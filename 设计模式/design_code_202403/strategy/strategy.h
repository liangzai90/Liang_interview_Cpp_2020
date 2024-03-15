#ifndef  __STRATEGY_H__
#define  __STRATEGY_H__

class Strategy;

class Context
{
public:
    Context(Strategy* pStrategy);
    ~Context();

    void ContextInterface();

private:
    Strategy* m_pStrategy;
};


class Strategy
{
public:
    Strategy(){};
    virtual ~Strategy(){};

    virtual void AlgorithmInterface() = 0;
};


class ConcreateStrategyA : public Strategy
{
public:
    ConcreateStrategyA(){};
    virtual ~ConcreateStrategyA(){};

    virtual void AlgorithmInterface();
};



#endif 