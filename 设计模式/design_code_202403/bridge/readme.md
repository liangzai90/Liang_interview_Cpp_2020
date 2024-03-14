## 桥接模式 Bridge Pattern


Bridge 模式又叫做桥接模式，是构造型的设计模式之一。

Bridge模式基于类的最小设计原则，通过使用封装，聚合以及继承等行为来让不同的类承担不同的责任。
它的主要特点是把抽象（abstraction）与行为实现（implementation）分离开来，
从而可以保持各部分的独立性以及应对它们的功能扩展。


### 桥接模式的角色和职责

 * Client    
    Bridge模式的使用者

 * Abstraction
    抽象类接口（接口或抽象类）
    维护对行为实现（Implementor）的引用

 * Refined Abstraction
    Abstraction子类

 * Implementor
    行为实现类接口 (Abstraction接口定义了基于Implementor接口的更高层次的操作)

 * ConcreteImplementor
    Implementor子类





-------------------------

以下内容由chatgpt生成：

桥接模式是一种结构型设计模式，用于将抽象部分与其实现部分分离，使它们可以独立地变化。这种模式涉及到一个作为桥梁的接口，使得抽象部分和实现部分可以独立地变化而互不影响。

### 模式结构

 * 抽象部分（Abstraction）：定义抽象类的接口，它维护一个指向实现部分对象的引用。

 * 扩充抽象类（Refined Abstraction）：扩展抽象类，通过调用实现部分的方法来实现业务逻辑。

 * 实现部分（Implementor）：定义实现类的接口，该接口不一定与抽象类接口完全一致。

 * 具体实现类（Concrete Implementor）：实现实现部分的接口，并完成具体业务逻辑。

### 模式实现

下面是一个简单的 C++ 示例来说明桥接模式：

```cpp
#include <iostream>

// 实现部分接口
class Implementor {
public:
    virtual void operationImpl() const = 0;
    virtual ~Implementor() {}
};

// 具体实现类 A
class ConcreteImplementorA : public Implementor {
public:
    void operationImpl() const override {
        std::cout << "Concrete Implementor A operation\n";
    }
};

// 具体实现类 B
class ConcreteImplementorB : public Implementor {
public:
    void operationImpl() const override {
        std::cout << "Concrete Implementor B operation\n";
    }
};

// 抽象类
class Abstraction {
protected:
    Implementor* implementor;
public:
    Abstraction(Implementor* impl) : implementor(impl) {}
    virtual void operation() const = 0;
    virtual ~Abstraction() {}
};

// 扩充抽象类
class RefinedAbstraction : public Abstraction {
public:
    RefinedAbstraction(Implementor* impl) : Abstraction(impl) {}
    void operation() const override {
        std::cout << "Refined Abstraction: ";
        implementor->operationImpl();
    }
};

int main() {
    Implementor* implA = new ConcreteImplementorA();
    Abstraction* absA = new RefinedAbstraction(implA);
    absA->operation();

    Implementor* implB = new ConcreteImplementorB();
    Abstraction* absB = new RefinedAbstraction(implB);
    absB->operation();

    delete implA;
    delete absA;
    delete implB;
    delete absB;

    return 0;
}
```


### 模式应用场景

 * 当一个类存在多个独立变化的维度时，可以使用桥接模式来避免类爆炸。

 * 当需要在抽象和具体实现之间增加更多的灵活性时，可以使用桥接模式。

 * 当一个类需要使用不同的实现来完成其功能时，桥接模式是一个不错的选择。

## 模式优缺点

### 优点：
 * 分离抽象部分及其实现部分。
 * 提高了系统的可扩展性。
 * 符合开闭原则。

### 缺点：
 * 增加了系统的复杂度。
 * 不容易理解和实现。

桥接模式是一种强大的设计模式，可以帮助我们更好地管理复杂系统中的变化和扩展。

