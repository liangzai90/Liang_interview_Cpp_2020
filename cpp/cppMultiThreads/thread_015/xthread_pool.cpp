#include "xthread_pool.h"
#include <iostream>


//默认构造
XTask::XTask(){
    std::cout<<">>> default XTask"<<std::endl;
}

//拷贝构造
XTask::XTask(const XTask&){
    std::cout<<">>> copy XTask"<<std::endl;
}

//拷贝赋值
XTask& XTask::operator=(const XTask& tsk){
    std::cout<<">>> operator= XTask"<<std::endl;
    return *this;
}

//析构函数
XTask::~XTask(){
    std::cout<<">>> destruct XTask"<<std::endl;
}

//移动构造
XTask::XTask(XTask&& tsk){
    std::cout<<">>> move XTask"<<std::endl;
}


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
        //threads_.emplace_back(new std::thread(&XThreadPool::Run, this));

        // 智能指针版本，创建线程列表
        auto th = std::make_shared<std::thread>(&XThreadPool::Run, this);
        threads_.push_back(th);
    }
}

//线程池退出
void XThreadPool::Stop(){
    is_exit_ = true;
    cv_.notify_all();
    for(auto& th : threads_){
        th->join();
    }
    std::unique_lock<std::mutex> lock(mux_);
    threads_.clear();  //todo 这是正确释放了指针吗？
}

void XThreadPool::Run(){
    std::cout<<"Begin XThreadPool Run "<<std::this_thread::get_id()<<std::endl;

    while(!is_exit()){
        
        auto task = GetTask();
        if(!task) continue;
        ++task_run_count_;
        try{
            task->Run();
        }
        catch(...){
            //task->handleException() 
        }
        --task_run_count_;
    }

    std::cout<<"End XThreadPool Run "<<std::this_thread::get_id()<<std::endl;
}

void XThreadPool::AddTask(std::shared_ptr<XTask> task){
    std::unique_lock<std::mutex> lock(mux_);
    tasks_.push_back(task);
    task->is_exit = [this] {return is_exit();};
      
    lock.unlock();
    cv_.notify_one();
}

std::shared_ptr<XTask> XThreadPool::GetTask(){
    std::unique_lock<std::mutex> lock(mux_);
    if(tasks_.empty())
    {
        cv_.wait(lock);
    }
    if(is_exit()){
        return nullptr;
    }
    if(tasks_.empty()){
        return nullptr;
    }
    auto task = tasks_.front();
    tasks_.pop_front();
    return task;
}