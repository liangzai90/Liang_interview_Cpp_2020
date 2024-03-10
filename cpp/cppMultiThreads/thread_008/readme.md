## 条件变量 condition_variable

### 生产者-消费者模型
 * 生产者和消费者共享资源（list队列）
 * 生产者生产一个产品，通知消费者消费
 * 消费者阻塞等待信号--获取信号后消费产品（取出list队列中数据）

### 改变共享变量的线程步骤
 - 1.准备好信号量

```cpp
std::condition_variable cv;
```

 - 2.获得 std::mutex（常通过 std::unique_lock）
```cpp
std::unique_lock<std::mutex> lock(mux);
```

 - 3.在获取锁时进行修改
```cpp
msgs_.push_back(msg);
```

 - 4.释放锁并通知读取进程

```cpp
lock.unlock();
cv.notify_one();  // 通知一个等待信号线程
cv.notify_all();  // 通知所有等待信号线程
```
  
### 等待信号读取共享变量的线程步骤
 - 1.准备好信号量
```cpp
std::unique_lock<std::mutex> lock(mux);
```

 - 2.wait()等待信号通知

 - 2.1 无lambda表达式
```cpp
//解锁 lock, 并阻塞等待 notify_one   notify_all 通知
cv.wait(lock);

//接收到通知会再次获取锁标注，也就是说如果此时 mux 资源被占用，wait() 会阻塞等待，直到 mux 资源被释放
msgs_.front();

//处理数据
msgs_.pop_front();
```

 - 2.2lambda表达式  cv.wait(lock,[&]{return !msgs_.empty();});

只在std::unique_lock<std::mutex> 上工作的 std::condition_variable

```cpp
void wait(unique_lock<mutex>& _Lck) { // wait for signal
    // Nothing to do to comply with LWG‐2135 because std::mutex lock/unlock are nothrow
    _Check_C_return(_Cnd_wait(_Mycnd(), _Lck.mutex()‐>_Mymtx()));
}

template <class _Predicate>
void wait(unique_lock<mutex>& _Lck, _Predicate _Pred) { // wait for signal and test predicate
    while (!_Pred())
    { wait(_Lck);
    }
}
```


