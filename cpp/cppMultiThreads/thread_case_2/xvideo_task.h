#pragma once

#include "xthread_pool.h"


//todo: 这是一种创建 task 的方式
// class XVideoTask : public XTask
// {
// public:
//     XVideoTask(std::function<void()> func) : func_(func) {}
//     int Run() override;
// private:
//     std::function<void()> func_;
// };

class XVideoTask : public XTask
{
public:
    int Run() override;
    std::string windows();
    std::string centos();
    
public:
    std::string in_path;
    std::string out_path;
    int width = 0;
    int height = 0;
};

