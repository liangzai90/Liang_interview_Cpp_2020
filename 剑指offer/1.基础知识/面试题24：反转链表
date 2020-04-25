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

// 面试题24：反转链表
// 题目：定义一个函数，输入一个链表的头结点，反转该链表并输出反转后链表的
// 头结点。

#include <iostream>
#include "List.h"
using namespace std;

/////我自己写的
ListNode* reverseList(ListNode* pListHead)
{
    ListNode* pBeforeNode = pListHead;
    if (pBeforeNode == nullptr)
    {
        return pBeforeNode; //zero node
    }
    ListNode* pMoveNode = pListHead->m_pNext;
    if (pMoveNode == nullptr)
    {
        return pBeforeNode;//one node
    }
    pBeforeNode->m_pNext = nullptr;
    ListNode* pNextNode = pMoveNode->m_pNext;
    pMoveNode->m_pNext = pBeforeNode;
    while (pNextNode != nullptr)
    {
        pBeforeNode = pMoveNode;
        pMoveNode = pNextNode;
        pNextNode = pNextNode->m_pNext;
        pMoveNode->m_pNext = pBeforeNode;
    }
    return pMoveNode;
}


//作者写的
ListNode* ReverserList2(ListNode* pHead)
{
    ListNode* pReversedHead = nullptr;
    ListNode* pNode = pHead;
    ListNode* pPrev = nullptr;
    while (pNode != nullptr)
    {
        ListNode* pNext = pNode->m_pNext;
        if (pNext == nullptr)
        {
            pReversedHead = pNode;
        }
        pNode->m_pNext = pPrev;
        pPrev = pNode;
        pNode = pNext;
    }
    return pReversedHead;
}




//====================测试代码================
ListNode* Test(ListNode* pHead)
{
    printf("The original list is : \r\n");
    PrintList(pHead);

    ListNode* pReversedHead = reverseList(pHead);

    printf("The reversed list is: \r\n");
    PrintList(pReversedHead);

    return pReversedHead;
}

//输入的链表有多个节点
void Test1()
{
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode4 = CreateListNode(4);
    ListNode* pNode5 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);

    ListNode* pReversedHead = Test(pNode1);

    DestroyList(pReversedHead);
}

//输入的链表只有一个节点
void Test2()
{
    ListNode* pNode1 = CreateListNode(1);

    ListNode* pReversedHead = Test(pNode1);

    DestroyList(pReversedHead);
}


//输入的链表只有2个节点
void Test3()
{
    ListNode* pNode1 = CreateListNode(66);
    ListNode* pNode2 = CreateListNode(77);
    ConnectListNodes(pNode1, pNode2);

    ListNode* pReversedHead = Test(pNode1);

    DestroyList(pReversedHead);
}


// 输入空链表
void Test4()
{
    Test(nullptr);
}




int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();


	cout << endl;
	system("pause");
	return 0;
}



