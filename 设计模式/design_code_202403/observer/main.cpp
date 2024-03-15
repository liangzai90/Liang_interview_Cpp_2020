
#include <iostream>
#include "observer.h"
using namespace std;

void test1(){
    Observer* p1 = new ConcreateObserver();
    Observer* p2 = new ConcreateObserver();

    Subject* p = new ConcreateSubject();
    p->Attach(p1);
    p->Attach(p2);
    p->SetState(4);
    p->Notify();

    p->Detach(p1);
    p->SetState(10);
    p->Notify();

    delete p;

}

int main()
{
    test1();
    getchar();
    return 0;
}


