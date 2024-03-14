#ifndef __ADAPTER_H__
#define __ADAPTER_H__
#include <memory>  // for std::shared_ptr  and  make_shared

// 需要被 Adapt 的类
class Target
{
public:
    Target(){};
    virtual ~Target(){};
    virtual void Request() = 0;
};

class Adaptee; //类的前置声明

// 进行 Adapt 的类，采用聚合原有接口类的方式
class Adapter : public Target
{
public:
    Adapter(std::shared_ptr<Adaptee> pAdptee);
    virtual ~Adapter();
    virtual void Request();

private:
    std::shared_ptr<Adaptee> m_pAdptee;
};

// 与被 Adapt 对象提供不兼容接口的类
class Adaptee
{
public:
    Adaptee();
    ~Adaptee();
    void SpecialRequest();
};

#endif  