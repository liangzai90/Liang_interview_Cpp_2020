### C++11 线程创建的多种方式和参数传递

```
std::thread th;
th =  std::thread(ThreadMain, 10086, f1, "test para", p);
```
thread 创建对象的时候，使用的是值传递，传递的参数都做了一次 kind of copy.



参数传递的一些坑
 - 传递空间已销毁
 - 多线程共享访问一块空间
 - 传递的指针变量的生命周期小于线程的生命周期



#### 线程函数
传递指针和引用

```cpp

std::thread th(ThreadMainPtr, &p);//传递指针

std::thread th(ThreadMainRef, std::ref(p)); //传递引用 std::ref

```

```cpp
//第35行，引用传递的时候，参数必须带上 std::ref，告诉编译器这是一个引用的类型
35   std::thread th(ThreadMainRef, std::ref(p)); //传递引用必须使用 std::ref

```

没有传递引用的时候，有下面的报错信息
```shell
In file included from /home/henry/workspace/multi_thread/thread_003/thread_03_2.cpp:2:
/opt/rh/devtoolset-9/root/usr/include/c++/9/thread: In instantiation of ‘std::thread::thread(_Callable&&, _Args&& ...) [with _Callable = void (&)(Para&); _Args = {Para&}; <template-parameter-1-3> = void]’:
/home/henry/workspace/multi_thread/thread_003/thread_03_2.cpp:35:42:   required from here
/opt/rh/devtoolset-9/root/usr/include/c++/9/thread:120:44: error: static assertion failed: std::thread arguments must be invocable after conversion to rvalues
  120 |           typename decay<_Args>::type...>::value,
      |                                            ^~~~~
/opt/rh/devtoolset-9/root/usr/include/c++/9/thread: In instantiation of ‘struct std::thread::_Invoker<std::tuple<void (*)(Para&), Para> >’:
/opt/rh/devtoolset-9/root/usr/include/c++/9/thread:131:22:   required from ‘std::thread::thread(_Callable&&, _Args&& ...) [with _Callable = void (&)(Para&); _Args = {Para&}; <template-parameter-1-3> = void]’
/home/henry/workspace/multi_thread/thread_003/thread_03_2.cpp:35:42:   required from here
/opt/rh/devtoolset-9/root/usr/include/c++/9/thread:243:4: error: no type named ‘type’ in ‘struct std::thread::_Invoker<std::tuple<void (*)(Para&), Para> >::__result<std::tuple<void (*)(Para&), Para> >’
  243 |    _M_invoke(_Index_tuple<_Ind...>)
      |    ^~~~~~~~~
/opt/rh/devtoolset-9/root/usr/include/c++/9/thread:247:2: error: no type named ‘type’ in ‘struct std::thread::_Invoker<std::tuple<void (*)(Para&), Para> >::__result<std::tuple<void (*)(Para&), Para> >’
  247 |  operator()()
      |  ^~~~~~~~


```