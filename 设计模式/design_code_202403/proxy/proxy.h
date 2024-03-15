#ifndef  __PROXY_H__
#define  __PROXY_H__


// 定义了 Proxy 和 RealSubject 的公有接口
// 这样就可以在 任何需要使用到 RealSubject  的地方都使用 Proxy
class Subject
{
public:
    Subject(){};
    virtual ~Subject(){};

    virtual void Request() = 0;
};


// 真正使用的实体
class RealSubject : public Subject
{
public:
    RealSubject();
    virtual ~RealSubject(){};

    virtual void Request();
};


// 代理类，含有一个指向 RealSubject 对象的指针
class Proxy : public Subject
{
public:
    Proxy();
    virtual ~Proxy();
    
    virtual void Request();

private:
    RealSubject* m_pRealSubject;
};


#endif 