
#include <iostream>
#include "flyweight.h"
using namespace std;

void test1(){
    FlyweightFactory flyweightfactory;
    flyweightfactory.GetFlyweight("Hello");
    flyweightfactory.GetFlyweight("--world--");
    flyweightfactory.GetFlyweight("==hello==");
    flyweightfactory.GetFlyweight("Hello");
}

int main()
{
    test1();
    getchar();
    return 0;
}


