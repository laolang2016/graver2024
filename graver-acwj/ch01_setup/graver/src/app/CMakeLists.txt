# 源文件列表
aux_source_directory(. SRCS_MAIN)

# 生成可执行程序
add_executable(${PROJECT_NAME} ${SRCS_MAIN})

# 链接动态库
target_link_libraries(${PROJECT_NAME} ${lib_config_name} ${lib_util_name}
                      fmt::fmt spdlog::spdlog)

# 可执行程序生成目录
set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY
                                                 ${bin_dir})

if(UNIX)
    # 设置 rpath
    set_target_properties(${PROJECT_NAME} PROPERTIES INSTALL_RPATH
                                                     "\${ORIGIN}/../lib")

    add_custom_command(
        TARGET ${PROJECT_NAME}
        POST_BUILD
        # 复制 vcpkg 库
        COMMAND cp -rf ${fmt_DIRECTORY}/lib* ${lib_dir}/)
endif()

if(WIN32)
    add_custom_command(
        TARGET ${PROJECT_NAME}
        POST_BUILD
        # 复制 vcpkg 库
        COMMAND ${CMAKE_COMMAND} -E copy
                ${fmt_DIRECTORY}/libfmt${CMAKE_DEBUG_POSTFIX}.dll ${bin_dir}/
        COMMAND
            ${CMAKE_COMMAND} -E copy
            ${spdlog_DIRECTORY}/libspdlog${CMAKE_DEBUG_POSTFIX}.dll ${bin_dir}/)
endif()
