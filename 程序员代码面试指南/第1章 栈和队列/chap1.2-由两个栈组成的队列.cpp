/***************************
《程序员代码面试指南--IT名企算法与数据结构题目最优解》 左程云  著

由两个栈组成的队列

题目：
编写一个类，用两个栈实现队列，支持队列的基本操作（add, poll, peek)

add:添加元素
poll:删除队列第1个元素
peek:读取队列第1个元素


难度：[ ★★☆☆ ]

题目地址：
https://www.nowcoder.com/practice/6bc058b32ee54a5fa18c62f29bae9863?tpId=101&tqId=33074&tPage=1&rp=1&ru=/ta/programmer-code-interview-guide&qru=/ta/programmer-code-interview-guide/question-ranking

**************************************/




#include <assert.h>
#include <iostream>
#include <stack>
#include <stdlib.h>
#include <string>
using namespace std;


//typedef int  DataType;
template<typename DataType>
class MyQueue
{
public:
	MyQueue();
	~MyQueue();
	DataType pop();
	void push(DataType elem);
	DataType getFront();
	int size();

private:
	int m_stackLength;
//	stack<DataType> m_normalStack;
	stack<DataType> m_inputStack;
	stack<DataType> m_outputStack;
	DataType m_front;
};


template<typename DataType>
MyQueue<DataType>::MyQueue()
{
	m_stackLength = 0;
}

template<typename DataType>
MyQueue<DataType>::~MyQueue()
{
	m_stackLength = 0;
}


template<typename DataType>
DataType MyQueue<DataType>::pop()
{
	assert(!m_inputStack.empty() && "pop() Error");
	int size1 = m_inputStack.size();
	for (int i = 0; i <size1; i++)
	{
		DataType elem = m_inputStack.top();
		m_outputStack.push(elem);
		m_inputStack.pop();
	}

	DataType elem;
	elem = m_outputStack.top();//C++的stack，只能通过top()去访问最顶部元素，pop()是不会返回值的
	m_outputStack.pop();
	
	if (!m_outputStack.empty())
	{

		m_front = m_outputStack.top();
	}

	// 如果最后一个元素也弹出去了，就不要for循环了
	int size2 = m_outputStack.size();
	for (int i = 0; i < size2; i++)
	{
		DataType elem = m_outputStack.top();
		m_inputStack.push(elem);
		m_outputStack.pop();
	}

	m_stackLength--;
	return elem;
}


template<typename DataType>
void MyQueue<DataType>::push(DataType elem)
{
	if (m_inputStack.empty())
	{
		m_front = elem;
	}
	m_inputStack.push(elem);
	m_stackLength++;
}

template<typename DataType>
DataType MyQueue<DataType>::getFront()
{
	return m_front;
}

template<typename DataType>
int MyQueue<DataType>::size()
{
	return m_stackLength;
}




//////////////////测试案例
//基本功能测试
void test1()
{
	cout << "---------test1---------" << endl;
	MyQueue<int> myStack1;
	myStack1.push(8);
	myStack1.push(7);
	myStack1.push(6);
	cout << "peek:" << myStack1.getFront() << endl;
	myStack1.pop();
	cout << "peek:" << myStack1.getFront() << endl;
	myStack1.pop();
	cout << "peek:" << myStack1.getFront() << endl;
	myStack1.push(5);
	myStack1.push(4);
	myStack1.push(3);
	myStack1.push(2);
	cout << "peek:" << myStack1.getFront() << endl;
	myStack1.pop();
	cout << "peek:" << myStack1.getFront() << endl;
	myStack1.pop();
	cout << "peek:" << myStack1.getFront() << endl;
}

//边界值测试
void test2()
{
	cout << "---------test2---------" << endl;
	MyQueue<int> myStack2;
	myStack2.push(8);
	myStack2.push(7);
	myStack2.pop();
	myStack2.pop();
	myStack2.push(4);
	myStack2.push(2);
	cout << "peek:" << myStack2.getFront() << endl;
	myStack2.pop();
	myStack2.pop();
	myStack2.push(1);
	cout << "peek:" << myStack2.getFront() << endl;
}

//无效输入
void test3()
{
	cout << "---------test3---------" << endl;
	MyQueue<int> myStack3;
	myStack3.push(-826955);
	myStack3.push(312698);
	myStack3.pop();
//	myStack3.pop();
	myStack3.push(-283180);
	myStack3.push(120911);
	myStack3.push(975752);
	myStack3.push(588311);
	myStack3.push(142372);
	myStack3.push(826515);
	cout << "Peek:" << myStack3.getFront();
}

////性能测试（大量数据）
void test4()
{
	cout << "---------test4---------" << endl;

}

int getOperaType(string& str)
{
	if (0 == str.compare("add"))
	{
		return 1;
	}
	else if (0 == str.compare("poll")) //单词别写错了啊
	{
		return 2;
	}
	else if (0 == str.compare("peek"))
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
	MyQueue<int> myStack;
	test1();
	test2();
	test3();

	//int iTotalNum = 0;
	//cin >> iTotalNum;

	//for (int i = 0; i < iTotalNum; i++)
	//{
	//	string stropea;
	//	int num = 0;
	//	int iOpeaType = 0;
	//	cin >> stropea;
	//	if (1 == getOperaType(stropea))
	//	{
	//		// add
	//		int iInput = 0;
	//		cin >> iInput;
	//		myStack.push(iInput);
	//	}
	//	else if (2 == getOperaType(stropea))
	//	{
	//		// poll
	//		myStack.pop();
	//	}
	//	else if (3 == getOperaType(stropea))
	//	{
	//		// peek
	//		cout << myStack.getFront() << endl;
	//	}

	//}

	cout << endl;
	system("pause");
	return 0;
}

