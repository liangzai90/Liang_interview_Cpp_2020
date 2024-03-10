#include <iostream>
#include <thread>
#include <mutex>
#include <shared_mutex>


//C++14 的 读写锁

int main(int argc, char* argv[]){

    {
        //共享锁
        static std::shared_timed_mutex  tmux;
        
        //读取锁  共享锁
        {
            //调用共享锁
            std::shared_lock<std::shared_timed_mutex> lock(tmux);
            std::cout<<" read data "<<std::endl;
            //退出栈区， 释放共享锁
        }

        // 写入锁，互斥锁
        {
            std::unique_lock<std::shared_timed_mutex> lock(tmux);
            std::cout<<"write data"<<std::endl;
        }
    }


    getchar();
    return 0;
}

