### 使用成员函数作为线程入口并封装线程基类接口


创建一个基类，来管理线程的生命周期。
其他类，来继承这个基类，去具体实现线程的若干方法。


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


