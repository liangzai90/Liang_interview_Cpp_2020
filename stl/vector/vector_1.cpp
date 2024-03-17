#include <iostream>  
#include <vector>  
  
int main() {  
    std::vector<int> vec;  
  
    // 使用 push_back 在末尾插入元素  
    vec.push_back(1);  
    vec.push_back(2);  
    vec.push_back(3);  
    vec.push_back(40);

    // 使用 pop_back 删除末尾元素
    vec.pop_back();  
  
    // 使用 size 获取 vector 的大小  
    std::cout << "Size of vec: " << vec.size() << std::endl;  
  
    // 使用 emplace_back 在末尾直接构造元素  
    vec.emplace_back(4);  
  
    // 使用 insert 在指定位置插入元素  
    auto it = vec.begin() + 1; // 指向第二个元素  
    vec.insert(it, 99);  
  
    // 使用 erase 删除元素  
    it = vec.begin() + 2; // 指向第三个元素（现在是99后面的那个元素）  
    vec.erase(it);  
  
    // 使用 at 通过下标访问元素并修改它  
    vec.at(1) = 88;  
  
    // 使用 operator[] 通过下标访问元素并输出  
    for (size_t i = 0; i < vec.size(); ++i) {  
        std::cout << vec[i] << ' ';  
    }  
    std::cout << std::endl;  
  
    // 使用 front 和 back 获取第一个和最后一个元素  
    std::cout << "First element: " << vec.front() << std::endl;  
    std::cout << "Last element: " << vec.back() << std::endl;  
  
    // 使用 empty 判断是否为空  
    if (!vec.empty()) {  
        std::cout << "Vector is not empty." << std::endl;  
    }  
  
    // 使用 clear 清空 vector  
    vec.clear();  
    std::cout << "After clear, size of vec: " << vec.size() << std::endl;  
  
    // 使用 reserve 预先分配内存（这里只是演示，实际上 clear 后是空的）  
    vec.reserve(10);  
  
    // 使用 swap 交换两个 vector  
    std::vector<int> anotherVec = {5, 6, 7};  
    vec.swap(anotherVec);  
    std::cout << "After swap, elements in vec: ";  
    for (int num : vec) {  
        std::cout << num << ' ';  
    }  
    std::cout << std::endl;  
  
    // 使用 assign 重新赋值  
    vec.assign({8, 9, 10});  
    std::cout << "After assign, elements in vec: ";  
    for (int num : vec) {  
        std::cout << num << ' ';  
    }  
    std::cout << std::endl;  
  
    // 使用 resize 重新调整大小并填充新元素（如果需要）  
    vec.resize(5, 100); // 将大小调整为5，新增的元素值为100  
    std::cout << "After resize, elements in vec: ";  
    for (int num : vec) {  
        std::cout << num << ' ';  
    }  
    std::cout << std::endl;  
  
    // 使用 capacity 获取容量和 max_size 获取最大可能大小  
    std::cout << "Capacity of vec: " << vec.capacity() << std::endl;  
    std::cout << "Max size of vec: " << vec.max_size() << std::endl;  
  
    // 使用 data 获取指向数据的指针（C++11起）  
    int* rawData = vec.data();  
    std::cout << "First element via raw pointer: " << *rawData << std::endl;  
  
    // 使用迭代器遍历 vector  
    std::cout << "Elements in vec via iterators: ";  
    for (auto it = vec.begin(); it != vec.end(); ++it) {  
        std::cout << *it << ' ';  
    }  
    std::cout << std::endl;  
  
    // 使用反向迭代器遍历 vector  
    std::cout << "Elements in vec in reverse order: ";  
    for (auto it = vec.rbegin(); it != vec.rend(); ++it) {
        std::cout << *it << ' ';
    }
    std::cout << std::endl;
    // 使用 const_iterator 和 const_reverse_iterator 遍历 vector（不修改元素）  
    std::cout << "Elements in vec via const_iterator: ";  
    for (auto it = vec.cbegin(); it != vec.cend(); ++it) {  
        std::cout << *it << ' ';  
    }  
    std::cout << std::endl;  
    std::cout << "Elements in vec in reverse order via const_reverse_iterator: ";  
    for (auto it = vec.crbegin(); it != vec.crend(); ++it) {  
        std::cout << *it << ' ';  
    }  
    std::cout << std::endl;  

    // 使用 shrink_to_fit 尝试减小容量以匹配大小  
    if (vec.capacity() > vec.size()) {  
        vec.shrink_to_fit();  
        std::cout << "After shrink_to_fit, capacity of vec: " << vec.capacity() << std::endl;  
    }  

    return 0;
}

/*
Size of vec: 3
1 88 3 4 
First element: 1
Last element: 4
Vector is not empty.
After clear, size of vec: 0
After swap, elements in vec: 5 6 7 
After assign, elements in vec: 8 9 10 
After resize, elements in vec: 8 9 10 100 100 
Capacity of vec: 6
Max size of vec: 2305843009213693951
First element via raw pointer: 8
Elements in vec via iterators: 8 9 10 100 100 
Elements in vec in reverse order: 100 100 10 9 8 
Elements in vec via const_iterator: 8 9 10 100 100 
Elements in vec in reverse order via const_reverse_iterator: 100 100 10 9 8 
After shrink_to_fit, capacity of vec: 5


在这个例子中，我演示了如何使用 `std::vector` 的大多数成员函数。
每个操作后，我都添加了一些输出语句，以便观察 `vector` 的变化。
注意，`shrink_to_fit` 的效果是依赖于实现的，并且可能不总是减小 `vector` 的容量到与大小相等。  
  
在C++中，迭代器是一种设计模式，
它允许程序员顺序访问一个聚合对象中的各个元素，而又不需要暴露该对象的内部表示。
`begin()` 和 `end()` 返回普通迭代器，可以用于修改元素，
而 `cbegin()` 和 `cend()` 返回常量迭代器，只能用于读取元素。
同样地，`rbegin()` 和 `rend()` 返回反向迭代器，用于从后向前遍历 `vector`，
而 `crbegin()` 和 `crend()` 返回常量反向迭代器。  
  
`std::vector` 是一个非常灵活且常用的容器，在C++编程中广泛使用。
掌握其成员函数和迭代器对于编写高效且可维护的代码至关重要。

*/