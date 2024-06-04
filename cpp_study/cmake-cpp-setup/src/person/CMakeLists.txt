aux_source_directory(. SRCS_LIB_PERSON)
add_library(${lib_person_name} SHARED ${SRCS_LIB_PERSON})

if(UNIX)
    # 设置动态库生成目录
    set_target_properties(${lib_person_name} PROPERTIES LIBRARY_OUTPUT_DIRECTORY
        ${lib_dir})
endif()

if(UNIX)
    # 设置 rpath
    set_target_properties(${lib_person_name} PROPERTIES INSTALL_RPATH
        "\${ORIGIN}/")
endif()

if(WIN32)
    add_custom_command(
        TARGET ${lib_person_name}
        POST_BUILD

        # 复制动态库到可执行文件所在目录
        COMMAND ${CMAKE_COMMAND} -E copy
        ${CMAKE_CURRENT_BINARY_DIR}/${lib_person_file_name} ${bin_dir}/)
endif()
