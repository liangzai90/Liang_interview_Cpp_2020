message("----->>>>>thread_004/CMakeLists.txt" )

# 收集当前目录下所有的 .cpp 文件
aux_source_directory(. DIR_SRCS)

# 添加可执行文件
add_executable(thread_04 thread_04.cpp)
# 链接需要的库
target_link_libraries(thread_04 ${LIB_LIB})


# 添加可执行文件
add_executable(thread_04_2 thread_04_2.cpp)
# 链接需要的库
target_link_libraries(thread_04_2 ${LIB_LIB})

# 添加可执行文件
add_executable(thread_04_3 thread_04_3.cpp)
# 链接需要的库
target_link_libraries(thread_04_3 ${LIB_LIB})

