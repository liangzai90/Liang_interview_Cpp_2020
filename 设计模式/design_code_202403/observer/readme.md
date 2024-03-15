## 观察者模式（Observer Pattern） --- 行为型模式


观察者模式（Observer Pattern）：定义对象之间的一对多依赖关系，以便当一个对象改变状态时，它的所有依赖者都会收到通知并自动更新。


观察者模式（Observer Pattern）是一种行为设计模式，它允许对象之间定义一对多的依赖关系，当一个对象状态发生改变时，它的所有依赖者都会收到通知并自动更新。这种模式在软件开发中非常常见，特别是在需要实现事件驱动或发布/订阅模型时。

### 观察者模式的参与者包括：

 * Subject（主题）：维护一个观察者列表，当状态发生改变时，通知所有观察者。
 * Observer（观察者）：为那些在主题状态发生改变时需要得到通知的对象定义一个接口。
 * ConcreteSubject（具体主题）：实现 Subject 接口，维护观察者列表，当状态发生改变时，遍历列表并通知每个观察者。
 * ConcreteObserver（具体观察者）：实现 Observer 接口，并在接到通知时更新自身状态。


### 以下是观察者模式的类图关系：

```lua
+----------------+     +----------------+  
   |  Observer    |-----|  Subject   |  
   +----------------+     +------------+  
   | update(state) |     | register() |  
   |------------------|     | unregister() |  
   |                |     | notify()     |  
   +----------------+     +------------+  
  
   +----------------------+     +----------------------+  
   | ConcreteObserverA  |     | ConcreteSubject  |  
   +----------------------+     +----------------------+  
   |                    |     |                    |  
   | update(state)      |     | register(Observer) |  
   |----------------------|     | unregister(Observer) |  
   |                    |     | notifyObservers()  |  
   |     state          |     |----------------------|  
   |                    |     |  observersList   |  
   +----------------------+     +----------------------+
```

在这个类图中，Observer 和 Subject 是接口，ConcreteObserverA 是一个实现了 Observer 接口的具体观察者类，ConcreteSubject 是一个实现了 Subject 接口的具体主题类。
ConcreteSubject 维护了一个观察者列表 observersList，并提供了注册、注销和通知观察者的方法。




###  注意死锁

```txt 
registerObserver
unregisterObserver
notifyObservers
setState

这几个函数里面都定义了lock_guard，因此这几个函数不能嵌套。否则必定会死锁！！！
  比如 setState 里面调用了 notifyObservers，那么就会产生死锁。
```

```cpp
#include <iostream>  
#include <vector>  
#include <memory>  
#include <mutex>  
#include <thread> 
#include <algorithm> 
  
// Observer 接口  
class Observer {  
public:  
    virtual ~Observer() = default;  
    virtual void update(const std::string& state) = 0;  
};  
  
// Subject 接口  
class Subject {  
public:  
    virtual ~Subject() = default;  
    virtual void registerObserver(std::shared_ptr<Observer> observer) = 0;  
    virtual void unregisterObserver(std::shared_ptr<Observer> observer) = 0;  
    virtual void notifyObservers(const std::string& state) = 0;  
    virtual void setState(const std::string& state) = 0;  
};  
  
// ConcreteObserver 类  
class ConcreteObserver : public Observer {  
public:  
    ConcreteObserver(const std::string& name) : name_(name) {}  
    void update(const std::string& state) override {  
        std::cout << name_ << " received state: " << state << std::endl;  
    }  
  
private:  
    std::string name_;  
};  
  
// ConcreteSubject 类  
class ConcreteSubject : public Subject {  
public:  
    void registerObserver(std::shared_ptr<Observer> observer) override {  
        std::lock_guard<std::mutex> lock(mutex_);  
        observers_.push_back(observer);  
    }  
  
    void unregisterObserver(std::shared_ptr<Observer> observer) override {  
        std::lock_guard<std::mutex> lock(mutex_);  
        auto it = std::find(observers_.begin(), observers_.end(), observer);  
        if (it != observers_.end()) {  
            observers_.erase(it);  
        }  
    }  
  
    void notifyObservers(const std::string& state) override {  
        std::lock_guard<std::mutex> lock(mutex_);  
        for (const auto& observer : observers_) {  
            observer->update(state);  
        }  
    }  
  
    void setState(const std::string& state) {  
        std::lock_guard<std::mutex> lock(mutex_);  
        state_ = state;  
       
    }  
  
private:  
    std::vector<std::shared_ptr<Observer>> observers_;  
    std::string state_;  
    std::mutex mutex_;  
};  
  
// 示例使用  
int main() {  
    std::shared_ptr<ConcreteSubject> subject = std::make_shared<ConcreteSubject>();  
    std::shared_ptr<Observer> observer1 = std::make_shared<ConcreteObserver>("Observer1");  
    std::shared_ptr<Observer> observer2 = std::make_shared<ConcreteObserver>("Observer2");  
  
    subject->registerObserver(observer1);  
    subject->registerObserver(observer2);  
  
    // 模拟多线程环境  
    std::thread t1([&]() {  
        subject->setState("State from thread 1");  
        subject->notifyObservers("State from thread 1");  
    });  

    std::thread t2([&]() {
        std::this_thread::sleep_for(std::chrono::seconds(1)); // 假设第二个线程稍微延迟一点
    subject->setState("State from thread 2");
    subject->notifyObservers("State from thread 2");  
    });

t1.join();  
t2.join();  

// 注销观察者  
subject->unregisterObserver(observer1);  

// 再次改变状态，这次 observer1 不应该收到通知  
subject->setState("State from main thread");  

return 0;
}

// g++ observer.cpp -o obser -std=c++11 -lpthread -g

```

在上面的代码中，`ConcreteSubject` 使用了 `std::mutex` 来确保线程安全地管理观察者列表和状态更新。每个 `setState` 调用都会锁定互斥锁，然后更新状态并通知所有注册的观察者。在 `registerObserver` 和 `unregisterObserver` 方法中也使用了互斥锁来确保观察者列表的线程安全操作。  
  
`main` 函数中，我们创建了一个 `ConcreteSubject` 实例和两个 `ConcreteObserver` 实例，并在两个线程中分别改变主题的状态。由于使用了互斥锁，我们可以确保观察者列表和状态更新的线程安全。最后，我们注销了其中一个观察者，并再次改变状态，以演示注销后的观察者不再收到通知。  
  
请注意，上面的代码示例是一个简化的版本，实际项目中可能需要更复杂的线程同步机制来处理更多的并发场景，例如使用条件变量、读写锁等。此外，还需要注意智能指针的使用，以确保对象生命周期的正确管理，避免内存泄漏或野指针的问题。





### lock_guard 介绍

std::lock_guard 是 C++ 标准库中的一个模板类，它简化了对互斥量（mutex）的锁定和解锁操作。
使用 std::lock_guard 可以确保互斥量在构造时自动锁定，并在析构时自动解锁，即使在异常发生时也是如此。这种自动管理可以减少因忘记解锁互斥量而导致的死锁或其他并发问题。

下面是一个使用 std::lock_guard 的简单示例：

```cpp
#include <iostream>  
#include <thread>  
#include <mutex>  
  
std::mutex mtx;  // 定义一个互斥量  
  
void print_block(int n, char c) {  
    std::lock_guard<std::mutex> lock(mtx);  // 使用lock_guard自动锁定互斥量  
    for (int i = 0; i < n; ++i) { std::cout << c; }  
    std::cout << '\n';  
}  
  
int main() {  
    std::thread th1(print_block, 50, '*');  
    std::thread th2(print_block, 50, '$');  
  
    th1.join();  
    th2.join();  
  
    return 0;  
}
```

在这个示例中，我们定义了一个全局的互斥量 mtx。print_block 函数接受一个整数 n 和一个字符 c，并使用 std::lock_guard 来确保在打印字符块时，互斥量 mtx 被锁定。我们创建了两个线程 th1 和 th2，它们分别调用 print_block 函数来打印星号 * 和美元符号 $。由于 std::lock_guard 的存在，这两个线程会顺序地打印字符块，而不会交替打印，从而避免了输出混乱。

需要注意的是，std::lock_guard 的构造函数会锁定互斥量，而析构函数会解锁互斥量。因此，当 print_block 函数返回时，std::lock_guard 对象 lock 会被销毁，从而自动解锁互斥量 mtx。这种自动管理可以确保即使在发生异常时，互斥量也会被正确解锁。



-----------------------------------

## lock_guard 与 std::unique_lock 的区别

std::lock_guard 和 std::unique_lock 都是 C++ 标准库中的锁类型，用于管理互斥量（mutexes）的锁定和解锁。
它们的主要目的是确保在作用域结束时自动释放锁，以避免因忘记解锁而导致的死锁问题。
然而，它们之间有几个关键的区别：

### std::lock_guard

std::lock_guard 是一个简单的 RAII（Resource Acquisition Is Initialization）风格的锁包装器。它在构造时获取锁，并在析构时释放锁。这意味着你无法手动控制锁的获取和释放；它们自动发生在对象的生命周期的开始和结束。

### 优点：

 * 简单易用：无需手动调用 lock() 或 unlock()。
 * 安全：自动管理锁的生命周期，减少死锁的风险。

### 缺点：

 * 灵活性有限：无法手动控制锁的获取和释放时机。

### std::unique_lock
std::unique_lock 提供了比 std::lock_guard 更多的灵活性。它允许你延迟锁定、尝试锁定、解锁以及手动控制锁的生命周期。

### 优点：

 * 灵活性：可以手动控制锁的获取和释放。
 
可用于复杂的同步场景，如条件变量、递归锁等。

### 缺点：

 * 复杂性：由于有更多的控制选项，因此代码可能更复杂，也更容易出错。

### 使用场景
std::lock_guard：适用于简单的场景，其中你希望在对象的整个生命周期中持有锁，并且不需要手动控制锁的获取和释放。
std::unique_lock：适用于需要更精细控制锁的场景，如需要在某个特定点解锁，或者与条件变量一起使用。


### 示例代码

std::lock_guard

```cpp
std::mutex mtx;  
  
void safe_increment() {  
    std::lock_guard<std::mutex> lock(mtx);  
    // 在这里安全地访问共享资源  
}

```

std::unique_lock

```cpp
std::mutex mtx;  
std::condition_variable cv;  
bool ready = false;  
  
void wait_for_signal() {  
    std::unique_lock<std::mutex> lock(mtx);  
    while (!ready) { // 可能需要多次检查条件  
        cv.wait(lock); // 释放锁并等待条件成立，条件成立时自动重新获取锁  
    }  
    // 在这里处理信号  
}
```

在上面的 std::unique_lock 示例中，cv.wait(lock) 会释放锁，允许其他线程获取锁并修改 ready 的值。当条件成立时（即 ready 变为 true），wait 函数会自动重新获取锁，然后代码继续执行。这种灵活性是 std::lock_guard 无法提供的。





