#include "decorator.h"
#include <iostream>

using namespace std;
//--------------------------------------------
// ConcreateComponent
//--------------------------------------------
void ConcreateComponent::Operation()
{
    cout << "Operation of ConcreateComponent." << endl;
}

//--------------------------------------------
// Decorator
//--------------------------------------------
Decorator::~Decorator()
{
    delete m_pComponent;
    m_pComponent = NULL;
}

//--------------------------------------------
// ConcreateDecorator
//--------------------------------------------
void ConcreateDecorator::Operation()
{
    m_pComponent->Operation();
    AddedBehavior();
}

void ConcreateDecorator::AddedBehavior()
{
    cout << "AddedBehavior of ConcreateDecorator." << endl;
}


