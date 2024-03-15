#include "state.h"
#include <iostream>

using namespace std;



//----------------------------------------------------
// Context  
//----------------------------------------------------
Context::Context(State* pState) : m_pState(pState)
{
    cout << "Context  construct." << endl;
}

Context::~Context()
{
    delete m_pState;
    m_pState = nullptr;
}

void Context::Request()
{
    if (nullptr != m_pState)
    {
        m_pState->Handle(this);
    }
}

void Context::ChangeState(State* pState)
{
    if (nullptr != m_pState)
    {
        delete m_pState;
        m_pState = nullptr;
    }
    m_pState = pState;
}





//----------------------------------------------------
// ConcreateStateA  
//----------------------------------------------------
void ConcreateStateA::Handle(Context* pContext)
{
    cout << "Handle by ConcreateStateA..." << endl;

    if (nullptr != pContext)
    {
        pContext->ChangeState(new ConcreateStateB());
    }
}






//----------------------------------------------------
// ConcreateStateB  
//----------------------------------------------------
void ConcreateStateB::Handle(Context* pContext)
{
    cout << "Handle by ConcreateStateB.... " << endl;

    if (nullptr != pContext)
    {
        pContext->ChangeState(new ConcreateStateA());
    }
}





