#include <iostream>
#include <thread>
#include <string>
#include <mutex>  // std::call_once

void SystemInit(){
    std::cout <<"Call SystemInit "<<std::endl;
}

// call_once，多线程调用函数只进入一次
void SystemInitOne(){
    static std::once_flag flag;
    std::call_once(flag, SystemInit);
}

int main(int argc, char* argv[]){
    SystemInitOne();
    SystemInitOne();

    for(int i=0;i<3; ++i){
        std::thread th(SystemInitOne);
        th.detach();
    }

    getchar();
    return 0;
}