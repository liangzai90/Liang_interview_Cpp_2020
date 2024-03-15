#ifndef  __OBSERVER_H__
#define  __OBSERVER_H__

#include <list>

typedef int STATE;

class Observer;


// Subject抽象基类，只需要知道 Observer 基类的声明就可以了
class Subject
{
public:
    Subject() : m_nSubjectState(-1){};
    virtual ~Subject();

    // 通知对象改变状态
    void Notify();
    // 新增对象
    void Attach(Observer* pObserver);
    // 删除对象
    void Detach(Observer* pObserver);

    // 虚函数，提供默认的实现，派生类可以自己实现来覆盖基类的实现
    // 设置状态
    virtual void SetState(STATE nState);
    // 得到状态
    virtual STATE GetState();

protected:
    // 模拟保存 Subject 状态的变量
    STATE m_nSubjectState;
    // 保存 Observer 指针的链表
    std::list<Observer*> m_ListObserver;
};




// ConcreateSubject 类，派生自 Subject 类
class ConcreateSubject : public Subject
{
public:
    ConcreateSubject() : Subject() {};
    virtual ~ConcreateSubject() {};

    // 派生类 自己实现，来覆盖基类的实现
    // 设置状态
    virtual void SetState(STATE nState);
    // 得到状态
    virtual STATE GetState();
};




// Observer 抽象基类
class Observer
{
public:
    Observer() : m_nObserverState(-1){};
    virtual ~Observer() {};

    // 纯虚函数，各个派生类可能有不同实现
    // 通知 Observer 状态发生了变化
    virtual void Update(Subject* pSubject) = 0;

protected:
    // 模拟保存 Observer 状态的变量
    STATE m_nObserverState;
};



// ConcreateObserver 类派生自 Observer
class ConcreateObserver : public Observer
{
public:
    ConcreateObserver() : Observer() {};
    virtual ~ConcreateObserver() {};

    // 虚函数，实现基类提供的接口
    virtual void Update(Subject* pSubject);
};



#endif 