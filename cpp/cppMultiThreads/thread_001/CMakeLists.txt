message("----->>>>>thread_001/CMakeLists.txt" )
# thread_001/CMakeLists.txt

# 收集当前目录下所有的 .cpp 文件
#file(GLOB SOURCE_FILES "*.cpp")
aux_source_directory(. DIR_SRCS)

# 添加可执行文件，命名为 thread_01
add_executable(thread_01 ${DIR_SRCS})

# 链接需要的库
target_link_libraries(thread_01 ${LIB_LIB})
#target_link_libraries(indicli ${LIB_ALGO}  ${LIB_TAF} ${LIB_PTHREAD})
