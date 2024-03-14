#ifndef __ABSTRACT_FACTORY_H__
#define __ABSTRACT_FACTORY_H__



// 抽象基类 AbstractProductA,代表产品 A 的抽象 
class AbstractProductA
{
public:
    AbstractProductA(){};
    virtual ~AbstractProductA(){};
};


// 派生类 ConcreateProductA1, 继承自 AbstractProductA，代表产品 A 的第一种实现
class ConcreateProductA1 : public AbstractProductA
{
public:
    ConcreateProductA1();
    virtual ~ConcreateProductA1();
};

// 派生类 ConcreateProductA2, 继承自 AbstractProductA, 代表产品 A 的第二种实现
class ConcreateProductA2 : public AbstractProductA
{
public:
    ConcreateProductA2();
    virtual ~ConcreateProductA2();
};



// 抽象基类 AbstractProductB, 代表产品 B 的抽象 
class AbstractProductB
{
public:
    AbstractProductB(){};
    virtual ~AbstractProductB(){};
};


// 派生类 ConcreateProductB1, 继承自 AbstractProductB，代表产品 B 的第一种实现
class ConcreateProductB1 : public AbstractProductB
{
public:
    ConcreateProductB1();
    virtual ~ConcreateProductB1();
};

// 派生类 ConcreateProductB2, 继承自 AbstractProductB，代表产品 B 的第二种实现
class ConcreateProductB2 : public AbstractProductB
{
public:
    ConcreateProductB2();
    virtual ~ConcreateProductB2();
};

// 抽象基类 AbstractFactory,工厂的抽象类，生产产品A 和产品B
class AbstractFactory
{
public:
    AbstractFactory(){};
    virtual ~AbstractFactory(){};

    virtual AbstractProductA* CreateProductA() = 0;
    virtual AbstractProductB* CreateProductB() = 0;
};

// 派生类 ConcreateFactory1，继承自 AbstractFactory
// 生产产品A 和产品B的第一种实现
class ConcreateFactory1 : public AbstractFactory
{
public:
    ConcreateFactory1();
    virtual ~ConcreateFactory1();

    virtual AbstractProductA* CreateProductA();
    virtual AbstractProductB* CreateProductB();
};

// 派生类 ConcreateFactory2,继承自 AbstractFactory
// 生产产品A 和产品B 的第二种实现
class ConcreateFactory2 : public AbstractFactory
{
public:
    ConcreateFactory2();
    virtual ~ConcreateFactory2();

    virtual AbstractProductA* CreateProductA();
    virtual AbstractProductB* CreateProductB();
};


#endif // 