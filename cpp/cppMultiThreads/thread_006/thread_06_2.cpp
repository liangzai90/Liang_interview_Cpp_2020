#include <iostream>
#include <thread>
#include <string>
#include <mutex>

// lock_guard 管理锁的生命周期
static std::mutex gmutex;
void TestLockGuard(int i){
    gmutex.lock();
    {
        //已经拥有锁，不 lock
        std::lock_guard<std::mutex> lock(gmutex, std::adopt_lock);
        //结束释放锁
    }

    {
        std::lock_guard<std::mutex> lock(gmutex);
        std::cout<<" begin thread "<< i <<std::endl;
    }

    for(;;){
        {
            std::lock_guard<std::mutex> lock(gmutex);
            std::cout<<" In  "<<i<<std::endl;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}

int main(int argc, char* argv[]) {

    for(int i = 0; i < 3; ++i){
        std::thread t1(TestLockGuard, i+100);
        t1.detach();
    }

    getchar();
    return 0;
}
