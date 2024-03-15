#ifndef  __ITERATOR_H__
#define  __ITERATOR_H__

typedef int DATA;

class Iterater;


// 容器的抽象基类
class Aggregate
{
public:
    Aggregate() {};
    virtual ~Aggregate() {};

    virtual Iterater* CreateIterater(Aggregate* pAggregate) = 0;
    virtual int GetSize() = 0;
    virtual DATA GetItem(int nIndex) = 0;
};



// 迭代器 的抽象基类
class Iterater
{
public:
    Iterater() {};
    virtual ~Iterater() {};

    virtual void First() = 0;
    virtual void Next() = 0;
    virtual bool IsDone() = 0;
    virtual DATA CurrentItem() = 0;

private:
    /// 
};



// 一个具体的容器类，这里是用数组表示
class ConcreateAggregate : public Aggregate
{
public:
    ConcreateAggregate(int nSize);
    virtual ~ConcreateAggregate();

    virtual Iterater* CreateIterater(Aggregate* pAggregate);
    virtual int GetSize();
    virtual DATA GetItem(int nIndex);

private:
    int m_nSize;
    DATA* m_pData;
};



// 访问 ConcreateAggregate 容器类的 迭代器类
class ConcreateIterater : public Iterater
{
public:
    ConcreateIterater(Aggregate* pAggregate);
    virtual ~ConcreateIterater(){};

    virtual void First();
    virtual void Next();
    virtual bool IsDone();
    virtual DATA CurrentItem();

private:
    Aggregate* m_pConcreateAggregate;
    int m_nIndex;
};

#endif 