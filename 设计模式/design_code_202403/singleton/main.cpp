#include "singleton.h"
#include <iostream>

using namespace std;


// 这种单例模式下，只能通过 Singleton::GetInstancePtr() 获取单例的指针来访问单例
void Test1(){
    std::cout<<"-------------------test1-----"<<std::endl;
    Singleton* s1 = Singleton::GetInstancePtr();
    Singleton* s2 = Singleton::GetInstancePtr();

    s1->SetValue(666);
    s2->SetValue(777);

    s1->Print();
    s2->Print();
}


void Test2(){
    std::cout<<"-------------------test2-----"<<std::endl;
    Singleton::GetInstancePtr()->SetValue(123);
    Singleton::GetInstancePtr()->SetValue(321);

    Singleton::GetInstancePtr()->Print();
    Singleton::GetInstancePtr()->Print();
}

int main()
{
    Test1();
    Test2();

    getchar();
    return 0;
}
