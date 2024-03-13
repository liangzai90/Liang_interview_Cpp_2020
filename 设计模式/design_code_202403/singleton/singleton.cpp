#include "singleton.h"
#include <iostream>

using namespace std;

// 类的静态成员变量要在类体外进行定义
Singleton* Singleton::m_pStatic = NULL;


Singleton* Singleton::GetInstancePtr()
{
    if (NULL == m_pStatic)
    {
        m_pStatic = new Singleton();
    }
    return m_pStatic;
}
void Singleton::Print()
{
    cout << "Singleton::Print! val:"<<m_value << endl;
}

void Singleton::SetValue(int val){
    m_value = val;
}


