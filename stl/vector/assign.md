## 介绍 assign 的用法

`std::vector` 的 `assign` 成员函数用于替换容器中的现有元素。它有几个重载版本，可以接受不同数量和类型的参数。以下是 `assign` 成员函数的一些常见用法和代码示例：

### 1. 使用迭代器赋值

你可以使用两个迭代器（指向要复制元素的范围的开始和结束）来调用 `assign`。

```cpp
#include <iostream>
#include <vector>
#include <list>

int main() {
    std::list<int> lst = {1, 2, 3, 4, 5}; // 使用list作为示例源
    std::vector<int> vec;

    // 使用list的迭代器来赋值给vector
    vec.assign(lst.begin(), lst.end());

    // 输出vector的内容
    for (int n : vec) {
        std::cout << n << ' ';
    }
    std::cout << std::endl;

    return 0;
}
```

### 2. 使用指定数量的元素赋值

你可以指定一个元素值和一个数量，来用相同值的多个元素替换容器内容。

```cpp
#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec = {1, 2, 3};

    // 使用5个值为10的元素替换vec的内容
    vec.assign(5, 10);

    // 输出vector的内容
    for (int n : vec) {
        std::cout << n << ' ';
    }
    std::cout << std::endl;

    return 0;
}
```

### 3. 使用初始化列表赋值

你还可以使用初始化列表来赋值。

```cpp
#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec;

    // 使用初始化列表赋值
    vec.assign({1, 2, 3, 4, 5});

    // 输出vector的内容
    for (int n : vec) {
        std::cout << n << ' ';
    }
    std::cout << std::endl;

    return 0;
}
```

在这些示例中，`assign` 函数会替换 `vector` 中现有的所有元素。如果新的元素数量少于原始元素数量，多余的元素会被删除；如果新的元素数量多于原始元素数量，`vector` 会增长以容纳新的元素。

注意，`assign` 不会保留原始 `vector` 中的任何元素，即使新的元素数量和原始元素数量相同，原始元素也会被新元素替换。如果你只想添加或删除元素而不替换所有元素，应该使用 `push_back`、`pop_back`、`insert`、`erase` 等成员函数。