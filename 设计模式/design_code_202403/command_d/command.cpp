#include "command.h"
#include <iostream>

using namespace std;



//---------------------------------------
// Receiver
//---------------------------------------
void Receiver::Action()
{
    cout << "Receiver  Action." << endl;
}




//---------------------------------------
// Invoker
//---------------------------------------
Invoker::Invoker(Command* pCommand) : m_pCommand(pCommand)
{
    cout << "Invoker  construct." << endl;
}

Invoker::~Invoker()
{
    delete m_pCommand;
    m_pCommand = nullptr;
}

void Invoker::Invoke()
{
    if (nullptr != m_pCommand)
    {
        m_pCommand->Execute();
    }
}



//---------------------------------------
// ConcreateCommand
//---------------------------------------
ConcreateCommand::ConcreateCommand(Receiver* pReceiver)
{
    cout << "ConcreateCommand  construct." << endl;
}

ConcreateCommand::~ConcreateCommand()
{
    delete m_pReceiver;
    m_pReceiver = nullptr;
}

void ConcreateCommand::Execute()
{
    if (nullptr != m_pReceiver)
    {
        m_pReceiver->Action();
    }
    cout << "Execute by ConcreateCommand." << endl;
}
