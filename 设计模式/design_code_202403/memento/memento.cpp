#include "memento.h"
#include <iostream>

using namespace std;


///-----------------------------------------------------
// Originator   
///-----------------------------------------------------
Originator::Originator()
{
    cout << "Originator construct." << endl;
}

Originator::Originator(const State& rState) : m_State(rState)
{
    cout << "Originator construct .. para 1" << endl;
}

Originator::~Originator()
{
    cout << "Originator destruct." << endl;
}

State Originator::GetState()
{
    return m_State;
}

void Originator::SetState(const State& rState)
{
    m_State = rState;
}

Memento* Originator::CreateMemento()
{
    return new Memento(m_State);
}

void Originator::RestoreState(Memento* pMemento)
{
    if (nullptr != pMemento)
    {
        m_State = pMemento->GetState();
    }
}

void Originator::PrintState()
{
    cout << "PrintState()--- State = " << m_State << endl;
}





///-----------------------------------------------------
// Memento   
///-----------------------------------------------------
Memento::Memento(const State& rState) :m_State(rState)
{
    cout << "Memento construct." << endl;
}

State Memento::GetState()
{
    return m_State;
}

void Memento::SetState(const State& rState)
{
    m_State = rState;
}


