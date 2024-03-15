
#include <iostream>
#include "memento.h"
using namespace std;

void test1(){
    // 创建一个 原发器 
    Originator* pOriginator = new Originator("old state");
    pOriginator->PrintState();

    // 创建一个备忘录存放这个原发器的状态
    Memento* pMemento = pOriginator->CreateMemento();

    // 更改原发器的状态
    pOriginator->SetState("new state");
    pOriginator->PrintState();

    // 通过备忘录把原发器的状态还原到之前的状态
    pOriginator->RestoreState(pMemento);
    pOriginator->PrintState();

    delete pOriginator;
    delete pMemento;
}

int main()
{
    test1();
    getchar();
    return 0;
}


