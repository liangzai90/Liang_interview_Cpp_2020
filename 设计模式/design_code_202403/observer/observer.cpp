#include "observer.h"
#include <iostream>
#include <algorithm>

using namespace std;



//-------------------------------------------------------------
// Subject 
//-------------------------------------------------------------
void Subject::Attach(Observer* pObserver)
{
    cout << "Attach an Observer." << endl;
    m_ListObserver.push_back(pObserver);
}

void Subject::Detach(Observer* pObserver)
{
    list<Observer*>::iterator  iter;
    iter = find(m_ListObserver.begin(), m_ListObserver.end(), pObserver);
    if (m_ListObserver.end() != iter)
    {
        m_ListObserver.erase(iter);
        cout << "the Observer find." << endl;
    }
    cout << "Detach an Observer." << endl;
}

void Subject::Notify()
{
    cout << "Notify Observer's State." << endl;
    list<Observer*>::iterator  iter1, iter2;
    for (iter1 = m_ListObserver.begin(), iter2 = m_ListObserver.end(); iter1 != iter2; ++iter1)
    {
        (*iter1)->Update(this);
    }
}

void Subject::SetState(STATE nState)
{
    cout << "SetState By Subject.." << nState << endl;
    m_nSubjectState = nState;
}

STATE Subject::GetState()
{
    cout << "GetState By Subject." << endl;
    return m_nSubjectState;
}

Subject::~Subject()
{
    list<Observer*>::iterator  iter1, iter2, temp;
    for (iter1 = m_ListObserver.begin(), iter2 = m_ListObserver.end(); iter1 != iter2;)
    {
        temp = iter1;
        ++iter1;
        delete(*temp);
    }

    m_ListObserver.clear();
}




//-------------------------------------------------------------
// ConcreateSubject  
//-------------------------------------------------------------
void ConcreateSubject::SetState(STATE nState)
{
    cout << "SetState by ConcreateSubject." << nState << endl;
    m_nSubjectState = nState;
}

STATE ConcreateSubject::GetState()
{
    cout << "GetState By ConcreateSubject." << endl;
    return m_nSubjectState;
}



//-------------------------------------------------------------
// ConcreateObserver 
//-------------------------------------------------------------
void ConcreateObserver::Update(Subject* pSubject)
{
    if (nullptr == pSubject)
    {
        return;
    }
    m_nObserverState = pSubject->GetState();
    cout << "The ObserverState is .. " << m_nObserverState << endl;
}








