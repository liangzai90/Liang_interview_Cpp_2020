
#include <iostream>
#include "chain_of_responsibility.h"
using namespace std;

void test1(){
    Handler* p1 = new ConcreateHandler1();
    cout << "-------------------------" << endl;

    Handler* p2 = new ConcreateHandler2();
    cout << "-------------------------" << endl;

    Handler* p3 = new ConcreateHandler3(p2);
    cout << "-------------------------" << endl;

    Handler* p4 = new ConcreateHandler4(p3);
    cout << "-------------------------" << endl;

    p4->HandleRequest();

    delete p1;
    delete p4;

}

int main()
{
    test1();
    getchar();
    return 0;
}


