## 迭代器模式（Iterator Pattern） --- 行为型模式


迭代器模式（Iterator Pattern）：它提供一种方法顺序访问一个聚合对象中各个元素，而又不需暴露该对象的内部表示。






---------------------------
以下内容由 文心一言 生成

迭代器模式（Iterator Pattern）是设计模式中的一种行为型模式，它提供了一种顺序访问一个聚合对象中各个元素，而又不需要暴露该对象的内部表示的方法。迭代器模式使得我们能够支持对聚合对象的多种遍历，同时又不需要改变这些对象的内部结构。

迭代器模式主要包含以下几个角色：

迭代器（Iterator）：定义访问和遍历元素的接口。
具体迭代器（ConcreteIterator）：实现迭代器接口，并跟踪遍历中的当前位置。
聚合（Aggregate）：定义创建迭代器对象的接口。
具体聚合（ConcreteAggregate）：实现聚合接口，返回具体迭代器的实例。
类图关系
以下是迭代器模式的类图关系：

+----------------+     +-----------------+  
|    Iterator    |---->| ConcreteIterator |  
+----------------+     +-----------------+  
| + next()       |     | + next()       |  
| + hasNext()    |     | + hasNext()    |  
| + currentItem()|     | + currentItem()|  
+----------------+     | + constructor()  |  
                      +-----------------+  
  
+-----------------+     +-------------------+  
|  Aggregate    |---->| ConcreteAggregate |  
+-----------------+     +-------------------+  
| + createIterator() |     | + createIterator() |  
+-----------------+     | + items           |  
                      +-------------------+
在这个类图中，Iterator 是迭代器接口，定义了遍历聚合对象所需的方法。ConcreteIterator 是具体迭代器，实现了迭代器接口，并持有对具体聚合对象的引用，以遍历其元素。Aggregate 是聚合接口，定义了创建迭代器的方法。ConcreteAggregate 是具体聚合，实现了聚合接口，并包含了需要遍历的元素集合。

C++代码示例（使用C++11智能指针）

```cpp
#include <iostream>  
#include <vector>  
#include <memory>  
  
// 迭代器接口  
class Iterator {  
public:  
    virtual ~Iterator() = default;  
    virtual bool hasNext() const = 0;  
    virtual void next() = 0;  
    virtual int currentItem() const = 0;  
};  
  
// 具体迭代器  
class ConcreteIterator : public Iterator {  
private:  
    std::vector<int>::const_iterator it;  
    const std::vector<int>* aggregate;  
  
public:  
    ConcreteIterator(const std::vector<int>& agg) : aggregate(&agg), it(agg.begin()) {}  
  
    bool hasNext() const override {  
        return it != aggregate->end();  
    }  
  
    void next() override {  
        ++it;  
    }  
  
    int currentItem() const override {  
        return *it;  
    }  
};  
  
// 聚合接口  
class Aggregate {  
public:  
    virtual ~Aggregate() = default;  
    virtual std::unique_ptr<Iterator> createIterator() const = 0;  
};  
  
// 具体聚合  
class ConcreteAggregate : public Aggregate {  
private:  
    std::vector<int> items;  
  
public:  
    void addItem(int item) {  
        items.push_back(item);  
    }  
  
    std::unique_ptr<Iterator> createIterator() const override {  
        return std::make_unique<ConcreteIterator>(items);  
    }  
};  
  
int main() {  
    // 创建一个具体聚合对象并添加元素  
    ConcreteAggregate aggregate;  
    aggregate.addItem(1);  
    aggregate.addItem(2);  
    aggregate.addItem(3);  
  
    // 创建迭代器并遍历聚合对象  
    std::unique_ptr<Iterator> iterator = aggregate.createIterator();  
    while (iterator->hasNext()) {  
        std::cout << iterator->currentItem() << " ";  
        iterator->next();  
    }  
    std::cout << std::endl;  
  
    return 0;  
}
```

在这个示例中，我们使用了C++11的智能指针 std::unique_ptr 来管理迭代器的生命周期。ConcreteIterator 类持有一个指向 std::vector<int> 的常量迭代器，并提供了遍历聚合对象中元素的方法。ConcreteAggregate 类包含了 std::vector<int> 类型的成员变量 items，用于存储元素，并实现了 createIterator 方法来创建并返回具体迭代器的实例。

在 main 函数中，我们创建了一个 ConcreteAggregate 对象，向其添加了一些元素，然后创建了一个迭代器并遍历了聚合对象中的元素。通过迭代器模式，我们能够在不改变聚合对象内部结构的情况下，以一种统一的方式遍历聚合对象中的元素。

