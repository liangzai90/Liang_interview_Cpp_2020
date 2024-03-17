### 使用智能指针管理线程对象和任务对象的生命周期

### 智能指针（真香）

用 **智能指针** 来管理我们的指针对象之后，就没有检测到内存泄漏的问题了。

### XTask 指针变量的生命周期

默认构造，拷贝构造，拷贝赋值，析构函数，移动构造， 通过打印这些日志，跟踪指针的生命周期


valgrind 检测内存泄漏：
```shell
valgrind  --tool=memcheck ./bin/thread_15 
```


程序输出的日志信息：
```bash
[henry@192 multi_thread]$ valgrind  --tool=memcheck ./bin/thread_15 
==3675== Memcheck, a memory error detector
==3675== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==3675== Using Valgrind-3.15.0 and LibVEX; rerun with -h for copyright info
==3675== Command: ./bin/thread_15
==3675== 
===================test1==============
---Thread pool Init 3
Begin XThreadPool Run 109258496
Begin XThreadPool Run 117651200
============================================
117651200 MyTask Run henry1
============================================
.============================================
109258496 MyTask Run henry2
============================================
.Begin XThreadPool Run 126043904
Test1 task run count:2
....End XThreadPool Run 126043904
End XThreadPool Run 117651200
End XThreadPool Run 109258496
Test1 task run count:0

===================test2==============
---Thread pool Init 3
Begin XThreadPool Run 126043904
Begin XThreadPool Run 117651200
Begin XThreadPool Run 109258496
============================================
109258496 MyTask Run henry2
============================================
.Test2 task run count:3
============================================
117651200 MyTask Run henry1
============================================
.============================================
126043904 MyTask Run henry0
============================================
................End XThreadPool Run 126043904
End XThreadPool Run 109258496
End XThreadPool Run 117651200
Test2 task run count:0

==3675== 
==3675== HEAP SUMMARY:
==3675==     in use at exit: 0 bytes in 0 blocks
==3675==   total heap usage: 127 allocs, 127 frees, 6,222 bytes allocated
==3675== 
==3675== All heap blocks were freed -- no leaks are possible
==3675== 
==3675== For lists of detected and suppressed errors, rerun with: -s
==3675== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```