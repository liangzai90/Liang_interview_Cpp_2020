/***************************
������Ա��������ָ��--IT�����㷨�����ݽṹ��Ŀ���Ž⡷ �����  ��

���һ����getMin���ܵ�ջ

��Ŀ��ʵ��һ���ص�ջ����ʵ��ջ�Ļ������ܵĻ����ϣ���ʵ�ַ���ջ����СԪ�صĲ�����

Ҫ��
1.pop, push, getMin������ʱ�临�Ӷȶ���O(1).
2.���ջ�����Ϳ���ʹ���ֳɵ�ջ�ṹ

�Ѷȣ�[ ����� ]


**************************************/

#include <assert.h>
#include <iostream>
#include <stack>
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
	elem = m_normalStack.top();//C++��stack��ֻ��ͨ��top()ȥ�������Ԫ�أ�pop()�ǲ��᷵��ֵ��
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
	//ע������ı߽�����.����ҲҪ��ջ������֪��ʲôʱ���ջ
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




//////////////////���԰���
//�������ܲ���
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

//�߽�ֵ����
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

//��Ч����
void test3()
{
	cout << "---------test3---------" << endl;
	MyStack<int> myStack3;
	myStack3.getMin();
	myStack3.pop();
	myStack3.pop();
}

////���ܲ��ԣ��������ݣ�
void test4()
{
	cout << "---------test4---------" << endl;

}


int main()
{
	test1();
	test2();
	test3();
	test4();


	cout << endl;
	cout << "������Ա��������ָ��--IT�����㷨�����ݽṹ��Ŀ���Ž⡷" << endl;
	system("pause");
	return 0;
}
