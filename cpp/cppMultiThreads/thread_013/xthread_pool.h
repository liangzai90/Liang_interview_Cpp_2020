#pragma once

#include <thread>
#include <vector>
#include <mutex>
#include <list>
#include <condition_variable>
#include <functional>

class XTask{
public:
    virtual int Run() = 0;
    std::function<bool()> is_exit = nullptr;
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
    void AddTask(XTask* task);

    //获取任务
    XTask* GetTask();

    //线程池是否退出
    bool is_exit() {return is_exit_;}

private:
    //线程池线程的入口函数
    void Run();
    int thread_num_ = 0; //线程数量
    std::mutex mux_;
    std::vector<std::thread*> threads_;
    std::list<XTask*> tasks_;
    std::condition_variable cv_;
    bool is_exit_ = false; //线程池退出
};


