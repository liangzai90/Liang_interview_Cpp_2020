#ifndef __PROTOTYPE_H__
#define __PROTOTYPE_H__

// 虚拟基类，所有原型的基类，提供Clone接口函数
class Prototype
{
public:
    Prototype(){};
    virtual ~Prototype(){};

    virtual Prototype* Clone() = 0;
    virtual void Print01() = 0;
    virtual void Print03();
};

// 派生自 Prototype，实现 Clone 方法
class ConcreatePrototype1 : public Prototype
{
public:
    ConcreatePrototype1();
    ConcreatePrototype1(const ConcreatePrototype1&);
    virtual ~ConcreatePrototype1();

    virtual Prototype* Clone();

    virtual void Print01();
    void Print02();
    //virtual void Print03();

};

// 派生自 Prototype，实现 Clone 方法
class ConcreatePrototype2 : public Prototype
{
public:
    ConcreatePrototype2();
    ConcreatePrototype2(const ConcreatePrototype2&);
    virtual ~ConcreatePrototype2();

    virtual Prototype* Clone();

    virtual void Print01();
    void Print02();

    virtual void Print03();
};


#endif 


