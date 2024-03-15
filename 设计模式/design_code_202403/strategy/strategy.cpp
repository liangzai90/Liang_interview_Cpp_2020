#include "strategy.h"
#include <iostream>

using namespace std;
//---------------------------------------------------
// Context  
//---------------------------------------------------
Context::Context(Strategy* pStrategy) : m_pStrategy(pStrategy)
{
    cout << "Context construct." << endl;
}

Context::~Context()
{
    delete m_pStrategy;
    m_pStrategy = nullptr;
}

void Context::ContextInterface()
{
    if (nullptr != m_pStrategy)
    {
        m_pStrategy->AlgorithmInterface();
    }
}

//---------------------------------------------------
// ConcreateStrategyA  
//---------------------------------------------------
void ConcreateStrategyA::AlgorithmInterface()
{
    cout << "ConcreateStrategyA  Implemented by ConcreateStrategyA." << endl;
}

