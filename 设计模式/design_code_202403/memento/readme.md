## 备忘录模式（Memento Pattern）--- 行为型模式


备忘录模式（Memento Pattern）：在不破坏封装性的前提下，捕获一个对象的内部状态，并在对象之外保存这个状态。这样以后就可将该对象恢复到原先保存的状态。



----------------------------
以下内容由 文心一言 生成

备忘录模式（Memento Pattern）是一种行为型设计模式，它允许在不破坏封装性的前提下捕获一个对象的内部状态，并在之后将该对象恢复到原先保存的状态。这种模式提供了一种恢复状态的机制，使得用户能够方便地返回到某一历史状态，同时无需暴露对象的内部实现细节。

备忘录模式主要包含三个角色：

发起人（Originator）：记录当前时刻它的内部状态，并可使用备忘录恢复到之前的状态。

备忘录（Memento）：负责存储发起人对象的内部状态，并可防止发起人以外的其他对象访问备忘录。备忘录通常需要根据发起人的内部状态来定制。

管理者（Caretaker）：负责保存好备忘录，不能对备忘录的内容进行操作或检查。

下面是备忘录模式的类图关系：
```lua
+----------------+       +----------------+  
|  Originator  |------->   Memento   |  
+----------------+       +----------------+  
|   -state     |       |   -state    |  
| +createMemento|       +------------+  
| +setMemento   |  
| +restoreMemento|  
+----------------+  
  
      ^  
      |  
      |  
+----------------+  
|  Caretaker   |  
+----------------+  
|   -memento   |  
| +addMemento  |  
| +getMemento  |  
+----------------+
```
在这个类图中，Originator 类有一个内部状态 state，并提供了创建备忘录（createMemento）、设置备忘录（setMemento）和恢复状态（restoreMemento）的方法。Memento 类存储了 Originator 的状态。Caretaker 类负责管理备忘录，它存储了备忘录对象，并提供了添加（addMemento）和获取（getMemento）备忘录的方法。

下面是一个使用C++11标准实现的备忘录模式的代码示例：

```cpp
#include <iostream>  
#include <string>  
#include <memory>  
#include <vector>  
  
// 备忘录  
class Memento {  
public:  
    explicit Memento(const std::string& state) : state_(state) {}  
    std::string getState() const { return state_; }  
  
private:  
    std::string state_;  
};  
  
// 发起人  
class Originator {  
public:  
    void setState(const std::string& state) { state_ = state; }  
    std::string getState() const { return state_; }  
    std::unique_ptr<Memento> createMemento() const {  
        return std::make_unique<Memento>(state_);  
    }  
    void setMemento(const std::unique_ptr<Memento>& memento) {  
        state_ = memento->getState();  
    }  
  
private:  
    std::string state_;  
};  
  
// 管理者  
class Caretaker {  
public:  
    void addMemento(std::unique_ptr<Memento> memento) {  
        mementos_.push_back(std::move(memento));  
    }  
    std::unique_ptr<Memento> getMemento(size_t index) {  
        if (index < mementos_.size()) {  
            return std::move(mementos_[index]);  
        }  
        return nullptr;  
    }  
  
private:  
    std::vector<std::unique_ptr<Memento>> mementos_;  
};  
  
int main() {  
    Originator originator;  
    Caretaker caretaker;  
  
    // 发起人设置状态  
    originator.setState("State 1");  
    std::cout << "Current state: " << originator.getState() << std::endl;  
  
    // 发起人创建备忘录并交给管理者保存  
    caretaker.addMemento(originator.createMemento());  
  
    // 发起人改变状态  
    originator.setState("State 2");  
    std::cout << "Changed state: " << originator.getState() << std::endl;  
  
    // 发起人从管理者处取得先前保存的备忘录，并恢复状态  
    originator.setMemento(caretaker.getMemento(0));  
    std::cout << "Restored state: " << originator.getState() << std::endl;  
  
    return 0;  
}
```

在这个示例中，Originator 类有一个 state_ 成员变量来存储其状态，它提供了 setState 和 getState 方法来修改和获取状态。createMemento 方法用于创建一个包含当前状态的 Memento 对象。setMemento 方法则用于恢复先前保存的状态。

`
