## 状态模式（State Pattern）--- 行为型模式



状态模式（State Pattern）：允许一个对象在其内部状态改变时改变它的行为。对象看起来好像修改了它的类。





```cpp
#include <iostream>  
#include <string>  
  
// 基类（父类）  
class Animal {  
public:  
    virtual void speak() const {  
        std::cout << "The animal speaks." << std::endl;  
    }  
};  
  
// 派生类（子类）  
class Dog : public Animal {  
public:  
    void speak() const override {  
        std::cout << "The dog barks." << std::endl;  
    }  
};  
  
int main() {  
    // 父类对象  
    Animal animal;  
    animal.speak(); // 输出：The animal speaks.  
  
    // 子类对象  
    Dog dog;  
    dog.speak(); // 输出：The dog barks.  
  
    // 父类指针指向父类对象  
    Animal* animalPtr = &animal;  
    animalPtr->speak(); // 输出：The animal speaks.  
  
    // 父类指针指向子类对象（多态）  
    animalPtr = &dog;  
    animalPtr->speak(); // 输出：The dog barks.  
  
    // 子类指针指向子类对象  
    Dog* dogPtr = &dog;  
    dogPtr->speak(); // 输出：The dog barks.  
  
    return 0;  
}
```

在这个例子中，我们有一个基类Animal和一个派生类Dog。基类Animal有一个虚函数speak()，而派生类Dog重写了这个函数。

 * 1.当我们创建一个Animal对象并通过该对象调用speak()函数时，会执行基类中的speak()函数。

 * 2.当我们创建一个Dog对象并通过该对象调用speak()函数时，会执行派生类中的speak()函数，因为它重写了基类的函数。

 * 3.当我们使用一个Animal类型的指针指向Animal对象并调用speak()函数时，同样会执行基类中的speak()函数。

 * 4.但是，当我们使用同一个Animal类型的指针指向Dog对象并调用speak()函数时，会执行派生类（即Dog类）中的speak()函数。这是因为speak()函数在基类中被声明为virtual，所以当我们通过基类指针调用这个函数时，会执行
  与指针实际指向的对象类型相对应的函数版本。这就是多态的体现。

 * 5.最后，当我们使用Dog类型的指针指向Dog对象并调用speak()函数时，同样会执行派生类中的speak()函数。

运行这段代码，你会看到输出结果与上述解释一致。这个例子展示了多态的基本概念以及如何使用父类指针和子类指针来调用多态函数。



**子类指针不能指向父类对象。**

这是因为子类对象可能包含父类对象没有的额外属性和方法，父类指针无法访问这些额外的成员。如果子类指针指向父类对象，那么在尝试访问子类特有的方法或成员变量时，就会出现非法访问的问题，因为父类对象并没有这些方法和变量。

然而，父类指针可以指向子类对象，这是多态性的一个体现。当父类指针指向子类对象时，只能操作子类从父类中继承过来的数据（包括重写父类的虚函数得到的数据）。这样，就可以通过父类指针来调用子类对象中的方法，实现代码的复用和扩展。
