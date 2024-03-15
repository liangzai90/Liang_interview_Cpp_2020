
#include <iostream>
#include "prototype.h"
using namespace std;

void test1(){
    Prototype* pPrototype1 = new ConcreatePrototype1();
    Prototype* pPrototype2 = pPrototype1->Clone();

//     Prototype* pPrototype3 = new ConcreatePrototype2();
//     Prototype* pPrototype4 = pPrototype3->Clone();
    pPrototype1->Print01();
    pPrototype1->Print03();

    delete pPrototype1;
//     delete pPrototype2;
//     delete pPrototype3;
//     delete pPrototype4;

    pPrototype2->Print01();

    //// 这里也有 子类虚表 覆盖 父类虚表 方面的东西
    //// 此处需要 复习一下  重载(overload)、覆盖(重写 override)、隐藏(重定义 redefining)
    // 错误！
    // pPrototype2，虽然是由 ConcreatePrototype1（子类型）强制转换过去的，但它是 Prototype 类型（父类型）。
    //【0】 pPrototype2 它只能访问 Prototype 里面定义的方法。
    // 【1】如果是普通方法，正常访问
    // 【2】如果是 虚函数，且子类（ConcreatePrototype1）没有重写该虚函数，则访问的是 父类（Prototype）的虚函数；
    // 【3】如果是 虚函数，子类（ConcreatePrototype1）重写了该虚函数，则子类的虚函数覆盖了父类的虚函数。这叫【覆盖(override)】。访问的是 子类（ConcreatePrototype1）的（虚）函数；
    // 【4】如果是纯虚函数（接口），访问的是 子类（ConcreatePrototype1）的函数；
    // pPrototype2->Print02();//// 

}

int main()
{
    test1();
    getchar();
    return 0;
}


