# 指定 cmake 最小版本, 意指 cmake 版本小于指定版本则构建过程终止
cmake_minimum_required(VERSION 3.26)

# 语言版本
set(CMAKE_C_STANDARD 17)

# 如果指定的语言版本不受支持, 则构建过程终止
set(CMAKE_C_STANDARD_REQUIRED True)

# 只弃用 ISO C++ 标准的编译器标志, 而不使用特定编译器的扩展
set(CMAKE_C_EXTENSIONS OFF)

project(lua LANGUAGES C)

# 包含全局头文件
include_directories(${PROJECT_SOURCE_DIR}/include)

set(src_list
src/lapi.c
src/lauxlib.c
src/lbaselib.c
src/lcode.c
src/lcorolib.c
src/lctype.c
src/ldblib.c
src/ldebug.c
src/ldo.c
src/ldump.c
src/lfunc.c
src/lgc.c
src/linit.c
src/liolib.c
src/llex.c
src/lmathlib.c
src/lmem.c
src/loadlib.c
src/lobject.c
src/lopcodes.c
src/loslib.c
src/lparser.c
src/lstate.c
src/lstring.c
src/lstrlib.c
src/ltable.c
src/ltablib.c
src/ltm.c
src/lundump.c
src/lutf8lib.c
src/lvm.c
src/lzio.c
)

# 生成动态库
add_library(${PROJECT_NAME} SHARED ${src_list})
# 设置动态库版本
SET_TARGET_PROPERTIES(${PROJECT_NAME} PROPERTIES VERSION 5.4.2 SOVERSION 5)
# 生成静态库
add_library(${PROJECT_NAME}_static STATIC ${src_list})

set_target_properties(${PROJECT_NAME}_static PROPERTIES OUTPUT_NAME ${PROJECT_NAME})
# 使动态库和静态库同时存在
set_target_properties(${PROJECT_NAME} PROPERTIES CLEAN_DIRECT_OUTPUT 1)


