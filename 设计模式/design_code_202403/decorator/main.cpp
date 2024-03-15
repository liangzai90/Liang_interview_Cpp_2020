
#include <iostream>
#include "decorator.h"
using namespace std;

void test1(){
    // 初始化一个 Component 对象
    Component* pComponent = new ConcreateComponent();
    // 采用这个 Component 对象去初始化一个 Decorator 对象，这样就可以为这个 Component 对象动态添加职责
    Decorator* pDecorator = new ConcreateDecorator(pComponent);
    pDecorator->Operation();
    delete pDecorator;
}

int main()
{
    test1();
    getchar();
    return 0;
}


