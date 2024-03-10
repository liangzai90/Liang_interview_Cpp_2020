#include <iostream>
#include <thread>
#include <string>
#include <mutex>

static std::mutex mux;

//try_lock()的一个坑.try_lock() 是有资源开销的,因此try_lock失败之后，sleep一段时间很有必要。
void TestThread(){
    for(;;){

        //获取锁资源，如果没有则阻塞等待
        //mux.lock();

        //返回true表示获取到了锁
        if(!mux.try_lock()){
            std::cout<<"."<<std::flush;
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
            continue;
        }
        std::cout<<"======================================="<<std::endl;
        std::cout<<"test 001"<<std::endl;
        std::cout<<"test 002"<<std::endl;
        std::cout<<"test 003"<<std::endl;
        std::cout<<"======================================="<<std::endl;
        mux.unlock();
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
}

int main(int argc, char* argv[]) {
    for(int i=0;i<3; i++){
        std::thread th(TestThread);
        th.detach();
    }

    getchar();
    return 0;
}
