#include <iostream>
#include <thread>
#include <string>
#include <mutex>


//验证 超时锁
std::timed_mutex tmux;
void ThreadMainTime(int i){
    for(;;){
        if(!tmux.try_lock_for(std::chrono::milliseconds(500))){
            std::cout<< i <<" [try_lock_for timeout] "<<std::endl;
            continue;
        }
        std::cout<< i <<" [in] "<<std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(2000));
        tmux.unlock();
        std::this_thread::sleep_for(std::chrono::milliseconds(2));
    }
}


// 验证递归锁
std::recursive_mutex rmux;
void Task1(){
    rmux.lock();
    std::cout<<" task1 [in] "<<std::endl;
    rmux.unlock();
}

void Task2(){
    rmux.lock();
    std::cout<<" task2 [in] "<<std::endl;
    rmux.unlock();
}

void ThreadMainRec(int i){
    for(;;){
        rmux.lock();
        Task1();
        std::cout<< i <<"[in]"<<std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(2000));

        Task2();
        rmux.unlock();
        std::this_thread::sleep_for(std::chrono::milliseconds(2));
    }
}


int main(int argc, char* argv[])
{
    for(int i=0; i<3; ++i){
        std::thread th(ThreadMainRec, i+100);
        th.detach();
    }
    getchar();
    std::cout<<"-------------------------"<<std::endl;

    for(int i=0; i<3; ++i){
        std::thread th(ThreadMainTime, i+200);
        th.detach();
    }
    getchar();
    std::cout<<"-------------------------"<<std::endl;

    getchar();
    return 0;
}
