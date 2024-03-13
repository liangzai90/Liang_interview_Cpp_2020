#ifndef __SINGLETON_H__
#define __SINGLETON_H__
#include <iostream>

class Singleton
{
    // 定义类的静态指针，和一个静态函数。
public:    
    // 静态成员函数，提供全局访问的接口
    static Singleton* GetInstancePtr();
 
    void Print();
    void SetValue(int val);

private:
    // 静态成员变量，提供全局唯一的一个实例
    static Singleton* m_pStatic;
    int m_value;

    // 将构造函数和析构函数设为私有，防止外部创建和删除对象
    Singleton() {}
    ~Singleton() {}
    // 禁止复制和赋值操作，确保只有一个实例
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;
 };


#endif 