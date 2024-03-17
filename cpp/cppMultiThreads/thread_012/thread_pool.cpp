#include <iostream>
#include "xthread_pool.h"

class MyTask : public XTask{
public:
    int Run() override{
        std::cout<<"============================================"<<std::endl;
        std::cout<<std::this_thread::get_id()<<" MyTask Run "<<name<<std::endl;
        std::cout<<"============================================"<<std::endl;
        return 0;
    }

    std::string name = "";
};


void Test1(){
    std::cout<<"===================test1=============="<<std::endl;
    XThreadPool pool;
    pool.Init(3);
    pool.Start();

    MyTask task1;
    task1.name = "henry1";

    pool.AddTask(&task1);
    getchar();
}


/// 这个测试用例翻车了，添加多个任务，输出的数据就乱了
void Test2(){
    std::cout<<"===================test2=============="<<std::endl;

    XThreadPool pool;
    pool.Init(3);
    pool.Start();

    // MyTask task2;
    // task2.name = "henry2";
    // pool.AddTask(&task2);

    // MyTask task3;
    // task3.name = "henry3";
    // pool.AddTask(&task3);

    // MyTask task4;
    // task4.name = "henry4";
    // pool.AddTask(&task4);

    // MyTask task5;
    // task5.name = "henry5";
    // pool.AddTask(&task5);


    // MyTask task6;
    // task6.name = "henry6";
    // pool.AddTask(&task6);


    for(int i=0; i<20; i++){
        MyTask* task = new MyTask();
        std::string name = "henry";
        task->name = name + std::to_string(i);
        pool.AddTask(task);
    }
    getchar();
}


int main(){
    Test1();
    Test2();
    return 0;
}