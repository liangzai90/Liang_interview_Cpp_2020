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

    std::shared_ptr<MyTask> task1 = std::make_shared<MyTask>();
    task1->name = "henry1";
    pool.AddTask(task1);

    std::shared_ptr<MyTask> task2 = std::make_shared<MyTask>();
    task2->name = "henry2";
    pool.AddTask(task2);

    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    std::cout<<"Test1 task run count:"<<pool.task_run_count()<<std::endl;


    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    pool.Stop();

    std::cout<<"Test1 task run count:"<<pool.task_run_count()<<std::endl;
    getchar();
}


void Test2(){
    std::cout<<"===================test2=============="<<std::endl;

    XThreadPool pool;
    pool.Init(3);
    pool.Start();

    for(int i=0; i<20; i++){
        std::shared_ptr<MyTask> task = std::make_shared<MyTask>();

        std::string name = "henry";
        task->name = name + std::to_string(i);

        pool.AddTask(task);
    }
 
    std::cout<<"Test2 task run count:"<<pool.task_run_count()<<std::endl;

    std::this_thread::sleep_for(std::chrono::milliseconds(3000));
    pool.Stop();
    std::cout<<"Test2 task run count:"<<pool.task_run_count()<<std::endl;

    getchar();
}


void Test3(){
    std::cout<<"===================test3=============="<<std::endl;
    XThreadPool pool;
    pool.Init(3);
    pool.Start();

    std::shared_ptr<MyTask> task1 = std::make_shared<MyTask>();
    task1->name = "henry3";
    pool.AddTask(task1);

    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    std::cout<<"Test3 task run count:"<<pool.task_run_count()<<std::endl;

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    pool.Stop();

    std::cout<<"Test3 task run count:"<<pool.task_run_count()<<std::endl;
    getchar();
}

int main(){

    // 验证 智能指针的功能
    Test1();
    Test2();
    
    return 0;
}