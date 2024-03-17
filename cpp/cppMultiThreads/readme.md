## 介绍C++多线程相关的知识

使用CMake来管理工程。
每一个文件夹，就是一个工程


## C++多线程从原理到线程池实战


1.多线程概述

为什么要用多线程？
#### 任务分解
 - 耗时的操作，任务分解，实时响应
#### 数据分解
 - 充分利用多核 CPU 处理数据
#### 数据流分解
 - 读写分离，解耦合 设计

2.C++11多线程快速入门
* [2.1 先动手写第一个C++多线程程序](./thread_001/readme.md)

3.C++11多线程创建的几种方式






-------------------------------------
## step by step, a thread pool

 * **1.[完成线程池的初始化和启动](./thread_011/readme.md)**

 * **2.[完成线程池调度任务](./thread_012/readme.md)**

 * **3.[完成线程池退出 并等待任务处理结束](./thread_013/readme.md)**


**使用valgrind 检查内存 --tool=memcheck**

将日志输出到 t13_memcheck.log

2>&1 是一个特殊的重定向，
它会把标准错误（stderr，通常是错误消息）重定向到标准输出的当前位置，
即 t13_memcheck.log 文件。

```shell
valgrind  --tool=memcheck  ./bin/thread_13  > t13_memcheck.log  2>&1
```


**使用 valgrind 检查内存泄漏 --leak-check=full**

将日志输出到 t13_leck_check.log

2>&1 是一个特殊的重定向，
它会把标准错误（stderr，通常是错误消息）重定向到标准输出的当前位置，
即 t13_leck_check.log 文件。

```shell
valgrind  --leak-check=full  ./bin/thread_13  > t13_leck_check.log  2>&1
```


 * **4.[线程池中正在运行的任务数量获取，使用 atomic 原子变量](./thread_014/readme.md)**
  
 * **5.[使用智能指针管理线程对象和任务对象的生命周期](./thread_015/readme.md)**
  使用智能指针之后，没有内存泄漏的问题了。**智能指针 真香**

 * **6.[异步获取线程池中任务执行结果](./thread_016/readme.md)**


-------------------------------------
## use thread pool

 * **[基于线程池实现音视频批量转码测试任务](./thread_017/readme.md)**

 * **[完成线程池案例-基于ffpeg工具多线程转码视频](./thread_018/readme.md)**

-------------------------------------

## more than C++20

 * **[C++20屏障barrier实现线程协调](./thread_019/readme.md)**

 * **[call_once多线程调用函数只进入一次](./thread_020/readme.md)**

