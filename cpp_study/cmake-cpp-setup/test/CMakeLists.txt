# 指定 cmake 最小版本, 意指 cmake 版本小于指定版本则构建过程终止
cmake_minimum_required(VERSION 3.26)

#[[
    语言环境配置
]]

# 语言版本
set(CMAKE_CXX_STANDARD 17)

# 如果指定的语言版本不受支持, 则构建过程终止
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 只弃用 ISO C++ 标准的编译器标志, 而不使用特定编译器的扩展
set(CMAKE_CXX_EXTENSIONS OFF)

if(UNIX)
    # 将 install_rpath 的设置应用在 build_rpath 上 避免在开发期间出现动态库找不到的问题
    set(CMAKE_BUILD_WITH_INSTALL_RPATH True)
endif()

#[[
    项目配置
]]

# 项目名称和语言
project(
    graver_test
    LANGUAGES CXX
    VERSION 1.0.0)

#[[
    编译相关配置
]]

# 生成 compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

aux_source_directory(. test_srcs)
add_executable(${PROJECT_NAME} ${test_srcs})

target_include_directories(
    ${PROJECT_NAME} PRIVATE ${PROJECT_SOURCE_DIR} ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/third/test
    ${PROJECT_SOURCE_DIR}/third/lib)

target_link_libraries(${PROJECT_NAME} ${lib_person_name})
set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY
    ${dist_dir}/test)

if(UNIX)
    # 设置 rpath
    set_target_properties(${PROJECT_NAME} PROPERTIES INSTALL_RPATH
        "\${ORIGIN}/../lib")
endif()

if(WIN32)
    add_custom_command(
        TARGET ${PROJECT_NAME}
        POST_BUILD

        # 复制 vcpkg 库
        COMMAND cp -rf ${bin_dir}/*.dll ${dist_dir}/test/)
endif()
