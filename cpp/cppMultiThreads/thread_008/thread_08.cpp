#include <iostream>
#include <thread>
#include <mutex>
#include <list>
#include <string>
#include <sstream>
#include <condition_variable>

std::list<std::string> msgs_;
std::mutex mux;
std::condition_variable  cv;

void ThreadWrite(){
    for(int i=0; ; ++i){
        std::stringstream ss;
        ss <<"Write msg "<< i ;
        std::unique_lock<std::mutex> lock(mux);
        msgs_.push_back(ss.str());

        // 先解锁，再通知
        lock.unlock();
        cv.notify_one(); // 发送信号
        //cv.notify_all();

        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

void ThreadRead(int i) {
    for(; ; ){
        std::cout<<"read msg "<<std::endl;
        std::unique_lock<std::mutex> lock(mux);
        //cv.wait(lock); //解锁， 阻塞等待信号

        // 等待条件满足,只要不是true，就会一直循环等待，一直循环调用wait.
        // 如果返回true，这里wait不会阻塞，会直接进入下一行代码
        cv.wait(lock, [i] {
            std::cout<< i <<" wait "<<std::endl;
            return !msgs_.empty();
        });

        //获取信号后锁定
        while(!msgs_.empty()){
            std::cout<<"["<<i<<"]" <<" read: "<< msgs_.front() <<std::endl;
            msgs_.pop_front();
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}

int main(int argc, char* argv[]) {
    {
        std::thread  th(ThreadWrite);
        th.detach();
    }

    for(int i=0;i<3; ++i){
        std::thread th(ThreadRead, i+1);
        th.detach();
    }
  
    getchar();
    return 0;
}
