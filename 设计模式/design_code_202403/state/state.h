#ifndef  __STATE_H__
#define  __STATE_H__

class State;

class Context
{
public:
    Context(State* pState);
    ~Context();

    void Request();
    void ChangeState(State* pState);

private:
    State* m_pState;
};


class State
{
public:
    State(){};
    virtual ~State(){};

    virtual void Handle(Context* pContext) = 0;
};


class ConcreateStateA : public State
{
public:
    ConcreateStateA() {};
    ~ConcreateStateA() {};

public:
    void Handle(Context* pContext);
};

class ConcreateStateB : public State
{
public:
    ConcreateStateB()  {};
    ~ConcreateStateB() {};

public:
    void Handle(Context* pContext);
};



#endif 