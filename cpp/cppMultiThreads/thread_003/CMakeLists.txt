message("----->>>>>thread_003/CMakeLists.txt" )

# 收集当前目录下所有的 .cpp 文件
aux_source_directory(. DIR_SRCS)

# 添加可执行文件
add_executable(thread_03 thread_03.cpp)
# 链接需要的库
target_link_libraries(thread_03 ${LIB_LIB})

# 添加可执行文件
add_executable(thread_03_2 thread_03_2.cpp)
# 链接需要的库
target_link_libraries(thread_03_2 ${LIB_LIB})

