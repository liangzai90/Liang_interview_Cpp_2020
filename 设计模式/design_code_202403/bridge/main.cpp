
#include <iostream>
#include "bridge.h"
using namespace std;

void test1(){
    ConcreateImplementorA* pImplA = new ConcreateImplementorA();
    Abstraction* pAbstraction1 = new Abstraction(pImplA); //pImplA 在 Abstraction 的析构函数里面被释放了
    pAbstraction1->Operation();

    ConcreateImplementorB* pImplB = new ConcreateImplementorB();
    Abstraction* pAbstraction2 = new Abstraction(pImplB);
    pAbstraction2->Operation();

    delete pAbstraction1;
    delete pAbstraction2;
}

int main()
{
    test1();
    getchar();
    return 0;
}


