#include <iostream>
#include <thread>
#include <future>
#include <string>

void TestFuture(std::promise<std::string> p){
    std::cout<<" begin TestFuture "<<std::endl<<std::flush;
    std::this_thread::sleep_for(std::chrono::milliseconds(3000));
    std::cout<<" begin set value "<<std::endl<<std::flush;

    p.set_value("6666666");//调用set_value()方法后，就解除了阻塞状态

    std::this_thread::sleep_for(std::chrono::milliseconds(3000));
    std::cout<<"end TestFuture"<<std::endl<<std::flush;
}

int main(int argc, char* argv[]) {

    //异步传输变量存储
    std::promise<std::string> p;

    //用来获取线程异步的值
    auto future = p.get_future();

    auto th = std::thread(TestFuture, std::move(p));

    std::cout<<"begin future.get() "<<std::endl<<std::flush;
    std::cout<<"future get() = "<<future.get()<<std::endl<<std::flush;
    std::cout<<"end future.get()"<<std::endl<<std::flush;

    th.join();

    getchar();
    return 0;
}
