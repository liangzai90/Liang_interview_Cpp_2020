cmake_minimum_required(VERSION 3.2)
project(multi_threads)

set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_CXX_FLAGS "$ENV{CXXFLAGS} -rdynamic -O0 -ggdb -std=c++11 -Wall -Wno-deprecated -Werror -Wno-unused-function -Wno-builtin-macro-redefined -Wno-deprecated-declarations ")
## -Wno-unused-variable

include_directories(.)
include_directories(/usr/local/include)
link_directories(/usr/local/lib64)

#输出目录重定向
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
SET(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

set(LIB_LIB
    pthread
    )

## 初步认识线程
add_subdirectory(thread_001)
add_subdirectory(thread_002)
add_subdirectory(thread_003)
add_subdirectory(thread_004)
add_subdirectory(thread_005)
add_subdirectory(thread_006)
add_subdirectory(thread_007)
add_subdirectory(thread_008)

# 一个多线程通信的示例。条件变量 应用线程通信，解决线程退出的阻塞问题.
add_subdirectory(thread_009)

# 多线程异步通信 和 并发计算
add_subdirectory(thread_010)

