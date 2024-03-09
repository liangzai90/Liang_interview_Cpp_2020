#include <iostream>
#include <thread>
#include <string>

//using namespace std;
class Para{
public:
    Para() {std::cout<<"Create Para"<<std::endl;}
    Para(const Para& p) {std::cout<<"Copy Para"<<std::endl;}
    ~Para() {std::cout<<"Drop Para"<<std::endl;}
    std::string name;
};

//线程调用这个回调函数的时候，Para 对象又进行了一次拷贝构造【这是第三次】
void ThreadMain(int p1, float p2, std::string str, Para p4){
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    std::cout<<"ThreadMain "<<p1<<" "<<p2<<" "<<str<<" "<<p4.name<<std::endl;
}

int main(int argc, char* argv[]) {
    std::thread th;
    {
        float f1 = 12.1f;
        Para p; //创建对象 【这是第一次】
        p.name ="henry daociyiyou";
        
        //所有参数都做复制
        //p对象，作为参数传递过来的时候，做了一次复制（线程把p对象存了下来【这是第二次】），因此这里会有一次拷贝构造
        th =  std::thread(ThreadMain, 10086, f1, "test para", p);
    }

    th.join();
    getchar();
    return 0;
}
