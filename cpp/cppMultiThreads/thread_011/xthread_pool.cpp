#include "xthread_pool.h"
#include <iostream>

void XThreadPool::Init(int num){
    std::unique_lock<std::mutex> lock(mux_);
    this->thread_num_ = num;
    std::cout<<"Thread pool Init "<<num<<std::endl;
}

//启动所有线程，必须先调用 Init
void XThreadPool::Start(){
    std::unique_lock<std::mutex> lock(mux_);
    if(thread_num_ <= 0){
        std::cerr<<"Please Init XThreadPool"<<std::endl;
        return;
    }
    if(!threads_.empty()){
        std::cerr<<"XThreadPool has started"<<std::endl;
        return;
    }
    //启动线程
    for(int i = 0; i < thread_num_; ++i){
        threads_.emplace_back(new std::thread(&XThreadPool::Run, this));
    }
}

void XThreadPool::Run(){
    std::cout<<"Begin XThreadPool Run "<<std::this_thread::get_id()<<std::endl;

    std::cout<<"End XThreadPool Run "<<std::this_thread::get_id()<<std::endl;
}
