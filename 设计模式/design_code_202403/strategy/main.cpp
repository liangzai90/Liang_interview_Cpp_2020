
#include <iostream>
#include "strategy.h"
using namespace std;

void test1(){
   Strategy* pStrategy = new ConcreateStrategyA();
   Context* pContext = new Context(pStrategy);

   pContext->ContextInterface();

   delete pContext;
}

int main()
{
    test1();
    getchar();
    return 0;
}


