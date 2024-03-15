## 中介者模式（Mediator Pattern）--- 行为型模式


中介者模式（Mediator Pattern）：用一个中介对象来封装一系列的对象交互。中介者使各对象不需要显式地相互引用，从而使其耦合松散，而且可以独立地改变它们之间的交互。



中介者模式（Mediator Pattern） 是一种行为设计模式，它用于减少对象之间的直接相互依赖，通过引入一个中介者对象来协调对象之间的交互。这样，对象之间的耦合度就被降低了，并且可以独立地改变它们之间的交互方式。

在中介者模式中，通常会有多个同事对象（Colleague），它们之间原本有直接通信，但现在通过中介者对象来间接通信。中介者对象知道如何与每个同事对象通信，并负责协调它们之间的交互。

类图关系：

以下是中介者模式的类图关系（以UML表示）：
```lua
+---------+       +---------+  
| Colleague |<----| Mediator |  
+---------+       +---------+  
   |                  ^  
   |  send()          |  
   |<-----------------+  
   |  receive()  
   v  
+---------+  
| Other   |  
|Colleague|  
+---------+
```

在上面的类图中，Colleague 类表示同事对象，它知道中介者对象的存在，并通过中介者对象与其他同事对象进行通信。Mediator 类是中介者对象，它维护了同事对象之间的通信关系。



下面是一个使用C++11标准实现的中介者模式的示例，其中使用了智能指针来管理对象的生命周期。

首先，我们定义同事类（Colleague）的接口：

```cpp
#include <memory>
#include <string>
#include <iostream>
#include <unordered_map>

class Colleague;
class Mediator {
public:
    virtual ~Mediator() = default;
    
    virtual void registerColleague(const std::string& name, std::shared_ptr<Colleague> colleague) = 0;
    virtual void notify(Colleague* sender, const std::string& message, const std::string& receiverName) = 0;
};

class Colleague {
public:
    virtual ~Colleague() = default;
    
    virtual void send(const std::string& message, const std::string& receiverName) = 0;
    virtual void receive(const std::string& message) = 0;
    
    void setMediator(std::shared_ptr<Mediator> mediator) {
        this->m_mediator = mediator;
    }

protected:
    std::weak_ptr<Mediator> m_mediator;
};

class ConcreteColleague : public Colleague {
public:
    ConcreteColleague(const std::string& name) : name(name) {}
    
    void send(const std::string& message, const std::string& receiverName) override {
        if (auto med = m_mediator.lock()) {
            med->notify(this, message, receiverName);
        }
    }
    
    void receive(const std::string& message) override {
        std::cout << name << " received: " << message << std::endl;
    }

private:
    std::string name;
};

class ConcreteMediator : public Mediator {
public:
    void registerColleague(const std::string& name, std::shared_ptr<Colleague> colleague) override {
        colleagues[name] = colleague;
    }
    
    void notify(Colleague* sender, const std::string& message, const std::string& receiverName) override {
        if (auto receiver = colleagues.find(receiverName); receiver != colleagues.end()) {
            receiver->second->receive(message);
        }
    }

private:
    std::unordered_map<std::string, std::shared_ptr<Colleague>> colleagues;
};

int main() {
    // 创建中介者对象
    std::shared_ptr<ConcreteMediator> mediator = std::make_shared<ConcreteMediator>();
    
    // 创建同事对象，并设置中介者
    std::shared_ptr<ConcreteColleague> colleagueA = std::make_shared<ConcreteColleague>("ColleagueA");
    std::shared_ptr<ConcreteColleague> colleagueB = std::make_shared<ConcreteColleague>("ColleagueB");
    
    colleagueA->setMediator(mediator);
    colleagueB->setMediator(mediator);
    
    // 注册同事到中介者
    mediator->registerColleague("ColleagueA", colleagueA);
    mediator->registerColleague("ColleagueB", colleagueB);
    
    // 同事A通过中介者向同事B发送消息
    colleagueA->send("Hello, ColleagueB!", "ColleagueB");
    
    return 0;
}
```

在这个示例中，我们使用了`std::shared_ptr`来管理中介者和同事对象的生命周期，
并通过`std::weak_ptr`在同事类中持有对中介者的引用，以避免循环引用。

同事类通过调用中介者的`notify`方法来间接地向其他同事发送消息，而不需要知道其他同事的具体实例。中介者通过维护一个

