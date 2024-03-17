#include <iostream>
#include "xthread_pool.h"

void Test1(){
    XThreadPool pool;
    pool.Init(10);
    pool.Start();
}
int main(){

    Test1();
    getchar();
    return 0;
}