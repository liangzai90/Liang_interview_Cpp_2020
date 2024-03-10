#include <iostream>
#include <thread>
#include <string>
#include <mutex>

//RAII 创建一个 RAII 对象，来管理锁的生命周期

class XMutex{
public:
    // 在构造函数初始化列表初始化 引用变量
    XMutex(std::mutex& mux):mux_(mux){
        std::cout<<" Lock "<<std::endl;
        mux_.lock();
    }

    ~XMutex(){
        std::cout<<" Unlock "<<std::endl;
        mux_.unlock();
    }

private:
    
    // 为了减少复制，这里是定义的引用；
    //因此必须在构造函数的初始化列表里面初始化这个变量
    std::mutex& mux_;
};

static std::mutex mux;

void TestMutex(int status){
    XMutex lock(mux);
    if(status == 1) {
        std::cout<<" =1 "<<std::endl;
    } else if(status == 2){
        std::cout<<" =2 "<<std::endl;
    }
    return;
}
int main(int argc, char* argv[]) {
    TestMutex(1);
    TestMutex(2);

    getchar();
    return 0;
}
