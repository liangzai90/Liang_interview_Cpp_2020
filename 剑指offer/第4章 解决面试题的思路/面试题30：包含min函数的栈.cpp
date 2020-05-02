/*******************************************************************
Copyright(c) 2016, Harry He
All rights reserved.

Distributed under the BSD license.
(See accompanying file LICENSE.txt at
https://github.com/zhedahht/CodingInterviewChinese2/blob/master/LICENSE.txt)
*******************************************************************/

//==================================================================
// 《剑指Offer——名企面试官精讲典型编程题》代码
// 作者：何海涛
//==================================================================

// 面试题30：包含min函数的栈
// 题目：定义栈的数据结构，请在该类型中实现一个能够得到栈的最小元素的min
// 函数。在该栈中，调用min、push及pop的时间复杂度都是O(1)。



#include <iostream>
#include <stack>
#include <assert.h>
using namespace std;



//====================== 辅助类 =================
template <typename T> 
class StackWithMin
{
public:
    StackWithMin(){};
    virtual ~StackWithMin(){};

    T& top();
    const T& top() const;

    void push(const T& value);
    void pop();

    const T& min() const;
    bool empty() const;
    size_t size() const;

private:
    std::stack<T>  m_data;//数据栈，存放栈的所有元素
    std::stack<T>  m_min;//辅助栈，存放栈的最小元素
};

template <typename T> 
void StackWithMin<T>::push(const T& value)
{
    //把新元素添加到辅助栈
    m_data.push(value);

    //当新元素比之前的最小元素小时，把新元素插入辅助栈里
    //否则把之前的最小元素重复插入辅助栈里
    if (m_min.size() == 0 || value < m_min.top())
    {
        m_min.push(value);
    }
    else
    {
        m_min.push(m_min.top());
    }
}

template <typename T>
void StackWithMin<T>::pop()
{
    assert(m_data.size() >= 0 && m_min.size() >= 0);
    
    m_data.pop();
    m_min.pop();
}

template<typename T>
const T& StackWithMin<T>::min() const
{
    assert(m_data.size() > 0 && m_min.size() > 0);

    return m_min.top();
}

template<typename T>
T& StackWithMin<T>::top()
{
    return m_data.top();
}

template<typename T>
const T& StackWithMin<T>::top() const
{
    return m_data.top();
}

template<typename T>
bool StackWithMin<T>::empty() const
{
    return m_data.empty();
}

template<typename T>
size_t StackWithMin<T>::size() const
{
    return m_data.size();
}


//==============================
void Test(const char* testName, const StackWithMin<int>& stack, int expected)
{
    if (testName != nullptr)
        printf("%s begins: ", testName);
    assert(!stack.empty());

    if (stack.min() == expected)
        printf("PASSED... \r\n");
    else
        printf("Failed ******.\r\n");
}



int main(int argc, char* argv[])
{
    StackWithMin<int> stack;

    stack.push(3);
    Test("Test1", stack, 3);

    stack.push(4);
    Test("Test2", stack, 3);

    stack.push(2);
    Test("Test3", stack, 2);

    stack.push(3);
    Test("Test4", stack, 2);



    stack.pop();
    Test("Test5", stack, 2);

    stack.pop();
    Test("Test6", stack, 3);

    stack.pop();
    Test("Test7", stack, 3);

    stack.push(0);
    Test("Test8", stack, 0);
    //stack.pop();
    //Test("Test8", stack, 0);






	cout << endl;
	system("pause");
	return 0;
}





