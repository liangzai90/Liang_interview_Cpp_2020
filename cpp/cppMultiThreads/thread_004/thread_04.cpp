#include <iostream>
#include <thread>
#include <string>

//using namespace std;

class MyThread {
public:
    //入口线程函数
    void Main(){
        std::cout<<"MyThread Main "<< name <<std::endl;
    }
    std::string name;
    int age = 100;
};

// 定义一个线程基类，管理线程的生命周期
class XThread {
public:
    virtual void Start(){
        is_exit_ = false;
        // 以成员函数作为线程入口函数
        th_ = std::thread(&XThread::Main, this);
    }
    virtual void Stop(){
        is_exit_ = true;
        Wait();
    }
    virtual void Wait(){
        if(th_.joinable()){
            th_.join();
        }
    }

    bool is_exit() {return is_exit_;}

private:
    virtual void Main() = 0;
    bool is_exit_ = false;
    std::thread  th_;
};

//派生类，实现具体的Main函数即可
class TestXThread : public XThread {
public:
    void Main() override {
        std::cout<<"TestXThread Main begin "<< std::endl;
        while(!is_exit()){
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
            std::cout<<"."<<std::flush;
        }
        std::cout<<"TestXThread Main end"<<std::endl;
    }

    std::string name;
};

int main(int argc, char* argv[]) {
    {
        // 成员函数作为线程入口
        MyThread myth;
        myth.name = "test name henry";
        myth.age = 123;
        // &MyThread::Main 是 成员函数的指针
        // &myth 当前对象的地址
        std::thread th(&MyThread::Main, &myth);
        th.join();
        std::cout<<"---------------------"<<std::endl;
    }


    {
        // 类型的封装，在类里面管理线程的生命周期
        TestXThread testth;
        testth.name = "test xThread name henry";
        testth.Start();
        std::this_thread::sleep_for(std::chrono::milliseconds(3000));
        testth.Stop();
        testth.Wait();
        getchar();
        std::cout<<"---------------------"<<std::endl;
    }



    return 0;
}
