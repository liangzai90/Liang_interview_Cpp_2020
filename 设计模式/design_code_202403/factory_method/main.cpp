
#include <iostream>
#include "factory_method.h"
using namespace std;

void test1(){
    Creator* p = new ConcreateCreator();
    p->AnOperation();

    delete p;
}

int main()
{
    test1();
    getchar();
    return 0;
}


