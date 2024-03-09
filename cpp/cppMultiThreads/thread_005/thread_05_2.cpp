#include <iostream>
#include <thread>
#include <string>
#include <mutex>

static std::mutex mux;

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
