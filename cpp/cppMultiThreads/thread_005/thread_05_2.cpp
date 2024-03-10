#include <iostream>
#include <thread>
#include <string>
#include <mutex>

static std::mutex mux;

// 互斥锁的一个坑， 在 unlock()之后，需要sleep一小会，让其他线程有机会获取锁资源
void ThreadMainMux(int i){
    for(;;){
        mux.lock();
        std::cout<<i<<" [in] "<<std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        mux.unlock();

        //此处如果不sleep一会，则最开始的那个线程会一直占有锁资源
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }
}
int main(int argc, char* argv[]) {
    for(int i=0;i<5; i++){
        std::thread th(ThreadMainMux, i+100);
        th.detach();
    }

    getchar();
    return 0;
}
