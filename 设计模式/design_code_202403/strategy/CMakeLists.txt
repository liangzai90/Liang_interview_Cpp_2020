message("----->>>>>strategy/CMakeLists.txt" )
# strategy/CMakeLists.txt

# 收集当前目录下所有的 .cpp 文件
#file(GLOB SOURCE_FILES "*.cpp")
aux_source_directory(. DIR_SRCS)

# 添加可执行文件，命名为 strategy
add_executable(strategy ${DIR_SRCS})

# 链接需要的库
target_link_libraries(strategy ${LIB_LIB})
