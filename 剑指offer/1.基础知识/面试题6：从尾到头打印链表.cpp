/********************************
����ָoffer������ʼ�


������6����β��ͷ��ӡ����

��Ŀ��
����һ�������ͷ��㣬��β��ͷ��������ӡ��ÿ���ڵ��ֵ��
����ڵ㶨�����£�
struct ListNode
{
int m_nKey;
ListNode* m_pNext;
};


�ⷨ1������stack
�ⷨ2���ݹ�������������̫�����ݹ�ᵼ�º�������ջ�����

*******************************************/

#include <iostream>
#include <string>
#include <stack>
#include "List.h"
using namespace std;

/// �ݹ�ʵ�ִ�ӡ
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


////����stackʵ�ִ�ӡ
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


////======================���Դ���=======================
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

///ֻ��һ���ڵ�
void Test2()
{
	printf("\r\nTest2 begins. \r\n");
	ListNode* pNode1 = CreateListNode(1);
	Test(pNode1);
	DestroyList(pNode1);
}

//������
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

