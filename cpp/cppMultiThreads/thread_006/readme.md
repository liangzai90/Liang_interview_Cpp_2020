## 锁资源管理和条件变量


### 利用栈特性自动释放锁 RAII

什么是RAII，手动代码实现

    RAII(Resource Acquisition Is Initialization)C++之父提出；
    使用局部变量来管理资源的技术称为资源获取即初始化；
    它的生命周期是由操作系统来管理的，
    无需人工介入；
    资源的销毁容易忘记，造成死锁或内存泄漏

```cpp
class XMutex{
public:
    // 在构造函数初始化列表初始化 引用变量
    XMutex(std::mutex& mux):mux_(mux){
        std::cout<<" Lock "<<std::endl;
        mux_.lock();
    }

    ~XMutex(){
        std::cout<<" Unlock "<<std::endl;
        mux_.unlock();
    }

private:
    
    // 为了减少复制，这里是定义的引用；
    //因此必须在构造函数的初始化列表里面初始化这个变量
    std::mutex& mux_;
};
```


## C++11支持的RAII管理互斥资源  

### lock_guard C++11

 * C++11实现严格基于作用域的互斥体所有权包装提
 * adopt_lock C++11 类型为 adopt_lock_t，假设调用方拥有互斥体的所有权
 * 通过 {} 控制锁的临界区

```cpp
template <class _Mutex>
class lock_guard { // class with destructor that unlocks a mutex
public:
    using mutex_type = _Mutex;
        explicit lock_guard(_Mutex& _Mtx) : _MyMutex(_Mtx) { // construct and lock
        _MyMutex.lock();
    }
    lock_guard(_Mutex& _Mtx, adopt_lock_t) : _MyMutex(_Mtx) { // construct but don't lock
    }
    ~lock_guard() noexcept {
        _MyMutex.unlock();
    }
    lock_guard(const lock_guard&) = delete;
    lock_guard& operator=(const lock_guard&) = delete;
}；
```

```cpp
static std::mutex gmutex;

{
    std::lock_guard<std::mutex> lock(gmutex);
    std::cout<<" begin thread "<< i <<std::endl;
}
```
 * **注意，lock_guard 是不支持转移(move)的**

### unique_lock c++11
 * unique_lock C++11实现可移动的互斥体所有权包装提
 * 支持临时释放锁 unlock
 * 支持 adopt_lock （已经拥有锁，不加锁，出栈区 会释放）
 * 支持 defer_lock （延后拥有，不加锁，出栈区 不释放）
 * 支持 try_to_lock 尝试获得互斥体的所有权而不阻塞，获取失败退出栈区不会释放，通过 owns_lock()函数判断
 * 支持超时参数

```cpp
unique_lock& operator=(unique_lock&& _Other) {
    if (this != _STD addressof(_Other))
    { if (_Owns) {
        _Pmtx‐>unlock();
        }
        _Pmtx   = _Other._Pmtx;
        _Owns = _Other._Owns;
        _Other._Pmtx = nullptr;
        _Other._Owns = false;
    }
return *this;
}
```



### shared_lock  C++14

shared_lock C++14 实现可移动的共享互斥体所有权封装器
```cpp
explicit shared_lock(mutex_type& _Mtx)
    : _Pmtx(_STD addressof(_Mtx)), _Owns(true) { // construct with mutex and lock
    shared
    _Mtx.lock_shared();
}
```

### scoped_lock C++17

scoped_lock C++17 用于多个互斥体的免死锁 RAII 封装器 类似lock
```cpp
explicit scoped_lock(_Mutexes&... _Mtxes) : _MyMutexes(_Mtxes...) { //construct and lock
        _STD lock(_Mtxes...);
    }
lock(mux1, mux2);
mutex mux1, mux2;
std::scoped_lock lock(mux1, mux2);
```









