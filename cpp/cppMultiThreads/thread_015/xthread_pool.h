#pragma once

#include <thread>
#include <vector>
#include <mutex>
#include <list>
#include <condition_variable>
#include <functional>
#include <atomic>   // atomic 原子变量 

class XTask{
public:
    virtual int Run() = 0;
    std::function<bool()> is_exit = nullptr;

    //todo 默认构造，拷贝构造，拷贝赋值，析构函数，移动构造， 通过打印这些日志，跟踪指针的生命周期
    //默认构造
    XTask();
    //拷贝构造
    XTask(const XTask&);
    //拷贝赋值
    XTask& operator=(const XTask&);
    //析构函数
    virtual ~XTask();
    //移动构造
    XTask(XTask&&);
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
    //void AddTask(XTask* task);
    void AddTask(std::shared_ptr<XTask> task);

    //获取任务
    //XTask* GetTask();
    std::shared_ptr<XTask> GetTask();


    //线程池是否退出
    bool is_exit() {return is_exit_;}

    int task_run_count(){return task_run_count_;}

private:
    //线程池线程的入口函数
    void Run();
    int thread_num_ = 0; //线程数量
    std::mutex mux_;
    
    // std::vector<std::thread*> threads_;
    // 线程列表，智能指针版本
    std::vector<std::shared_ptr<std::thread> > threads_;

    // std::list<XTask*> tasks_;
    // 任务列表，智能指针版本
    std::list<std::shared_ptr<XTask> > tasks_;

    std::condition_variable cv_;
    bool is_exit_ = false; //线程池退出

    //正在运行的任务数量，线程安全
    std::atomic<int> task_run_count_ = {0}; //这是初始化列表的方法，将 atomicInt 初始化为 0
};


