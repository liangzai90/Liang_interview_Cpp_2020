
#include <iostream>
#include "iterator.h"
using namespace std;

void test1(){
    Aggregate* pAggregate = new ConcreateAggregate(4);
    Iterater* pIterater = new ConcreateIterater(pAggregate);

    for (; false == pIterater->IsDone(); pIterater->Next())
    {
        cout << pIterater->CurrentItem() << endl;
    }

}

int main()
{
    test1();
    getchar();
    return 0;
}


