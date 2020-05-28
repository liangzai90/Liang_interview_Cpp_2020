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

// 面试题52：两个链表的第一个公共结点
// 题目：输入两个链表，找出它们的第一个公共结点。


#include <iostream>
#include <algorithm>
#include <string>
#include "List.h"
using namespace std;

bool FindCommonNode(ListNode* listA, ListNode* listB)
{
	if (listB == nullptr || listA == nullptr)
	{
		cout << "List is nullptr" << endl;
		return false; 
	}

	//先计算A、B两个链表长度
	int lengthA = GetListLength(listA);//5
	int lengthB = GetListLength(listB);//2

	//根据链表长度，调整2个指针，直到末尾元素长度相等
	if (lengthA > lengthB)
	{
		int iGap = lengthA - lengthB;
		while (listA != nullptr && iGap>0)
		{
			listA = listA->m_pNext;
			iGap--;
		}
	}
	else if (lengthA < lengthB)
	{
		int iGap = lengthB - lengthA;
		while (listB != nullptr && iGap > 0)
		{
			listB = listB->m_pNext;
			iGap--;
		}
	}

	//有相同节点的链表，末尾元素都相同
	while (listB != nullptr && listA != nullptr)
	{
		if (listA == listB)
		{
			cout << "First common Node is:" << listA->m_nValue << endl;
			return true;
		}
		listA = listA->m_pNext;
		listB = listB->m_pNext;
	}
	cout << "No common Node." << endl;
	return false;
}

void Test(const char* testName, ListNode* listA, ListNode* listB, bool expected)
{
	if (testName)
	{
		cout << testName << " begins:" << endl;
	}
	if (expected == FindCommonNode(listA, listB))
	{
		cout << testName<< " passed " << endl;
	}
	else
	{
		cout << testName << " FAILED " << endl;
	}
	cout << endl;
}


//1,3,(2)5,7
void Test1()
{
	ListNode* node1 = CreateListNode(1);
	ListNode* node3 = CreateListNode(3);
	ListNode* node5 = CreateListNode(5);
	ListNode* node7 = CreateListNode(7);

	ListNode* node2 = CreateListNode(2);
	ListNode* node4 = CreateListNode(4);

	ConnectListNodes(node1, node3);
	ConnectListNodes(node3, node5);
	ConnectListNodes(node5, node7);

	ConnectListNodes(node2, node5);

	Test("test1",node1, node2, true);
}

//1,3,5,7,,,2,4
void Test2()
{
	ListNode* node1 = CreateListNode(1);
	ListNode* node3 = CreateListNode(3);
	ListNode* node5 = CreateListNode(5);
	ListNode* node7 = CreateListNode(7);

	ListNode* node2 = CreateListNode(2);
	ListNode* node4 = CreateListNode(4);

	ConnectListNodes(node1, node3);
	ConnectListNodes(node3, node5);
	ConnectListNodes(node5, node7);

	ConnectListNodes(node2, node4);

	Test("test2", node1, node2, false);
}

//1,3,5,7
void Test3()
{
	ListNode* node1 = CreateListNode(1);
	ListNode* node3 = CreateListNode(3);
	ListNode* node5 = CreateListNode(5);
	ListNode* node7 = CreateListNode(7);

	ConnectListNodes(node1, node3);
	ConnectListNodes(node3, node5);
	ConnectListNodes(node5, node7);

	Test("test3", node1, node1, true);
}



//1,3,5,(2)7,
void Test4()
{
	ListNode* node1 = CreateListNode(1);
	ListNode* node3 = CreateListNode(3);
	ListNode* node5 = CreateListNode(5);
	ListNode* node7 = CreateListNode(7);

	ListNode* node2 = CreateListNode(2);

	ConnectListNodes(node1, node3);
	ConnectListNodes(node3, node5);
	ConnectListNodes(node5, node7);

	ConnectListNodes(node2, node7);

	Test("test4", node1, node2, true);
}

void Test5()
{
	ListNode* node1 = CreateListNode(1);
	Test("test5", nullptr, node1, false);
}


int main(int argc, char* argv[])
{
	Test1();
	Test2();
	Test3();
	Test4();
	Test5();

	   
	cout << endl;
	system("pause");
	return 0;
}

