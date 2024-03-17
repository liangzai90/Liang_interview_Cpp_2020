message("----->>>>>thread_014/CMakeLists.txt" )

# 收集当前目录下所有的 .cpp 文件
aux_source_directory(. DIR_SRCS)

# 添加可执行文件
add_executable(thread_14 ${DIR_SRCS})

# 链接需要的库
target_link_libraries(thread_14 ${LIB_LIB})
