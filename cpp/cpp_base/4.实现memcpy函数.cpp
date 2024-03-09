#include <iostream>

void* my_memcpy(void* destination, const void* source, size_t num) {
    // 强制类型转换为char*类型以实现字节级别的操作
    char* dest = static_cast<char*>(destination);
    const char* src = static_cast<const char*>(source);

    // 使用循环逐字节复制数据
    for (size_t i = 0; i < num; ++i) {
        dest[i] = src[i];
    }

    return destination;
}

// 定义一个结构体类型
struct Person {
    int id;
    char name[20];
    double salary;
};

int main() {
    // 创建一个Person结构体对象
    Person source = {123, "John Doe", 50000.0};

    // 创建一个Person结构体对象作为目标
    Person destination;

    // 使用自定义的my_memcpy函数拷贝结构体
    my_memcpy(&destination, &source, sizeof(Person));

    // 输出目标结构体的内容
    std::cout << "ID: " << destination.id << std::endl;
    std::cout << "Name: " << destination.name << std::endl;
    std::cout << "Salary: " << destination.salary << std::endl;

    return 0;
}