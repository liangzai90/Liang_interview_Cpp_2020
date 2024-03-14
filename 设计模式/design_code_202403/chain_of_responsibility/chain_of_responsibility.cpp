#include "chain_of_responsibility.h"
#include <iostream>

using namespace std;

//---------------------------------------------------------
// Handler 
//---------------------------------------------------------
Handler::Handler(Handler* pSuccessor /*= nullptr*/) : m_pSuccessor(pSuccessor)
{
    cout << "Handler Construct." << endl;
}

Handler::~Handler()
{
    cout << "Handler Destruct." << endl;

    delete m_pSuccessor;
    m_pSuccessor = NULL;
}


//---------------------------------------------------------
// ConcreateHandler1
//---------------------------------------------------------
ConcreateHandler1::ConcreateHandler1(Handler* pSuccessor) : Handler(pSuccessor)
{
    cout << "Concreatehandler1 construct." << endl;
}

void ConcreateHandler1::HandleRequest()
{
    if (NULL != m_pSuccessor)
    {
        m_pSuccessor->HandleRequest();
    }
    else
    {
        cout << "HandleRequest by ConcreateHandler1." << endl;
    }
}


//---------------------------------------------------------
// ConcreateHandler2 
//---------------------------------------------------------
ConcreateHandler2::ConcreateHandler2(Handler* pSuccessor) : Handler(pSuccessor)
{
    cout << "Concreatehandler2 construct." << endl;
}

void ConcreateHandler2::HandleRequest()
{
    if (NULL != m_pSuccessor)
    {
        m_pSuccessor->HandleRequest();
    }
    else
    {
        cout << "HandleRequest by ConcreateHandler2." << endl;
    }
}


//---------------------------------------------------------
// ConcreateHandler3 
//---------------------------------------------------------
ConcreateHandler3::ConcreateHandler3(Handler* pSuccessor) : Handler(pSuccessor)
{
    cout << "Concreatehandler3 construct." << endl;
}

void ConcreateHandler3::HandleRequest()
{
    if (NULL != m_pSuccessor)
    {
        m_pSuccessor->HandleRequest();
    }
    else
    {
        cout << "HandleRequest by ConcreateHandler3." << endl;
    }
}


//---------------------------------------------------------
// ConcreateHandler4 
//---------------------------------------------------------
ConcreateHandler4::ConcreateHandler4(Handler* pSuccessor) : Handler(pSuccessor)
{
    cout << "Concreatehandler4 construct." << endl;
}

void ConcreateHandler4::HandleRequest()
{
    if (NULL != m_pSuccessor)
    {
        m_pSuccessor->HandleRequest();
    }
    else
    {
        cout << "HandleRequest by ConcreateHandler4." << endl;
    }
}




