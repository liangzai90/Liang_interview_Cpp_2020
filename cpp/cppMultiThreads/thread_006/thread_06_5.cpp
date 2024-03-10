#include <iostream>
#include <thread>
#include <mutex>
#include <shared_mutex>


//C++17 scoped_lock 

static std::mutex mux1;
static std::mutex mux2;

void testScope1(){
    //模拟死锁，停100ms 等另一个线程锁 mux2
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    std::cout<<std::this_thread::get_id()<<" begin mux1 lock "<<std::endl;

    //mux1.lock();
    std::cout<<std::this_thread::get_id()<<" begin mux2 lock"<<std::endl;
    // mux2.lock();   //死锁

    //C++11
    std::lock(mux1, mux2);

    //C++17
    std::scoped_lock lock(mux1, mux2);

    std::cout<<"TestScope1"<<std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    //mux1.unlock();
    //mux2.unlock();
}


void testScope2(){
    std::cout<<std::this_thread::get_id()<<" begin mux2 lock "<<std::endl;
    mux2.lock();
    std::this_thread::sleep_for(std::chrono::milliseconds(500));

    std::cout<<std::this_thread::get_id()<<" begin mux1 lock"<<std::endl;
    mux1.lock();   //死锁

    std::cout<<"TestScope2"<<std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(1500));

    mux1.unlock();
    mux2.unlock();
}


int main(int argc, char* argv[]){

    //演示死锁情况
    {
        std::thread th(testScope1);
        th.detach();
    }
    {
        std::thread th(testScope2);
        th.detach();
    }

    getchar();
    return 0;
}

