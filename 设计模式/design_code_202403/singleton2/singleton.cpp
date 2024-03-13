#include "singleton.h"
#include <iostream>

using namespace std;

// 获取单例实例的静态方法
Singleton& Singleton::getInstance() {
    // 使用静态局部变量确保线程安全的懒汉式单例模式
    static Singleton instance;
    return instance;
}

// 单例类的其他方法和成员
void Singleton::Print()
{
    cout << "Singleton::Print! val:"<<m_value << endl;
}

void Singleton::SetValue(int val){
    m_value = val;
}

