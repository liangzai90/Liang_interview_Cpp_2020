
#include <iostream>
#include "command.h"
using namespace std;

void test1(){
    Receiver* pReceiver = new Receiver();
    Command* pCommand = new ConcreateCommand(pReceiver);
    Invoker* pInvoker = new Invoker(pCommand);

    pInvoker->Invoke();

    delete pInvoker;
}

int main()
{
    test1();
    getchar();
    return 0;
}


