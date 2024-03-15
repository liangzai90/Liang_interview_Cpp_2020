#include <iostream>
#include "iterator.h"

using namespace std;

//--------------------------------------------------
// ConcreateAggregate  
//--------------------------------------------------
ConcreateAggregate::ConcreateAggregate(int nSize) : m_nSize(nSize), m_pData(nullptr)
{
    m_pData = new DATA[m_nSize];

    for (int i = 0; i < nSize; ++i)
    {
        m_pData[i] = i;
    }
}

ConcreateAggregate::~ConcreateAggregate()
{
    delete[] m_pData;
    m_pData = nullptr;
}

Iterater* ConcreateAggregate::CreateIterater(Aggregate* pAggregate)
{
    return new ConcreateIterater(this);
}

int ConcreateAggregate::GetSize()
{
    return m_nSize;
}

DATA ConcreateAggregate::GetItem(int nIndex)
{
    if (nIndex < m_nSize)
    {
        return m_pData[nIndex];
    }
    else
    {
        return -1;
    }
}


//--------------------------------------------------
// ConcreateIterater  
//--------------------------------------------------
ConcreateIterater::ConcreateIterater(Aggregate* pAggregate) : m_pConcreateAggregate(pAggregate), m_nIndex(0)
{
    cout << "ConcreateIterater  construct." << endl;
}

void ConcreateIterater::First()
{
    m_nIndex = 0;
}

void ConcreateIterater::Next()
{
    if (m_nIndex < m_pConcreateAggregate->GetSize())
    {
        ++m_nIndex;
    }
}

bool ConcreateIterater::IsDone()
{
    // 到达最后一个元素的 位置
    return m_nIndex == m_pConcreateAggregate->GetSize();
}

DATA ConcreateIterater::CurrentItem()
{
    return m_pConcreateAggregate->GetItem(m_nIndex);
}

