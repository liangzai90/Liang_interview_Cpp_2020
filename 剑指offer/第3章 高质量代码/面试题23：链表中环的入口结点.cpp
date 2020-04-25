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

// 面试题23：链表中环的入口结点
// 题目：一个链表中包含环，如何找出环的入口结点？例如，在图3.8的链表中，
// 环的入口结点是结点3。


#include <iostream>
#include "List.h"
using namespace std;

ListNode* MeetingNode(ListNode* pHead)
{
    if (pHead == nullptr)
    {
        return nullptr;
    }
    ListNode* pSlow = pHead->m_pNext;
    if (pSlow == nullptr)
    {
        return nullptr;
    }

    ListNode* pFast = pSlow->m_pNext;
    while (pFast != nullptr && pSlow!=nullptr)
    {
        if (pFast == pSlow)
        {
            return pFast;///相遇的点
        }

        pSlow = pSlow->m_pNext;
        pFast = pFast->m_pNext;


        ////快指针，每次走2步
        if (pFast != nullptr)
        {
            pFast = pFast->m_pNext;
        }
    }

    return nullptr;
}

ListNode* EntryNodeOfLoop(ListNode* pHead)
{
    ListNode* mettingNode = MeetingNode(pHead);
    if (mettingNode == nullptr)
    {
        return nullptr;
    }

    ////得到环中节点数目
    int nodesInLoop = 1;
    ListNode* pNode1 = mettingNode;
    while (pNode1->m_pNext != mettingNode)
    {
        pNode1 = pNode1->m_pNext;
        ++nodesInLoop;
    }

    //先移动pNode1,次数为 环中节点的数目
    pNode1 = pHead;
    for (int i = 0; i < nodesInLoop; i++)
    {
        pNode1 = pNode1->m_pNext;
    }

    //再移动pNode1和pNode2
    ListNode* pNode2 = pHead;
    while (pNode2 != pNode1)
    {
        pNode1 = pNode1->m_pNext;
        pNode2 = pNode2->m_pNext;
    }
    return pNode1; ///环的入口节点
}

//=============test code==============
void Test(char* testName, ListNode* pHead, ListNode* entryNode)
{
    if (testName != nullptr)
    {
        printf("%s begins: ", testName);
    }
    if (EntryNodeOfLoop(pHead) == entryNode)
    {
        printf(" Passed.\r\n");
    }
    else
    {
        printf("Failed*******\r\n");
    }
}

//A list has a node, without a loop
void Test1()
{
    ListNode* pNode1 = CreateListNode(1);
    Test("Test1", pNode1, nullptr);

    DestroyList(pNode1);
}

//A list has a node, with a loop
void Test2()
{
    ListNode* pNode1 = CreateListNode(1);

    ConnectListNodes(pNode1, pNode1);

    Test("Test2", pNode1, pNode1);

    delete pNode1;
    pNode1 = nullptr;
}

//A list has multiple nodes, with a loop
void Test3()
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
    ConnectListNodes(pNode5, pNode3);

    Test("Test3", pNode1, pNode3);

    delete pNode1;
    pNode1 = nullptr;
    delete pNode2;
    pNode2 = nullptr;
    delete pNode3;
    pNode3 = nullptr;
    delete pNode4;
    pNode4 = nullptr;
    delete pNode5;
    pNode5 = nullptr;
}


// A list has multiple nodes, with a loop 
void Test4()
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
    ConnectListNodes(pNode5, pNode1);

    Test("Test4", pNode1, pNode1);

    delete pNode1;
    pNode1 = nullptr;
    delete pNode2;
    pNode2 = nullptr;
    delete pNode3;
    pNode3 = nullptr;
    delete pNode4;
    pNode4 = nullptr;
    delete pNode5;
    pNode5 = nullptr;
}

// A list has multiple nodes, with a loop 
void Test5()
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
    ConnectListNodes(pNode5, pNode5);

    Test("Test5", pNode1, pNode5);

    delete pNode1;
    pNode1 = nullptr;
    delete pNode2;
    pNode2 = nullptr;
    delete pNode3;
    pNode3 = nullptr;
    delete pNode4;
    pNode4 = nullptr;
    delete pNode5;
    pNode5 = nullptr;
}

// A list has multiple nodes, without a loop 
void Test6()
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

    Test("Test6", pNode1, nullptr);

    DestroyList(pNode1);
}

// Empty list
void Test7()
{
    Test("Test7", nullptr, nullptr);
}


int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    Test7();

	cout << endl;
	system("pause");
	return 0;
}

