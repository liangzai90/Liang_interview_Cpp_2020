#ifndef __SINGLETON_H__
#define __SINGLETON_H__
#include <iostream>

class Singleton
{
public:
    // 定义类的静态指针，和一个静态函数。
    // 私有化  构造函数、析构函数、构造复制、重载赋值语句.线程安全，采用互斥体的方式实现.
    Singleton(){ std::cout<<" construct singleton"<<std::endl;};
    virtual ~Singleton(){};

    
    // 静态成员函数，提供全局访问的接口
    static Singleton* GetInstancePtr();
 
    void Print();
    void SetValue(int val);

private:
    // 静态成员变量，提供全局唯一的一个实例
    static Singleton* m_pStatic;
    int m_value;

    Singleton& operator=(const Singleton& ) = delete; 
    Singleton(const Singleton&) = delete;
 };


#endif 