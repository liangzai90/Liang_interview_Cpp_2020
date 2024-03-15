
#include <iostream>
#include "template_method.h"
using namespace std;

void test1(){
    AbstractClass* pConcreateClass = new ConcreateClass();
    pConcreateClass->TemplateMethod();

    delete pConcreateClass;
}

int main()
{
    test1();
    getchar();
    return 0;
}


