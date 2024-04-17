cmake_minimum_required(VERSION 3.2)
project(socket-example1)

set(CMAKE_VERBOSE_MAKEFILE ON)
# 设置C++标准  
set(CMAKE_CXX_STANDARD 11)  
set(CMAKE_CXX_STANDARD_REQUIRED True)  
set(CMAKE_CXX_FLAGS "$ENV{CXXFLAGS} -rdynamic -O0 -ggdb -std=c++11 -Wall -Wno-deprecated -Werror -Wno-unused-function -Wno-builtin-macro-redefined -Wno-deprecated-declarations ")


include_directories(/usr/include)
include_directories(/usr/local/include)
include_directories(/usr/local/include/log4cplus)  # 包含log4cplus的头文件


link_directories(/usr/lib64)
link_directories(/usr/local/lib64)
link_directories(/usr/local/lib/) # 包含log4cplus的库


find_package(fmt CONFIG REQUIRED) # 查找fmt库


#输出目录重定向
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
SET(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

set(LIB_LIB
    pthread
    fmt::fmt
    log4cplus
    )


add_subdirectory(client)

add_subdirectory(server)


