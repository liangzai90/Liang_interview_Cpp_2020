
#include <iostream>
#include "state.h"
using namespace std;

void test1(){
    State* pState = new ConcreateStateA();
    Context* pContext = new Context(pState);

    pContext->Request();
    pContext->Request();
    pContext->Request();
    

    delete pContext;

}

int main()
{
    test1();
    getchar();
    return 0;
}


