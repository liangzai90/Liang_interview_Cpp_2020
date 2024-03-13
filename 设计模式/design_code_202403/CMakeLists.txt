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

## 单例模式
add_subdirectory(singleton)
add_subdirectory(singleton2)






