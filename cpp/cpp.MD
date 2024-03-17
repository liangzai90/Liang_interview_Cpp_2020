# cpp参考手册：

https://en.cppreference.com/w/cpp
https://zh.cppreference.com/w/cpp


## C++ 性能分析工具

### gprof 
```shell
##编译代码
g++ -pg -o myprogram hello.cpp

## 执行代码
./myprogram

## 分析日志
gprof myprogram gmon.out > analysis.txt
```

### perf

```shell
## 编译代码
g++ -O2 -o myprogram  hello.cpp

## 执行程序
perf record ./myprogram

## 分析结果
perf report
```

### valgrind
```shell 
## 直接执行程序 进行检查（就是执行有点慢）
valgrind --tool=memcheck ./myprogram

## 检测内存泄漏
valgrind --leak-check=full  ./hello
```






