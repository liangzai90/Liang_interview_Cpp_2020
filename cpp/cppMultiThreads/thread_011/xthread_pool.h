#pragma once

#include <thread>
#include <vector>
#include <mutex>

class XThreadPool
{
public:
    //初始化线程池
    /// @para num 线程数量
    void Init(int num);

    //启动所有线程，必须先调用 Init
    void Start();

private:
    //线程池线程的入口函数
    void Run();
    int thread_num_ = 0; //线程数量
    std::mutex mux_;
    std::vector<std::thread*> threads_;
};


