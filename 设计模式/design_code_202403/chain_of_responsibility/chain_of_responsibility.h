#ifndef  __CHAINOFRESPONSIBILITY_H__
#define  __CHAINOFRESPONSIBILITY_H__

#include <iostream>
using namespace std;

// 抽象基类，定义一个处理请求的接口
class Handler
{
public:
    Handler(Handler* pSuccessor = nullptr);
    virtual ~Handler();

    // 纯虚函数，由派生类实现
    virtual void HandleRequest() = 0;

protected:
    Handler* m_pSuccessor;
};


class ConcreateHandler1 : public Handler
{
public:
    ConcreateHandler1(Handler* pSuccessor = nullptr);

    virtual ~ConcreateHandler1()
    {
        cout << "ConcreateHandler1 Destruct" << endl;
    };

    virtual void HandleRequest();
};


class ConcreateHandler2 : public Handler
{
public:
    ConcreateHandler2(Handler* pSuccessor = nullptr);
    virtual ~ConcreateHandler2()
    {
        cout << "ConcreateHandler2 Destruct" << endl;
    };

    virtual void HandleRequest();
};


class ConcreateHandler3 : public Handler
{
public:
    ConcreateHandler3(Handler* pSuccessor = nullptr);
    virtual ~ConcreateHandler3()
    {
        cout << "ConcreateHandler3 Destruct" << endl;
    };

    virtual void HandleRequest();
};


class ConcreateHandler4 : public Handler
{
public:
    ConcreateHandler4(Handler* pSuccessor = nullptr);
    virtual ~ConcreateHandler4()
    {
        cout << "ConcreateHandler4 Destruct" << endl;
    };

    virtual void HandleRequest();
};


#endif 


