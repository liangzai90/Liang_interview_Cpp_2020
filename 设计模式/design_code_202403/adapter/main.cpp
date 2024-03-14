
#include <iostream>
#include "adapter.h"
using namespace std;

void test1(){
    std::shared_ptr<Adaptee> pAdaptee = std::make_shared<Adaptee>();
    getchar();
    std::shared_ptr<Target> pTarget = std::make_shared<Adapter>(pAdaptee);
    pTarget->Request();
}

int main()
{
    test1();
    std::cout<<"-----------2个智能指针都析构了"<<std::endl;
    getchar();
    return 0;
}


