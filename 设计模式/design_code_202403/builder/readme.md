##  建造者模式 Builder Pattern  --- 创建型模式

建造者模式（Builder Pattern）：将一个复杂对象的构建与它的表示分离，使得同样的构建过程可以创建不同的表示。


### 建造者模式应用场景

 - 对象的创建：Builder模式是为对象的创建而设计的模式
  
 - 创建的是一个复合对象：被创建的对象为一个具有复合属性的复合对象
  
 - 关注对象创建的各部分的创建过程：不同的工厂（这里指builder生成器）对产品属性有不同的创建方法



-----------------
以下内容由chatgpt生成：

prompt:
```
你有20年C++编程经验，精通架构，精通设计模式。
你还是一名优秀的老师。
你详细讲一下 设计模式里面的 建造者模式。
你给出的代码示例，使用C++最新标准，能够用智能指针的地方，要用智能指针。
```


建造者模式是一种创建型设计模式，旨在将一个复杂对象的构建过程与其表示相分离，使得同样的构建过程可以创建不同的表示。这种分离可以让我们更加灵活地组合对象的各种部分，以及独立地修改它们的构建方式，而不必改变其实际构建逻辑。

### 1. 角色

- **Director（指导者）**：负责使用建造者接口来构建产品。指导者决定了构建的步骤和顺序。
- **Builder（建造者）**：定义了构建产品各个部分的接口，具体的建造者实现这些接口来构建和装配产品的各个部分。
- **ConcreteBuilder（具体建造者）**：实现了建造者接口，负责构建和装配具体的产品部件。
- **Product（产品）**：表示被构建的复杂对象。通常包含多个部件。

### 2. 结构

```
         +-------------+
         |   Director  |
         +-------------+
               |
               |
               v
         +-------------+
         |   Builder   |
         +------+------+
                |
       +--------|---------+
       |        |         |
+-------------+  +-------------+
|ConcreteBuilder|  |ConcreteBuilder|
+-------------+  +-------------+
       |                   |
       |                   |
+-------------+  +-------------+
|   Product   |  |   Product   |
+-------------+  +-------------+
```

### 3. 实现示例

让我们通过一个简单的示例来说明建造者模式。假设我们正在设计一个计算机，它有CPU、内存和硬盘等组件。我们希望可以灵活地组装不同配置的计算机，包括高性能和低成本的选项。

```cpp
#include <iostream>
#include <memory>
#include <string>

// 产品类 - 计算机
class Computer {
public:
    void setCPU(const std::string& cpu) {
        m_cpu = cpu;
    }

    void setMemory(const std::string& memory) {
        m_memory = memory;
    }

    void setHardDisk(const std::string& hardDisk) {
        m_hardDisk = hardDisk;
    }

    void show() const {
        std::cout << "Computer Configuration:" << std::endl;
        std::cout << "CPU: " << m_cpu << std::endl;
        std::cout << "Memory: " << m_memory << std::endl;
        std::cout << "Hard Disk: " << m_hardDisk << std::endl;
    }

private:
    std::string m_cpu;
    std::string m_memory;
    std::string m_hardDisk;
};

// 抽象建造者
class Builder {
public:
    virtual void buildCPU() = 0;
    virtual void buildMemory() = 0;
    virtual void buildHardDisk() = 0;
    virtual std::shared_ptr<Computer> getResult() = 0;
};

// 具体建造者A
class HighPerformanceComputerBuilder : public Builder {
public:
    void buildCPU() override {
        m_computer->setCPU("High Performance CPU");
    }

    void buildMemory() override {
        m_computer->setMemory("16GB RAM");
    }

    void buildHardDisk() override {
        m_computer->setHardDisk("512GB SSD");
    }

    std::shared_ptr<Computer> getResult() override {
        return m_computer;
    }

    HighPerformanceComputerBuilder() : m_computer(std::make_shared<Computer>()) {}

private:
    std::shared_ptr<Computer> m_computer;
};

// 具体建造者B
class LowCostComputerBuilder : public Builder {
public:
    void buildCPU() override {
        m_computer->setCPU("Basic CPU");
    }

    void buildMemory() override {
        m_computer->setMemory("8GB RAM");
    }

    void buildHardDisk() override {
        m_computer->setHardDisk("256GB HDD");
    }

    std::shared_ptr<Computer> getResult() override {
        return m_computer;
    }

    LowCostComputerBuilder() : m_computer(std::make_shared<Computer>()) {}

private:
    std::shared_ptr<Computer> m_computer;
};

// 指导者
class Director {
public:
    std::shared_ptr<Computer> buildComputer(Builder& builder) {
        builder.buildCPU();
        builder.buildMemory();
        builder.buildHardDisk();
        return builder.getResult();
    }
};

int main() {
    Director director;

    HighPerformanceComputerBuilder highPerformanceBuilder;
    auto highPerformanceComputer = director.buildComputer(highPerformanceBuilder);
    highPerformanceComputer->show();

    LowCostComputerBuilder lowCostBuilder;
    auto lowCostComputer = director.buildComputer(lowCostBuilder);
    lowCostComputer->show();

    return 0;
}
```

在这个示例中，`Computer`是产品类，表示被构建的计算机。`Builder`是抽象建造者，定义了构建计算机各个部件的接口。`HighPerformanceComputerBuilder`和`LowCostComputerBuilder`是具体建造者，它们分别实现了构建不同配置计算机的具体逻辑。`Director`是指导者，负责调用具体建造者的方法来构建产品。

通过建造者模式，我们可以轻松地创建不同配置的计算机，而不必关心每个部件的具体构建过程，也不必修改客户端代码。