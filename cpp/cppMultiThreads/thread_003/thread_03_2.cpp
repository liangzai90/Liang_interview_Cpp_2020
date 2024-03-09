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

void ThreadMainPtr(Para* p) {
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    std::cout<<"ThreadMainPtr name = "<<p->name<<std::endl;
}

void ThreadMainRef(Para& p){
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    std::cout<<"ThreadMainRef name = "<<p.name<<std::endl;
}

int main(int argc, char* argv[]) {
    {
        //传递引用
        Para p;
        p.name = "test ref";
        std::thread th(ThreadMainRef, std::ref(p)); //传递引用必须使用 std::ref
        th.join();
    }
    getchar();
    std::cout <<"-----------------------"<<std::endl;

    {
        //传递线程指针
        Para p;
        p.name = "this is pointer";
        std::thread th(ThreadMainPtr, &p);//错误，线程访问的p空间会提前释放
        th.detach();
    }

    getchar();
    std::cout <<"-----------------------"<<std::endl;

    {
        //传递线程指针
        Para p;
        p.name = "this is pointer2";
        std::thread th(ThreadMainPtr, &p);
        th.join();
    }


    getchar();
    return 0;
}
