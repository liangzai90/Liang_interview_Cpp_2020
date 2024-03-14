#include "bridge.h"
#include <iostream>

using namespace std;
//-------------------------------------------------------
// ConcreateImplementorA
//-------------------------------------------------------
void ConcreateImplementorA::OperationImpl()
{
    cout << "Implementation by ConcreateImplementorA." << endl;
}

//-------------------------------------------------------
// ConcreateImplementorB
//-------------------------------------------------------
void ConcreateImplementorB::OperationImpl()
{
    cout << "Implementation by ConcreateImplementorB." << endl;
}

//-------------------------------------------------------
// Abstraction
//-------------------------------------------------------
Abstraction::Abstraction(Implementor* pImplementor) :m_pImplementor(pImplementor)
{
}

Abstraction::~Abstraction()
{
    delete m_pImplementor;
    m_pImplementor = NULL;
}

void Abstraction::Operation()
{
    m_pImplementor->OperationImpl();
}



