
#include <iostream>
#include "visitor.h"
using namespace std;

void test1(){
    Visitor* pVisitorA = new ConcreateVisitorA();
    Element* pElementA = new ConcreateElementA();
    Element* pElementB = new ConcreateElementB();

    // 元素A 接受(Accept) 访问器A 访问 
    pElementA->Accept(*pVisitorA);

    // 元素B 接受(Accept) 访问器A 访问 
    pElementB->Accept(*pVisitorA);

    delete pElementA;
    delete pElementB;
    delete pVisitorA;

}

int main()
{
    test1();
    getchar();
    return 0;
}


