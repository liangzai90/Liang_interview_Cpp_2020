#include "composite.h"
#include <iostream>
#include <algorithm>

using namespace std;

//-----------------------------------------------
// Component 
//-----------------------------------------------
void Component::Add(Component* pChild)
{
    // 
}

void Component::Remove(Component* pChild)
{
    // 
}

Component* Component::GetChild(int nIndex)
{
    return NULL;
}



//-----------------------------------------------
// Leaf
//-----------------------------------------------
void Leaf::Operation()
{
    cout << "Operation by Leaf." << endl;
}



//-----------------------------------------------
// Composite
//-----------------------------------------------
Composite::~Composite()
{
    list<Component*>::iterator  iter1, iter2, temp;
    for (iter1 = m_ListOfComponent.begin(), iter2 = m_ListOfComponent.end(); iter1 != iter2;)
    {
        temp = iter1;
        ++iter1;
        delete(*temp);
    }
}

void Composite::Add(Component* pChild)
{
    m_ListOfComponent.push_back(pChild);
}

void Composite::Remove(Component* pChild)
{
    list<Component*>::iterator  iter;
    iter = find(m_ListOfComponent.begin(), m_ListOfComponent.end(), pChild);

    if (m_ListOfComponent.end() != iter)
    {
        m_ListOfComponent.erase(iter);
    }
}

Component* Composite::GetChild(int nIndex)
{
    if (nIndex <= 0 ||  static_cast<size_t>(nIndex) > m_ListOfComponent.size())
        return NULL;
    list<Component*>::iterator  iter1, iter2;
    int i;
    for (i = 1, iter1 = m_ListOfComponent.begin(), iter2 = m_ListOfComponent.end(); iter1 != iter2; ++iter1, ++i)
    {
        if (i == nIndex)
        {
            break;
        }
    }
    return *iter1;
}


void Composite::Operation()
{
    cout << "Operation by Composite." << endl;

    list<Component*>::iterator  iter1, iter2;
    for (iter1 = m_ListOfComponent.begin(), iter2 = m_ListOfComponent.end(); iter1 != iter2; ++iter1)
    {
        (*iter1)->Operation();
    }
}




