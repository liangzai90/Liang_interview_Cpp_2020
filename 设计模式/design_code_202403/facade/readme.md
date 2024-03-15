## 外观模式（Facade Pattern）--- 结构型模式

外观模式（Facade Pattern）：为子系统中的一组接口提供了一个统一的接口，外观模式定义了一个高层接口，这个接口使得这一子系统更加容易使用。

在外观模式中，外观类对子系统中的一组接口进行了封装，降低了子系统与客户端之间的耦合度。
客户端只需要与外观类进行交互，而不需要了解子系统的具体实现细节。
这样，当子系统内部发生变化时，只要外观类的接口保持不变，客户端代码就不需要修改。

下面是一个使用C++17实现的外观模式的示例，并附带了类图关系：

类图关系

```lua
+----------------+  
              |  SubsystemA  |  
              +--------+-----+  
                      |  
                      |  
+----------------+      |      +----------------+  
|  Facade      |------|     |  SubsystemB  |  
+--------+-----+      |      +--------+-----+  
      ^  |            |              ^  |  
      |  |            |              |  |  
      |  +------------+              |  +------------+  
      |                                |  
      |                                |  
+-----v-+                          +--v-+-----+  
| Client |                          | Other |  
+--------+                          +-------+
```

在这个类图中，SubsystemA 和 SubsystemB 是子系统的两个组件，它们各自提供了一些功能。Facade 类是外观类，它封装了与 SubsystemA 和 SubsystemB 的交互，并提供了简化的接口给 Client 使用。Client 和 Other 类是子系统的客户端，它们通过 Facade 类来与子系统交互。

代码示例

```cpp
#include <iostream>  
#include <memory>  
  
// 子系统A  
class SubsystemA {  
public:  
    void operationA() {  
        std::cout << "SubsystemA operationA()" << std::endl;  
    }  
};  
  
// 子系统B  
class SubsystemB {  
public:  
    void operationB() {  
        std::cout << "SubsystemB operationB()" << std::endl;  
    }  
};  
  
// 外观类  
class Facade {  
public:  
    Facade() : subA(std::make_unique<SubsystemA>()), subB(std::make_unique<SubsystemB>()) {}  
  
    void unifiedOperation() {  
        subA->operationA();  
        subB->operationB();  
    }  
  
private:  
    std::unique_ptr<SubsystemA> subA;  
    std::unique_ptr<SubsystemB> subB;  
};  
  
// 客户端代码  
int main() {  
    std::unique_ptr<Facade> facade = std::make_unique<Facade>();  
    facade->unifiedOperation(); // 客户端只需要调用外观类的接口  
  
    return 0;  
}
```

在这个示例中，SubsystemA 和 SubsystemB 是两个子系统组件，它们各自有一个方法。Facade 类封装了这两个子系统的操作，并提供了一个 unifiedOperation 方法供客户端调用。在 main 函数中，客户端通过智能指针创建了一个 Facade 对象，并调用了其 unifiedOperation 方法，从而间接地调用了子系统的操作。

外观模式的主要优点是简化了子系统的使用，降低了客户端与子系统的耦合度，使得子系统更加易于维护和扩展。同时，通过使用智能指针，我们确保了资源的自动管理，避免了内存泄漏等问题。