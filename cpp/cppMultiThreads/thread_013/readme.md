### 完成线程池退出，并等待任务处理结束


主要学习这里的设计思路。这里程序还是有缺陷的。


## 使用valgrind 检查内存 --tool=memcheck

将日志输出到 t13_memcheck.log

2>&1 是一个特殊的重定向，
它会把标准错误（stderr，通常是错误消息）重定向到标准输出的当前位置，
即 t13_memcheck.log 文件。

```shell
valgrind  --tool=memcheck  ./bin/thread_13  > t13_memcheck.log  2>&1
```


### 使用 valgrind 检查内存泄漏 --leak-check=full

将日志输出到 t13_leck_check.log

2>&1 是一个特殊的重定向，
它会把标准错误（stderr，通常是错误消息）重定向到标准输出的当前位置，
即 t13_leck_check.log 文件。

```shell
valgrind  --leak-check=full  ./bin/thread_13  > t13_leck_check.log  2>&1
```