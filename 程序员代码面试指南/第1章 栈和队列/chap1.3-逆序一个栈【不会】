/***************************
《程序员代码面试指南--IT名企算法与数据结构题目最优解》 左程云  著

逆序一个栈

题目：
如何仅用递归函数和栈操作逆序一个栈。
一个栈依次压入1,2,3,4,5，那么从栈顶到栈底分别为5,4,3,2,1.
将这个栈转置后，从栈顶到栈底为1,2,3,4,5，也就是实现栈中元素的逆序。
但是只能用递归函数来实现，不能用其他数据结构。



难度：[ ★★☆☆ ]

题目地址：
https://www.nowcoder.com/practice/1de82c89cc0e43e9aa6ee8243f4dbefd?tpId=101&tqId=33075&tPage=1&rp=1&ru=%2Fta%2Fprogrammer-code-interview-guide&qru=%2Fta%2Fprogrammer-code-interview-guide%2Fquestion-ranking



**************************************/

#include <iostream>
#include <stack>
using namespace std;

//将myStack的 栈底元素返回 并 移除 
int getAndRemoveLastElement(stack<int>& myStack)
{
	int result = myStack.top();
	myStack.pop();
	if (myStack.empty())
	{
		return result;
	}
	else
	{
		int last = getAndRemoveLastElement(myStack);
		myStack.push(result);
		return last;
	}
}

//实现栈的逆置
void reverse(stack<int>& myStack)
{
	if (myStack.empty())
	{
		return;
	}
	int elem = getAndRemoveLastElement(myStack);
	reverse(myStack);
	myStack.push(elem);

	// 输出结果
	cout << elem << " ";
}

int main()
{
	int inPutNum = 0;
	cin >> inPutNum;
	stack<int> myStack;
	for (int i = 0; i < inPutNum; i++)
	{
		int elem = 0;
		cin >> elem;
		myStack.push(elem);
	}

	reverse(myStack);

	return 0;
}





