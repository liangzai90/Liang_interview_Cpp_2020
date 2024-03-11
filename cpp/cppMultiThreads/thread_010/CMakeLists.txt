message("----->>>>>thread_010/CMakeLists.txt" )

# 收集当前目录下所有的 .cpp 文件
aux_source_directory(. DIR_SRCS)

# 添加可执行文件
add_executable(thread_10  ./thread_10.cpp)

# 链接需要的库
target_link_libraries(thread_10 ${LIB_LIB})


add_executable(thread_10_2 ./thread_10_2.cpp)
target_link_libraries(thread_10_2 ${LIB_LIB})

add_executable(thread_10_3 ./thread_10_3.cpp)
target_link_libraries(thread_10_3 ${LIB_LIB})

add_executable(thread_10_4 ./thread_10_4.cpp)
target_link_libraries(thread_10_4 ${LIB_LIB})

add_executable(thread_10_5 ./thread_10_5.cpp)
target_link_libraries(thread_10_5 ${LIB_LIB})



