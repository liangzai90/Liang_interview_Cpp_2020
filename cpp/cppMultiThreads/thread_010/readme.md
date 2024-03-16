## 多线程异步通信 和 并发计算

### 线程异步和通信

#### promise 和 future 

 * promise 用于异步传输变量
    std::promise 提供存储异步通信的值，再通过其对象创建的 std::future 异步获得结果。
    std::promise 只能使用一次。 void set_value(_Ty&& _Val)设置传递值，只能调用一次。
 * get() 阻塞等待 promise set_value 的值




```cpp
void TestFuture(std::promise<std::string> p){
    p.set_value("6666666");
}

int main(int argc, char* argv[]) {
    //异步传输变量，存储数据
    std::promise<std::string> p;
    //用来获取线程异步的值
    auto future = p.get_future();
    auto th = std::thread(TestFuture, std::move(p));
    std::cout<<"future get() = "<<future.get()<<std::endl<<std::flush;

    th.join();
    getchar();
    return 0;
}

```

### packaged_task 异步调用函数打包
 * packaged_task 用来包装一个函数，将函数的返回值和参数打包成一个异步任务，可以使用 std::future 获取异步任务的结果。
 * 与bind的区别，可异步调用，函数访问和获取返回值分开调用

```cpp
std::string TestPack(int index){
    std::cout<<"begin Test Pack "<<index<<std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(3000));
    return "Test Pack return";
}

std::packaged_task< std::string(int) > task(TestPack);  //打包一个函数
auto result = task.get_future();
std::thread th(std::move(task), 200);  //创建线程的时候， TestPack 函数被调用了，但是 TestPack 阻塞了，没有立即返回

std::cout<<"result get:"<<result.get()<<std::endl; //直到调用了result.get()，才会解除阻塞，返回函数执行结果
```


### async 创建异步线程

C++11 异步运行一个函数，并返回保有其结果的 std::future 对象。

 * launch::deferred 延迟执行，在调用 wait 和 get 时，调用函数代码
 * launch::async 创建线程（默认）
 * 返回的线程函数的返回值类型为 std::future<T>，T 为函数的返回值类型
 * re.get()获取结果，会阻塞等待

launch::deferred 没有创建线程

launch::async 创建了线程

### 异步操作结果 获取 future 

代码示例：

```cpp
std::string TestAsync(int index){
    std::cout<< index <<" begin in TestAsync"<<std::this_thread::get_id()<<std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(2));
    return "TestAsync string return..";
}

int main(int argc, char* argv[]){
    std::cout<<"main thread id is "<<std::this_thread::get_id()<<std::endl;

    //不创建线程 启动异步任务
    auto future = std::async(std::launch::deferred,TestAsync,123);
    std::this_thread::sleep_for(std::chrono::milliseconds(100));   
    std::cout<<" future.get() = "<<future.get() <<std::endl;

    //创建异步线程
    std::cout<<" ======= 创建异步线程 ======" <<std::endl;
    auto future2 = std::async(TestAsync, 10086);
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    std::cout<<" future2.get() = "<<future2.get() <<std::endl;
}
```


## C++17 多核并行计算
### 手动实现 base16 编码
    二进制转换为字符串
    一个字节8位，拆分为两个四位字节（最大值16）
    拆分后的字节映射到 0123456789abcdef 

获取时间间隔

```cpp
auto start2 = std::chrono::system_clock::now();
auto end2 = std::chrono::system_clock::now();
auto iMilliseconds2 = std::chrono::duration_cast<std::chrono::milliseconds>(end2-start2).count();

std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
std::chrono::steady_clock::time_point end   = std::chrono::steady_clock::now();
auto iMilliseconds =  std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count();

```

### c++11实现 base16 多线程编码


### C++17 for_each 实现多核并行计算 base16 编码



