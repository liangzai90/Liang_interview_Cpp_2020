#include <iostream>
#include "xthread_pool.h"

class MyTask : public XTask{
public:
    task_info_tag Run() override{
        //std::cout<<"============================================"<<std::endl;
        //std::cout<<std::this_thread::get_id()<<" MyTask Run "<<name<<std::endl;
        //std::cout<<"============================================"<<std::endl;

        for(int i=0; i<10; ++i){
            if(is_exit()) break;

            std::cout<<"."<<std::flush;
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
        }

        // 构造 要返回的信息
        task_info_tag ret_info;
        ret_info.id = id_;
        ret_info.name = name;
        ret_info.msg = msg;
        return ret_info; //返回执行结果
    }

    MyTask(int id=0):id_(id){
    }

//todo 这里的变量定义的还不太严谨，这里只是展示使用方法
    std::string name = "";
    int id_ = 0;  //任务ID
    std::string msg =""; // msg
};

void Test1(){
    XThreadPool pool;
    pool.Init(15);
    pool.Start();

    std::vector<std::future<task_info_tag> > ret_vec;

    for(int i=0; i<30; i++){
        std::shared_ptr<MyTask> task = std::make_shared<MyTask>(i+1000);

        std::string name = "henry";
        task->name = name + std::to_string(i);
        task->msg = std::string("msg_") + std::to_string(i+100);

        pool.AddTask(task);

        // 异步获取线程池中任务的执行结果
        ret_vec.emplace_back(task->GetReturn());//这里存放的是一个未来的值
    }

    std::cout<<"task run count:"<<pool.task_run_count()<<std::flush<<std::endl;


    // 对应的 task， 返回了该 task 里面的信息，以及处理结果
    // one_ret---> id:1017,name:henry17,msg:msg_117 
    for(auto& one_ret : ret_vec){
        //调用 get() ,阻塞，等待未来的值返回
        auto ret = one_ret.get();
        std::cout<<"one_ret---> id:"<<ret.id << ",name:"<<ret.name<<",msg:"<<ret.msg <<std::flush<< std::endl;// 同步阻塞了，等待 future 值
    }

    std::this_thread::sleep_for(std::chrono::milliseconds(3000));
    pool.Stop();
    std::cout<<"task run count:"<<pool.task_run_count()<<std::flush<<std::endl;

    getchar();
}


int main(){
    Test1();    
    return 0;
}