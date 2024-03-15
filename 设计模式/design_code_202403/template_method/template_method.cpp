#include <iostream>
#include "template_method.h"

using namespace std;

//--------------------------------------------------
// AbstractClass
//--------------------------------------------------
void AbstractClass::TemplateMethod()
{
    PrimitiveOperation1();
    PrimitiveOperation2();
}

//--------------------------------------------------
// ConcreateClass
//--------------------------------------------------
void ConcreateClass::PrimitiveOperation1()
{
    cout << "PrimitiveOperation1 by ConcreateClass." << endl;
}

void ConcreateClass::PrimitiveOperation2()
{
    cout << "PrimitiveOperation2 by ConcreateClass." << endl;
}




