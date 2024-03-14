## 适配器模式 (Adapter Pattern)---结构型模式

适配器模式（Adapter Pattern）：将一个类的接口转换成客户期望的另一个接口。适配器模式使得原本由于接口不兼容而无法协同工作的类可以一起工作。


### 适配器模式应用场景

在大规模的系统开发过程中，我们常常碰到诸如以下这些情况：

我们需要实现某些功能，这些功能已有还不太成熟的一个或多个外部组件，如果我们自己重新开发这些功能会花费大量时间；

所以很多情况下会选择先暂时使用外部组件，以后再考虑随时替换。

但这样一来，会带来一个问题，随着对外部组件库的替换，可能需要对引用该外部组件的源代码进行大面积的修改，因此也极可能引入新的问题等等。

如何最大限度的降低修改面呢？

Adapter模式就是针对这种类似需求而提出来的。

Adapter模式通过定义一个新的接口（对要实现的功能加以抽象），
和一个实现该接口的Adapter（适配器）类来透明地调用外部组件。

这样替换外部组件时，最多只要修改几个Adapter类就可以了，其他源代码都不会受到影响。



这里要注意 智能指针 的使用方法
```cpp
#include <memory>  // for std::shared_ptr  and  make_shared

std::shared_ptr<Adaptee> pAdaptee = std::make_shared<Adaptee>(); // 这是没有参数的情况
std::shared_ptr<Target> pTarget = std::make_shared<Adapter>(pAdaptee);//()里面是传递的参数
pTarget->Request();
```



-------------
以下内容由大语言模型 文心一言 生成：


适配器模式是一种非常实用且常见的设计模式，它主要用于解决两个软件实体之间由于接口不兼容而无法协同工作的问题。现在，我将为你详细解释适配器模式。

### 一、适配器模式概述
适配器模式（Adapter Pattern）属于结构型设计模式，它允许原本由于接口不兼容而无法协同工作的类可以一起工作。适配器模式将一个类的接口转换成客户端所期望的另一种接口，使得原本由于接口不兼容而无法协同工作的类可以一起工作。

### 二、适配器模式结构
适配器模式主要包含以下三个角色：

 * 目标接口（Target Interface）：客户端所期望的接口。
 * 适配者类（Adaptee Class）：需要被适配的类或者接口。
 * 适配器类（Adapter Class）：实现了目标接口，并将适配者的接口转换为目标接口，使得客户端可以与适配者进行交互。

### 三、适配器模式类型
根据适配器实现方式的不同，适配器模式主要分为两类：

 * 类适配器模式：通过多重继承将适配者类转换成目标接口。
 * 对象适配器模式：通过对象组合的方式将适配者类的对象转换成目标接口。


### 四、适配器模式使用场景

适配器模式通常在以下情况下使用：

 * 当你想使用一个已经存在的类，但是它的接口不符合你的需求时。
 * 当你想创建一个可以复用的类，该类可以与其他不相关的类或不可预见的类（即那些接口可能不一定兼容的类）协同工作时。
 * 当你想使用一个已经存在的子类，但是不可能通过继承来复用该类时。


### 五、适配器模式优缺点

 **优点**：

 * 提高了类的复用性。
 * 增加了类的透明度。
 * 灵活性和扩展性较好。

 **缺点**：

 * 过多使用适配器可能会使系统变得凌乱，不利于维护。
 * 适配器可能会增加系统的复杂性。

### 六、适配器模式示例
假设我们有一个老旧的音频播放器，它只支持MP3格式的音频文件，但现在我们有很多AAC格式的音频文件，我们需要让音频播放器能够播放这些AAC格式的文件。这时，我们可以使用适配器模式来解决问题。

 * 目标接口（Player）：定义了播放音频的方法。
 * 适配者类（AACAudio）：表示AAC格式的音频文件，它有自己的播放方法。
 * 适配器类（AACAdapter）：实现了Player接口，内部持有AACAudio对象，并在播放时调用AACAudio的播放方法。


客户端代码只需要与Player接口交互，而不需要关心具体的音频格式。适配器类AACAdapter负责将AAC格式的音频文件适配为Player接口所期望的格式。

### 七、总结
适配器模式是一种非常实用的设计模式，它可以帮助我们解决接口不兼容的问题，提高代码的复用性和灵活性。在实际开发中，我们可以根据具体的需求选择使用类适配器模式或对象适配器模式，以达到最佳的效果。




----------------------

以下内容由 chatgpt 生成


适配器模式是一种结构型设计模式，它允许将一个类的接口转换成客户端期望的另一个接口。适配器通常用于解决两个已有接口之间不兼容的情况，使得它们能够协同工作。

### 1.角色

 * **目标接口（Target）**：客户端期望的接口，适配器将原始接口转换为目标接口。
 * **适配器（Adapter）**：实现目标接口，并维护一个指向被适配对象的引用。
 * **被适配对象（Adaptee）**：需要被适配的类，它定义了不兼容的接口。

### 2.结构

```lua
    +--------------+              +-------------+
    |    Target    |<-------------|   Adapter   |
    +--------------+              +-------------+
            |                              |
            |                              |
            +-------------+                |
                          |                |
                          |                |
                     +---------+           |
                     | Adaptee |<----------+
                     +---------+

```

### 3. 实现示例

让我们通过一个简单的示例来说明适配器模式。假设我们有一个音乐播放器，它能够播放MP3格式的音乐，但我们希望能够播放其他格式的音乐，例如MP4格式。我们可以使用适配器模式来创建一个适配器，将MP4格式音乐的播放方法转换为MP3格式音乐的播放方法。

```cpp
#include <iostream>
#include <memory>

// 目标接口
class MediaPlayer {
public:
    virtual void play() const = 0;
    virtual ~MediaPlayer() {}
};

// 具体目标类 - MP3播放器
class MP3Player : public MediaPlayer {
public:
    void play() const override {
        std::cout << "Playing MP3 Music" << std::endl;
    }
};

// 被适配对象 - MP4播放器
class MP4Player {
public:
    void playMP4() const {
        std::cout << "Playing MP4 Music" << std::endl;
    }
};

// 适配器
class MP4Adapter : public MediaPlayer {
private:
    std::shared_ptr<MP4Player> mp4Player;
public:
    MP4Adapter(std::shared_ptr<MP4Player> player) : mp4Player(player) {}

    void play() const override {
        mp4Player->playMP4();
    }
};

int main() {
    // 使用智能指针创建具体目标对象
    auto mp3Player = std::make_shared<MP3Player>();

    // 使用智能指针创建被适配对象
    auto mp4Player = std::make_shared<MP4Player>();

    // 使用适配器将MP4播放器适配成MediaPlayer接口
    auto mp4Adapter = std::make_shared<MP4Adapter>(mp4Player);

    // 使用MediaPlayer接口播放音乐
    mp3Player->play();
    mp4Adapter->play();

    return 0;
}

```

在这个示例中，MediaPlayer是目标接口，定义了播放音乐的方法。MP3Player是具体目标类，它实现了MediaPlayer接口。MP4Player是被适配对象，它定义了MP4格式音乐的播放方法。MP4Adapter是适配器，它继承了MediaPlayer接口并将MP4Player的方法转换为目标接口的方法。

通过适配器模式，我们成功地将MP4播放器适配成了能够使用MediaPlayer接口的对象，使得客户端代码可以统一地使用MediaPlayer接口来播放音乐，而不必关心具体的音乐格式。

