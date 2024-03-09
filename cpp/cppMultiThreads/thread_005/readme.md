## 多线程通信和同步

### 多线程状态

多线程状态说明：

 * 初始化（Init）:该线程正在被创建
 * 就绪（Ready）：该线程在就绪列表中，等待CPU调度
 * 运行（Running）：该线程正在运行
 * 阻塞（Blocked）：该线程在等待某个事件发生，如I/O、锁等。该线程被阻塞挂起。Blocked状态包括：pend（锁、事件、信号量等阻塞）、suspend（主动pend）、delay（延时阻塞）、pendtime（因为锁、事件、信号量事件等超时等待）
 * 退出（Exit）：该线程正在退出，退出后线程资源将被回收

```txt
           初始化
             |
             |
             V
   阻塞 <--> 就绪 <-->运行  --> 退出 
    ^                 |
    |                 |
    |                 V
    <------------------
```


### 竞争状态（Race Condition）和临界区（Critical Section）
 - 竞争状态（Race Contition）
```
多线程同时读写数据
```

 - 临界区（Critical Section）
```
读写共享数据的代码片段
```

避免竞争状态策略，对临界区进行保护，同时只能有一个线程进入临界区。

### 互斥体和锁 mutex

互斥锁 mutex
```cpp
#include <mutex>

std::mutex mux;

mux.lock();      // 获取锁资源，如果没有则阻塞等待

// 注意，try_lock() 是有资源开销的，它会不断去试获取锁资源，直到获取成功，所以try_lock() 会比lock() 更高效。
// 因此try_lock失败之后，sleep一段时间很有必要。std::this_thread::sleep_for(std::chrono::milliseconds(100));
mux.try_lock();  // 如果有则获取锁资源


mux.unlock(); //unlock()之后，要留一段时间给操作系统重新分配锁资源
std::this_thread::sleep_for(std::chrono::milliseconds(1));

```

* mux.lock(); 

mux.lock() 获取锁资源，如果没有则阻塞等待


* mux.try_lock();  

mux.try_lock()如果有则获取锁资源
注意，try_lock() 是有资源开销的，
它会不断去试获取锁资源，
直到获取成功，
所以try_lock() 会比lock() 更高效。

因此try_lock失败之后，sleep一段时间很有必要。
std::this_thread::sleep_for(std::chrono::milliseconds(100));

 
### 互斥锁的坑

线程抢占不到资源

unlock()之后，要留一段时间给操作系统

```cpp
void ThreadMainMux(int i){
    for(;;){
        mux.lock();
        std::cout<<i<<" [in] "<<std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        mux.unlock();

        //此处如果不sleep一会，则最开始的那个线程会一直占有锁资源
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }
}
```


