#ifndef __BRIDGE_H__
#define __BRIDGE_H__

class Implementor;

// 维护一个 Implementor 类的指针
class Abstraction
{
public:
    Abstraction(Implementor* pImplementor);
    virtual ~Abstraction();
    void Operation();
protected:
    // 聚合 关系（Abstraction聚合了Implementor），通过构造函数传入 类的指针
    Implementor* m_pImplementor;
};

// 为实现 Abstraction 定义的抽象基类，定义了 实现的接口函数
class Implementor
{
public:
    Implementor(){};
    virtual ~Implementor(){};
    virtual void OperationImpl() = 0;
};

// 继承自 Implementor，是 Implementor 的不同实现之一
class ConcreateImplementorA : public Implementor
{
public:
    ConcreateImplementorA(){};
    virtual ~ConcreateImplementorA(){};
    virtual void OperationImpl();
};

// 继承自 Implementor, 是 Implementor 的不同实现之一
class ConcreateImplementorB : public Implementor
{
public:
    ConcreateImplementorB(){};
    virtual ~ConcreateImplementorB(){};
    virtual void OperationImpl();
};

#endif 
