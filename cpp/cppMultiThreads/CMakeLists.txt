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



###================================+++++++++++++++++
# 完成线程池的初始化和启动
add_subdirectory(thread_011)

# 完成线程池调度任务
add_subdirectory(thread_012)

# 完成线程池退出 并等待任务处理结束
add_subdirectory(thread_013)

# 线程池中正在运行的任务数量获取，使用 atomic 原子变量
add_subdirectory(thread_014)


## 使用智能指针管理线程对象和任务对象的生命周期
add_subdirectory(thread_015)

## 异步获取线程池中任务执行结果
add_subdirectory(thread_016)

##================================

## 基于线程池实现音视频批量转码测试任务
add_subdirectory(thread_case_1)

## 完成线程池案例-基于ffpeg工具多线程转码视频
add_subdirectory(thread_case_2)



