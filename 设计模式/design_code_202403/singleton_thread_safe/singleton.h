#ifndef __SINGLETON_H__
#define __SINGLETON_H__

class Singleton {
public:
    // 获取单例实例的静态方法
    static Singleton& getInstance();

    // 单例类的其他方法和成员
    void showMessage();
    void Print();
    void SetValue(int val);

private:
    int m_value;
    
    // 将构造函数和析构函数设为私有，防止外部创建和删除对象
    Singleton() {}
    ~Singleton() {}
    // 禁止复制和赋值操作，确保只有一个实例
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;
};


#endif 