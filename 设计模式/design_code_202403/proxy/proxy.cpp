#include "proxy.h"
#include <iostream>

using namespace std;


//-------------------------------------------
// RealSubject 
//-------------------------------------------
RealSubject::RealSubject()
{
    cout << "Constructing a RealSubject." << endl;
}

void RealSubject::Request()
{
    cout << "Request By RealSubject." << endl;
}


//-------------------------------------------
// Proxy
//-------------------------------------------
Proxy::Proxy() : m_pRealSubject(NULL)
{
    cout << "Constructing a Proxy." << endl;
}

Proxy::~Proxy()
{
    delete m_pRealSubject;
    m_pRealSubject = NULL;
}

void Proxy::Request()
{
    // 需要使用 RealSubject 的时候才去初始化
    if (NULL == m_pRealSubject)
    {
        cout << "Request By Proxy." << endl;
        m_pRealSubject = new RealSubject();
    }
    m_pRealSubject->Request();
}



