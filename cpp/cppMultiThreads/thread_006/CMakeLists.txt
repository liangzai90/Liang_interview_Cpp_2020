message("----->>>>>thread_006/CMakeLists.txt" )

# 收集当前目录下所有的 .cpp 文件
aux_source_directory(. DIR_SRCS)

# 添加可执行文件
add_executable(thread_06 ./thread_06.cpp)

# 链接需要的库
target_link_libraries(thread_06 ${LIB_LIB})


# 添加可执行文件
add_executable(thread_06_2 ./thread_06_2.cpp)
target_link_libraries(thread_06_2 ${LIB_LIB})

# 添加可执行文件
add_executable(thread_06_3 ./thread_06_3.cpp)
target_link_libraries(thread_06_3 ${LIB_LIB})
