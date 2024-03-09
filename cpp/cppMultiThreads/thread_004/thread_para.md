### 使用成员函数作为线程入口并封装线程基类接口


以成员函数作为线程的入口函数
```cpp
// 成员函数作为线程入口
MyThread myth;
myth.name = "test name henry";
myth.age = 123;
// &MyThread::Main 是 成员函数的指针
// &myth 当前对象的地址
std::thread th(&MyThread::Main, &myth);
```


创建一个基类，来管理线程的生命周期。
其他类，来继承这个基类，去具体实现线程的若干方法。
```cpp
virtual void Start(){
    is_exit_ = false;
    // 以成员函数作为线程入口函数
    th_ = std::thread(&XThread::Main, this);
}
virtual void Stop(){
    is_exit_ = true;
    Wait();
}
virtual void Wait(){
    if(th_.joinable()){
        th_.join();
    }
}
```



### lambda临时函数作为线程入口

lambda 临时函数作为线程入口函数
```cpp
lambda 函数，其基本格式如下
[捕捉列表] (参数) multable -> 返回类型 {函数体}
```
```cpp
//普通全局的 lambda 表达式
std::thread th(
    [](int i) {std::cout<<"---> "<<i<<std::endl;},
    10086);

//类成员的 lambda 表达式
std::thread th([this](){
    std::cout<<"TestLambda Start, name:"<<name<<std::endl;
});    
```
更多 lambda 例子：
[https://www.cnblogs.com/music-liang/p/14131125.html](https://www.cnblogs.com/music-liang/p/14131125.html)

[https://www.cnblogs.com/music-liang/p/12908464.html](https://www.cnblogs.com/music-liang/p/12908464.html)

[https://www.jianshu.com/p/d686ad9de817](https://www.jianshu.com/p/d686ad9de817)


### call once 多线程调用函数只进入一次


```cpp
#include <mutex>  // std::call_once

void SystemInit(){
    std::cout <<"Call SystemInit "<<std::endl;
}

void SystemInitOne(){
    static std::once_flag flag; //定义flag 
    std::call_once(flag, SystemInit); // call_once    
}
```



