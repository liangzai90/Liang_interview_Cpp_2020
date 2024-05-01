cmake_minimum_required(VERSION 2.8)

project(s1client)

if(WIN32)
    include (c:\\tars\\cpp\\makefile\\tars-tools.cmake)
else()
    include (/usr/local/tars/cpp/makefile/tars-tools.cmake)
endif()


include_directories(/usr/local/tars/cpp/thirdparty/include)
link_directories(/usr/local/tars/cpp/thirdparty/lib)

# 我们刚才编写的 henryS1Server服务 的头文件（通过 make release 自动生成）
include_directories(/home/tarsproto/Test/HenryS1Server/)

add_subdirectory(src)
