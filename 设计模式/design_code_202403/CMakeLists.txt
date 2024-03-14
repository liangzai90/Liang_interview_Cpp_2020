cmake_minimum_required(VERSION 3.2)
project(design_pattern)

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

## 单例模式 (Singleton Pattern)
add_subdirectory(singleton)
add_subdirectory(singleton_thread_safe)

## 抽象工厂模式（Abstract Factory Pattern）--- 创建新设计模式
add_subdirectory(abstract_factory)

## 适配器模式
add_subdirectory(adapter)

## 桥接模式
add_subdirectory(bridge)

## 建造者模式
add_subdirectory(builder)






