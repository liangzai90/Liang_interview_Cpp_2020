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


### 超时锁 timed_mutex

超时锁应用 timed_mutex （避免长时间死锁）

 * 超时锁 timed_mutex
可记录锁的情况，多次超时，可以记录日志，获取错误情况。


验证 超时锁( try_lock_for(超时时间) )
```cpp
//验证 超时锁
std::timed_mutex tmux;
void ThreadMainTime(int i){
    for(;;){
        if(!tmux.try_lock_for(std::chrono::milliseconds(500))){
            std::cout<< i <<" [try_lock_for timeout] "<<std::endl;
            continue;
        }
        std::cout<< i <<" [in] "<<std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(2000));
        tmux.unlock();
        std::this_thread::sleep_for(std::chrono::milliseconds(2));
    }
}
```


### 可重入锁 recursive_mutex
 recursive_mutex 递归锁，可以被同一个线程多次调用，但是不能被其他线程调用。
 recursive_mutex, recursive_timed_mutex,用于业务组合.
 
 * 可重入锁 recursive_mutex


```cpp
// 验证递归锁
std::recursive_mutex rmux;
void Task1(){
    rmux.lock();
    std::cout<<" task1 [in] "<<std::endl;
    rmux.unlock();
}

void Task2(){
    rmux.lock();
    std::cout<<" task2 [in] "<<std::endl;
    rmux.unlock();
}

void ThreadMainRec(int i){
    for(;;){
        rmux.lock();
        Task1();
        std::cout<< i <<"[in]"<<std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(2000));

        Task2();
        rmux.unlock();
        std::this_thread::sleep_for(std::chrono::milliseconds(2));
    }
}
```



### 共享锁 shared_mutex 

 * C++14 共享超时锁 shared_timed_mutex
 * C++17 共享互斥锁 shared_mutex
 * 如果只有写时需要互斥，读取时不需要，用普通的锁如何做？
 * 按照下面的代码，读取只能有一个线程进入，在很多业务场景中，没有充分利用CPU资源

```cpp
// 读取 同时只能有一个线程
mux.lock();
cout<<share<<endl;
mux.unlock();

// 写入 
mux.lock();
share++;
mux.unlock();
```





















































