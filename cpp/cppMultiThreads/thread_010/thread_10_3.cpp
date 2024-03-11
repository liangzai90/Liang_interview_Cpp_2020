#include <thread>
#include <iostream>
#include <future>
#include <string>

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
    
    std::cout<<" begin future get "<<std::endl;
    std::cout<<" future.get() = "<<future.get() <<std::endl;
    std::cout<<" end future get "<<std::endl;

    //创建异步线程
    std::cout<<" ======= 创建异步线程 ======" <<std::endl;
    auto future2 = std::async(TestAsync, 10086);
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    std::cout<<" begin future2 get "<<std::endl;
    std::cout<<" future2.get() = "<<future2.get() <<std::endl;
    std::cout<<" end future2 get "<<std::endl;

    getchar();
    return 0;
}
