## vector

vector 包含的方法

vector::push_back  // 在末尾插入元素
vector::pop_back  // 删除末尾元素
vector::erase // 删除元素
vector::insert // 在指定位置插入元素
vector::clear // 清空vector
vector::size // 返回vector的大小
vector::reserve // 重新分配内存
vector::empty // 判断是否为空
vector::emplace // 在指定位置插入元素
vector::emplace_back // 在末尾插入元素
vector::begin // 获取第一个元素
vector::end // 获取最后一个元素
vector::swap // 交换两个vector

vector::capacity // 返回vector的容量
vector::front // 获取第一个元素 
vector::back // 获取最后一个元素
vector::data // 返回vector的首地址
vector::rbegin // 反向迭代器
vector::rend // 反向迭代器
vector::cbegin // 反向迭代器
vector::cend // 获取最后一个元素
vector::crbegin // 反向迭代器
vector::crend // 反向迭代器
vector::max_size // 返回最大容量
vector::resize // 重新调整大小
vector::assign // 重新赋值
vector::shrink_to_fit // 释放多余空间
vector::at // 通过下标访问元素
vector::operator[] // 通过下标访问元素



你提到的这些方法都是C++ STL（标准模板库）中`std::vector`模板类的成员函数。`std::vector`是一个动态数组，能够根据需要增长或缩小。下面是每个方法的详细解释：

### 插入和删除元素

#### `push_back`

```cpp
void push_back(const value_type& val);
void push_back(value_type&& val);
```

在`vector`的末尾插入一个元素。

#### `pop_back`

```cpp
void pop_back();
```

删除`vector`的最后一个元素。

#### `erase`

```cpp
iterator erase(const_iterator position);
iterator erase(const_iterator first, const_iterator last);
```

删除指定位置的元素或删除一个范围内的元素。

#### `insert`

```cpp
iterator insert(const_iterator position, const value_type& val);
iterator insert(const_iterator position, size_type count, const value_type& val);
iterator insert(const_iterator position, const_iterator first, const_iterator last);
```

在指定位置插入一个或多个元素。

#### `emplace`

```cpp
iterator emplace(const_iterator position, args...);
```

在指定位置直接构造一个元素。

#### `emplace_back`

```cpp
void emplace_back(args...);
```

在`vector`的末尾直接构造一个元素。

#### `emplace_front`

注意：`std::vector`没有`emplace_front`成员函数，因为`vector`不支持在头部插入元素。对于在头部插入，你可能需要使用`deque`或`list`等其他容器。

### 容器大小操作

#### `clear`

```cpp
void clear();
```

删除`vector`中的所有元素。

#### `size`

```cpp
size_type size() const noexcept;
```

返回`vector`中元素的数量。

#### `empty`

```cpp
bool empty() const noexcept;
```

检查`vector`是否为空。

### 容量操作

#### `reserve`

```cpp
void reserve(size_type new_cap);
```

为`vector`至少分配能容纳`new_cap`个元素的内存。

#### `capacity`

```cpp
size_type capacity() const noexcept;
```

返回`vector`当前的容量（即分配的内存大小）。

### 访问元素

#### `front`

```cpp
reference front();
const_reference front() const;
```

返回`vector`中第一个元素的引用。

#### `back`

```cpp
reference back();
const_reference back() const;
```

返回`vector`中最后一个元素的引用。

#### `data`

```cpp
value_type* data() noexcept;
const value_type* data() const noexcept;
```

返回指向`vector`中第一个元素的指针。

#### `at`

```cpp
reference at(size_type pos);
const_reference at(size_type pos) const;
```

通过位置访问元素，如果位置越界，则抛出`std::out_of_range`异常。

#### `operator[]`

```cpp
reference operator[](size_type pos);
const_reference operator[](size_type pos) const;
```

通过下标访问元素，如果位置越界，则行为未定义（通常是访问违规内存）。

### 迭代器

#### `begin`

```cpp
iterator begin() noexcept;
const_iterator begin() const noexcept;
```

返回指向`vector`中第一个元素的迭代器。

#### `end`

```cpp
iterator end() noexcept;
const_iterator end() const noexcept;
```

返回指向`vector`末尾之后位置的迭代器（即“尾后迭代器”）。

#### `rbegin` 和 `rend`

```cpp
reverse_iterator rbegin() noexcept;
const_reverse_iterator rbegin() const noexcept;
reverse_iterator rend() noexcept;
const_reverse_iterator rend() const noexcept;
```

返回反向迭代器，用于从后向前遍历`vector`。

#### `cbegin` 和 `cend`

```cpp
const_iterator cbegin() const noexcept;
const_iterator cend() const noexcept;
```

返回指向`vector`中第一个元素的常量迭代器，以及指向`vector`末尾之后位置的常量迭代器。

#### `crbegin` 和 `crend`

```cpp
const_reverse_iterator crbegin() const noexcept;
const_reverse_iterator crend() const noexcept;
```

返回常量反向迭代器，用于从后向前遍历`vector`。

### 其他操作

#### `max_size`

```cpp
size_type max_size() const noexcept;
```

返回`vector`可能容纳的最大元素数量。这通常是一个很大的值，由系统或库的实现决定。

#### `resize`

```cpp
void resize(size_type new_size);
void resize(size_type new_size, const value_type& val);
```

改变`vector`的大小。如果新的大小大于当前大小，则可能需要添加元素（默认为构造的默认值或提供的值）。如果新的大小小于当前大小，则删除尾部的元素。

#### `assign`

```cpp
void assign(size_type n, const value_type& val);
void assign(const_iterator first, const_iterator last);
void assign(std::initializer_list<value_type> ilist);
```

为`vector`分配新的内容，替换当前内容。可以基于数量和值，迭代器范围，或初始化列表进行分配。

#### `shrink_to_fit`

```cpp
void shrink_to_fit();
```

请求容器减少其容量以匹配其大小。注意，这并不是强制性的，容器可以选择忽略此请求。

#### `swap`

```cpp
void swap(vector& other) noexcept;
```

交换两个`vector`的内容。这是一个高效的操作，不需要元素的复制或移动，只是交换内部指针和大小。

以上就是`std::vector`中主要方法的详细解释。每个方法都有其特定的用途，并且可以根据需要组合使用，以构建和修改`vector`容器。