#pragma once

#include <thread>
#include <vector>
#include <mutex>
#include <list>
#include <condition_variable>
#include <functional>
#include <atomic>   // atomic 原子变量 
#include <future>  // promise，future

//任务信息 结构体
typedef struct task_info{
    int id;
    std::string name;
    std::string msg;    
}task_info_tag;

class XTask{
public:
    virtual task_info_tag Run() = 0;   //任务函数，是异步的
    std::function<bool()> is_exit = nullptr;

    std::future<task_info_tag> GetReturn(){
        //阻塞等待 set_value
        return p_.get_future();
    }

    //设置返回值
    void SetValue(task_info_tag v){
        p_.set_value(v);
    }
private:
    //接收返回值
    std::promise<task_info_tag> p_;
};

class XThreadPool
{
public:
    //初始化线程池
    /// @para num 线程数量
    void Init(int num);

    //启动所有线程，必须先调用 Init
    void Start();

    //线程池退出
    void Stop();

    //添加任务
    void AddTask(std::shared_ptr<XTask> task);

    //获取任务
    std::shared_ptr<XTask> GetTask();

    //线程池是否退出
    bool is_exit() {return is_exit_;}

    int task_run_count(){return task_run_count_;}

private:
    //线程池线程的入口函数
    void Run();
    int thread_num_ = 0; //线程数量
    std::mutex mux_;
    // 线程列表，智能指针版本
    std::vector<std::shared_ptr<std::thread> > threads_;

    // 任务列表，智能指针版本
    std::list<std::shared_ptr<XTask> > tasks_;

    std::condition_variable cv_;
    bool is_exit_ = false; //线程池退出

    //正在运行的任务数量，线程安全
    std::atomic<int> task_run_count_ = {0}; //这是初始化列表的方法，将 atomicInt 初始化为 0
};


