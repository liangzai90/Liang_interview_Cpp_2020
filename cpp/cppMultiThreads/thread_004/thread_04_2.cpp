#include <iostream>
#include <thread>
#include <string>

//验证lambda表达式的用法
class TestLambda{
public:
    void Start(){
        std::thread th([this](){
            std::cout<<"TestLambda Start, name:"<<name<<std::endl;
        });
        th.join();
    }

    std::string name = "test lambda";
};

int main(int argc, char* argv[]) {
    std::thread th(
        [](int i) {std::cout<<"---> "<<i<<std::endl;},
        10086);
    th.join();

    TestLambda test;
    test.Start();
    getchar();
    return 0;
}
