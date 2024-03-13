#include <iostream>
#include "singleton.h"


void Test1(){
    // 获取单例实例的引用 
    Singleton& instance1 = Singleton::getInstance();   
    instance1.SetValue(123);

    // 获取单例实例
    Singleton& instance2 = Singleton::getInstance();  
    instance2.SetValue(456);


    instance1.Print();
    instance2.Print(); 
}

int main() {
    Test1();

    getchar();
    return 0;
}