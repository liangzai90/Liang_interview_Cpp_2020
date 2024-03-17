#include "xthread_pool.h"
#include <iostream>

void XThreadPool::Init(int num){
    std::unique_lock<std::mutex> lock(mux_);
    this->thread_num_ = num;
    std::cout<<"---Thread pool Init "<<num<<std::endl;
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

    while(true){
        
        auto task = GetTask();
        if(!task) continue;
        try{
            task->Run();
            //todo  这里执行之后，是不是要delete task ??
            //delete task;
        }
        catch(...){
            //task->handleException() 
        }
    }

    std::cout<<"End XThreadPool Run "<<std::this_thread::get_id()<<std::endl;
}

void XThreadPool::AddTask(XTask* task){
    std::unique_lock<std::mutex> lock(mux_);
    tasks_.push_back(task);

    lock.unlock();
    cv_.notify_one();
}

XTask* XThreadPool::GetTask(){
    std::unique_lock<std::mutex> lock(mux_);
    if(tasks_.empty())
    {
        cv_.wait(lock);
    }
    if(tasks_.empty()){
        return nullptr;
    }
    auto task = tasks_.front();
    tasks_.pop_front();
    return task;
}