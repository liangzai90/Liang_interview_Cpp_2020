### 第一个C++线程例子

第一个C++多线程的例子。
理解多线程如何创建，如何传递参数


```cpp
//C++11的线程函数
#include <thread>

//创建一个线程对象（创建的时候，线程就启动了）
//参数是 线程的 执行函数
std::thread th(ThreadMain);

//获取线程的id
std::this_thread::get_id()

//1秒的时间 
std::chrono::seconds(1)

//让程序等待1秒 sleep_for
 std::this_thread::sleep_for(std::chrono::seconds(1)); // 1000ms

//等待线程结束
th.join();
```

       
