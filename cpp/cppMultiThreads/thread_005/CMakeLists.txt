message("----->>>>>thread_005/CMakeLists.txt" )

# 收集当前目录下所有的 .cpp 文件
aux_source_directory(. DIR_SRCS)

# 添加可执行文件
add_executable(thread_05  thread_05.cpp)
# 链接需要的库
target_link_libraries(thread_05 ${LIB_LIB})

# 添加可执行文件
add_executable(thread_05_2 thread_05_2.cpp)
# 链接需要的库
target_link_libraries(thread_05_2 ${LIB_LIB})


