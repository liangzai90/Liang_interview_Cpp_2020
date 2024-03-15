#ifndef  __COMMAND_H__
#define  __COMMAND_H__

class Command
{
public:
    virtual ~Command(){};
    virtual void Execute() = 0;
};


class Receiver
{
public:
    void Action();
};


class Invoker
{
public:
    Invoker(Command* pCommand);
    ~Invoker();
    void Invoke();

private:
    Command* m_pCommand;
};


class ConcreateCommand : public Command
{
public:
    ConcreateCommand(Receiver* pReceiver);
    virtual ~ConcreateCommand();

    virtual void Execute();

private:
    Receiver* m_pReceiver;
};


#endif 

