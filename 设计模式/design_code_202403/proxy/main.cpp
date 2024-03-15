
#include <iostream>
#include "proxy.h"
using namespace std;

void test1(){
    Subject* pProxy = new Proxy();
    pProxy->Request();

    delete pProxy;
}

int main()
{
    test1();
    getchar();
    return 0;
}


