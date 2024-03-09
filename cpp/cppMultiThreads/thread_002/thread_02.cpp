#include <iostream>
#include <thread>

//using namespace std;
bool is_exit = false;

void ThreadMain() {
    std::cout<<"begin sub thread main"<<std::this_thread::get_id()<<std::endl;
    for(int i=0;i<10;i++) {
        if(is_exit) break;
        std::cout<<" in thread "<<i <<std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1)); // 1000ms
    }
    std::cout<<"end sub thread main "<<std::this_thread::get_id()<<std::endl;
}


int main(int argc, char* argv[]) {
    std::cout<<"main thread ID "<<std::this_thread::get_id()<<std::endl;

    {
        //std::thread th(ThreadMain);
        //th.detach(); //子线程与主线程分离， 守护线程
        //坑：主线程退出后，子线程不一定退出
    }

    {
        //线程创建启动
        std::thread th(ThreadMain);
        std::this_thread::sleep_for(std::chrono::seconds(3)); //1000ms
        is_exit = true; //通知子线程退出
        std::cout<<"主线程阻塞， 等待子线程退出 "<<std::endl;
        th.join();     //阻塞，等待子线程退出
        std::cout<<"子线程已经退出！"<<std::endl;
    }

    getchar();
    return 0;
}
