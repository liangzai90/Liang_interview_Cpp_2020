#include <iostream>
#include "xthread_pool.h"

class MyTask : public XTask{
public:
    int Run() override{
        std::cout<<"============================================"<<std::endl;
        std::cout<<std::this_thread::get_id()<<" MyTask Run "<<name<<std::endl;
        std::cout<<"============================================"<<std::endl;

        for(int i=0; i<10; ++i){
            if(is_exit()) break;

            std::cout<<"."<<std::flush;
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
        }

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

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    pool.Stop();
}


/// 这个测试用例翻车了，添加多个任务，输出的数据就乱了
void Test2(){
    std::cout<<"===================test2=============="<<std::endl;

    XThreadPool pool;
    pool.Init(3);
    pool.Start();

    for(int i=0; i<20; i++){
        MyTask* task = new MyTask();
        std::string name = "henry";
        task->name = name + std::to_string(i);
        pool.AddTask(task);
    }

    std::this_thread::sleep_for(std::chrono::milliseconds(3000));
    pool.Stop();
}


int main(){
    Test1();
    Test2();
    return 0;
}