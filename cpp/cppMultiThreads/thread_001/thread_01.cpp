#include <iostream>
#include <thread>

//using namespace std;

void ThreadMain() {
    std::cout<<"begin sub thread main"<<std::this_thread::get_id()<<std::endl;
    for(int i=0;i<10;i++) {
        std::cout<<" in thread "<<i <<std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1)); // 1000ms
    }
    std::cout<<"end sub thread main "<<std::this_thread::get_id()<<std::endl;
}


int main(int argc, char* argv[]) {
    std::cout<<"main thread ID "<<std::this_thread::get_id()<<std::endl;

    //线程创建启动
    std::thread th(ThreadMain);
    std::cout<<"begin wait sub thread "<<std::endl;

    //阻塞，等待子线程退出
    th.join();
    std::cout<<"end wait sub thread "<<std::endl;
    return 0;
}
