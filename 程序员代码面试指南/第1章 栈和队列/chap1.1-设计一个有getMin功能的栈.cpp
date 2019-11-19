/***************************
《程序员代码面试指南--IT名企算法与数据结构题目最优解》 左程云  著

设计一个由getMin功能的栈

题目：实现一个特的栈，在实现栈的基本功能的基础上，再实现返回栈中最小元素的操作。

要求：
1.pop, push, getMin操作的时间复杂度都是O(1).
2.设计栈的类型可以使用现成的栈结构

难度：[ ★☆☆☆ ]

题目地址：
https://www.nowcoder.com/practice/05e57ce2cd8e4a1eae8c3b0a7e9886be?tpId=101&tqId=33073&rp=1&ru=/ta/programmer-code-interview-guide&qru=/ta/programmer-code-interview-guide/question-ranking

**************************************/


#include <assert.h>
#include <iostream>
#include <stack>
#include <stdlib.h>
#include <string>
using namespace std;



template<typename DataType> 
//typedef int  DataType;
class MyStack
{
public:
	MyStack();
	~MyStack();
	DataType pop();
	void push(DataType elem);
	DataType getMin();
	int size();

private:
	int m_stackLength;
	stack<int> m_normalStack;
	stack<int> m_minStack;
};


template<typename DataType>
MyStack<DataType>::MyStack()
{
 	m_stackLength = 0;
}
 
template<typename DataType>
MyStack<DataType>::~MyStack()
{
	m_stackLength = 0;
}


template<typename DataType>
DataType MyStack<DataType>::pop()
{
	assert(!m_normalStack.empty() && "pop() Error");

	DataType elem;
	elem = m_normalStack.top();//C++的stack，只能通过top()去访问最顶部元素，pop()是不会返回值的
	m_normalStack.pop();
	if (elem <= m_minStack.top())
	{
		m_minStack.pop();
	}
	m_stackLength--;
	return elem;
}


template<typename DataType>
void MyStack<DataType>::push(DataType elem)
{
	m_normalStack.push(elem);
	if (m_minStack.empty())
	{
		m_minStack.push(elem);
	}
	//注意这里的边界条件.等于也要入栈，否则不知道什么时候出栈
	else if(elem <= m_minStack.top())
	{
		m_minStack.push(elem);
	}
	m_stackLength++;
}

template<typename DataType>
DataType MyStack<DataType>::getMin()
{
	assert(!m_minStack.empty() && "getMin() Error");

	return m_minStack.top();
}

template<typename DataType>
int MyStack<DataType>::size()
{
	return m_stackLength;
}




//////////////////测试案例
//基本功能测试
void test1()
{
	cout << "---------test1---------" << endl;
	MyStack<int> myStack1;
	myStack1.push(8);
	myStack1.push(7);
	myStack1.push(6);
	myStack1.push(3);
	myStack1.push(5);
	myStack1.push(2);
	myStack1.push(5);

	int stackLength = myStack1.size();
	for (int i = 0; i < stackLength; i++)
	{
		cout << "getMin()" << myStack1.getMin() << endl;
		cout << "pop" << myStack1.pop() << endl;
	}
}

//边界值测试
void test2()
{
	cout << "---------test2---------" << endl;
	MyStack<int> myStack2;
	myStack2.push(8);
	myStack2.push(7);
	myStack2.push(4);
	myStack2.push(4);
	myStack2.push(3);
	myStack2.push(5);
	int stackLength = myStack2.size();
	for (int i = 0; i < stackLength; i++)
	{
		cout << "getMin()" << myStack2.getMin() << endl;
		cout << "pop" << myStack2.pop() << endl;
	}

}

//无效输入
void test3()
{
	cout << "---------test3---------" << endl;
	MyStack<int> myStack3;
	myStack3.getMin();
	myStack3.pop();
	myStack3.pop();
}

////性能测试（大量数据）
void test4()
{
	cout << "---------test4---------" << endl;

}

int getOperaType(string& str)
{
    if(0 == str.compare("push"))
    {
        return 1;
    }
    else if(0 == str.compare("pop"))
    {
        return 2;
    }
    else if(0 == str.compare("getMin"))
    {
        return 3;
    }
    else 
    {
        return 0;
    }
}

int main()
{
    MyStack<int> myStack;
    int iTotalNum = 0;
    cin>>iTotalNum;
    
    for(int i=0;i<iTotalNum;i++)
    {
        string stropea;
        int num = 0;
        int iOpeaType = 0;
        cin>>stropea;
        if(1 == getOperaType(stropea))
        {
            // push
            int iInput=0;
            cin>>iInput;
            myStack.push(iInput);
        }
        else if(2 == getOperaType(stropea))
        {
            // pop
            myStack.pop();
        }
        else if(3 == getOperaType(stropea))
        {
            // getMin
            cout << myStack.getMin()<<endl;
        }
        
    }

	return 0;
}

