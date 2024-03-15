## 职责链模式（Chain of Responsibility Pattern）--- 行为型模式


职责链模式（Chain of Responsibility Pattern）：使多个对象都有机会处理请求，从而避免请求的发送者和接收者之间的耦合关系。将这些对象连成一条链，并沿着这条链传递该请求，直到有一个对象处理它为止。




------------------------
以下内容由 文心一言 生成


职责链模式（Chain of Responsibility Pattern）是一种行为设计模式，它允许你将请求沿着对象链进行传递。这条链上的每一个对象均包含对另一个对象的引用，而当一个对象不能处理该请求时，它会将该请求传给链中的下一个对象。


职责链模式涉及的关键组件包括：

 * 抽象处理者（Handler）：定义一个处理请求的接口。通常包含一个后继处理者的引用和一个处理请求的方法。
 * 具体处理者（Concrete Handler）：实现抽象处理者的接口，处理它所负责的请求；如果不能处理，则将请求转发给后继者。
 * 客户端（Client）：发起请求的起点。


下面是一个使用C++实现的职责链模式的简单示例，其中使用了智能指针和C++11及以后的特性。


```cpp
#include <iostream>  
#include <memory>  
  
class Handler {  
public:  
    using Ptr = std::shared_ptr<Handler>;  
  
    Handler() = default;  
    virtual ~Handler() = default;  
  
    virtual void SetNext(Handler::Ptr next) {  
        next_ = next;  
    }  
  
    virtual void HandleRequest(int request) const {  
        if (next_) {  
            next_->HandleRequest(request);  
        }  
    }  
  
protected:  
    virtual bool CanHandle(int request) const = 0;  
    virtual void ProcessRequest(int request) const = 0;  
  
private:  
    Handler::Ptr next_;  
};

class ConcreteHandlerA : public Handler {  
public:  
    void HandleRequest(int request) const override {  
        if (CanHandle(request)) {  
            ProcessRequest(request);  
        } else {  
            Handler::HandleRequest(request);  
        }  
    }  
  
private:  
    bool CanHandle(int request) const override {  
        return request >= 0 && request < 10;  
    }  
  
    void ProcessRequest(int request) const override {  
        std::cout << "ConcreteHandlerA handled request: " << request << std::endl;  
    }  
};  
  
class ConcreteHandlerB : public Handler {  
public:  
    void HandleRequest(int request) const override {  
        if (CanHandle(request)) {  
            ProcessRequest(request);  
        } else {  
            Handler::HandleRequest(request);  
        }  
    }  
  
private:  
    bool CanHandle(int request) const override {  
        return request >= 10 && request < 20;  
    }  
  
    void ProcessRequest(int request) const override {  
        std::cout << "ConcreteHandlerB handled request: " << request << std::endl;  
    }  
};  
  
class ConcreteHandlerC : public Handler {  
public:  
    void HandleRequest(int request) const override {  
        if (CanHandle(request)) {  
            ProcessRequest(request);  
        } else {  
            Handler::HandleRequest(request);  
        }  
    }  
  
private:  
    bool CanHandle(int request) const override {  
        return request >= 20;  
    }  
  
    void ProcessRequest(int request) const override {  
        std::cout << "ConcreteHandlerC handled request: " << request << std::endl;  
    }  
};


int main() {  
    Handler::Ptr handlerA = std::make_shared<ConcreteHandlerA>();  
    Handler::Ptr handlerB = std::make_shared<ConcreteHandlerB>();  
    Handler::Ptr handlerC = std::make_shared<ConcreteHandlerC>();  
  
    handlerA->SetNext(handlerB);  
    handlerB->SetNext(handlerC);  
  
    // 发起请求  
    handlerA->HandleRequest(2); // 由 ConcreteHandlerA 处理  
    handlerA->HandleRequest(15); // 由 ConcreteHandlerB 处理  
    handlerA->HandleRequest(25); // 由 ConcreteHandlerC 处理  
    handlerA->HandleRequest(30); // 
  
    return 0;  
}
```




上面的描述，类图关系可以大致描述如下：
```lua
+----------------+  
       |   Handler    |  
       +----------------+  
       |  + SetNext() |  
       |  + HandleRequest() |  
       |  + CanHandle() |  
       |  + ProcessRequest() |  
       +----------------+  
             ^    |  
             |    |  
             |    +----------------+  
             |    | ConcreteHandlerA |  
             |    +----------------+  
             |  
             |    +----------------+  
             +----| ConcreteHandlerB |  
             |    +----------------+  
             |  
             |    +----------------+  
             +----| ConcreteHandlerC |  
                  +----------------+
```

在这个类图中，Handler 是一个抽象类，它定义了 SetNext 方法来设置下一个处理者，HandleRequest 方法来处理请求，CanHandle 方法来判断是否能处理请求，以及 ProcessRequest 方法来实际处理请求。

ConcreteHandlerA、ConcreteHandlerB 和 ConcreteHandlerC 是 Handler 的具体实现，它们重写了 CanHandle 和 ProcessRequest 方法来定义自己的处理逻辑。

客户端代码创建这些处理者的实例，并通过 SetNext 方法将它们链接起来形成职责链。然后，客户端通过调用链中第一个处理者的 HandleRequest 方法来发起请求。

在C++中，使用智能指针（如 std::shared_ptr）来管理对象的生命周期是一个好的实践，这可以确保在不再需要对象时它们会被正确地删除，从而避免内存泄漏。在上面的示例中，我们使用了 std::shared_ptr 来存储处理者的指针，并在链中传递它们。

请注意，上面的代码示例和类图是一个简单的演示，实际应用中可能需要更复杂的逻辑和更多的考虑，比如错误处理、日志记录、性能优化等。此外，职责链模式可以与其他设计模式结合使用，以构建更灵活和可维护的系统。