/********************************
《剑指offer》做题笔记


面试题6：从尾到头打印链表

题目：
输入一个链表的头结点，从尾到头反过来打印出每个节点的值。
链表节点定义如下：
struct ListNode
{
int m_nKey;
ListNode* m_pNext;
};


解法1：利用stack
解法2：递归输出（如果链表太长，递归会导致函数调用栈溢出）

*******************************************/

#include <iostream>
#include <string>
#include <stack>
#include "List.h"
using namespace std;

/// 递归实现打印
void PrintListReversingly_Recursively(ListNode* pHead)
{
	if (pHead != nullptr)
	{
		if (pHead->m_pNext != nullptr)
		{
			PrintListReversingly_Recursively(pHead->m_pNext);
		}
		printf("%d \t", pHead->m_nValue);
	}
}


////利用stack实现打印
void PrintListReversingly_Iteratively(ListNode* pHead)
{
	std::stack<ListNode*> nodes;

	ListNode* pNode = pHead;
	while (pNode != nullptr)
	{
		nodes.push(pNode);
		pNode = pNode->m_pNext;
	}

	while (!nodes.empty())
	{
		pNode = nodes.top();
		printf("%d \t", pNode->m_nValue);
		nodes.pop();
	}
}


////======================测试代码=======================
void Test(ListNode* pHead)
{
	PrintList(pHead);
	PrintListReversingly_Iteratively(pHead);
	printf("\r\n");
	PrintListReversingly_Recursively(pHead);
}

//1->2->3->4->5
void Test1()
{
	printf("\r\nTest1 begins. \r\n");

	ListNode* pNode1 = CreateListNode(1);
	ListNode* pNode2 = CreateListNode(2);
	ListNode* pNode3 = CreateListNode(3);
	ListNode* pNode4 = CreateListNode(4);
	ListNode* pNode5 = CreateListNode(5);

	ConnectListNodes(pNode1, pNode2);
	ConnectListNodes(pNode2, pNode3);
	ConnectListNodes(pNode3, pNode4);
	ConnectListNodes(pNode4, pNode5);

	Test(pNode1);
	DestroyList(pNode1);
}

///只有一个节点
void Test2()
{
	printf("\r\nTest2 begins. \r\n");
	ListNode* pNode1 = CreateListNode(1);
	Test(pNode1);
	DestroyList(pNode1);
}

//空链表
void Test3()
{
	printf("\r\nTest3 begins.\r\n");
	Test(nullptr);
}


int main()
{
	Test1();
	Test2();
	Test3();


	cout << endl;
	system("pause");
	return 0;
}

