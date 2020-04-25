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

// 面试题25：合并两个排序的链表
// 题目：输入两个递增排序的链表，合并这两个链表并使新链表中的结点仍然是按
// 照递增排序的。例如输入图3.11中的链表1和链表2，则合并之后的升序链表如链
// 表3所示。

#include <iostream>
#include "List.h"
using namespace std;

//输入两个递增排序的链表,listA, listB
ListNode* MergeTwoList(ListNode* listA, ListNode* listB)
{
    //1.考虑特殊情（如空链表），要注意程序的鲁棒性
    //2.先找到头结点。（两个链表里面，值更小的那个）

    //存在空链表的情况
    if (listA == nullptr)
    {
        return listB;
    }
    else if (listB == nullptr)
    {
        return listA;
    }

    ListNode* pNewHead = nullptr;
    //a,b都不是空链表
    if (listA->m_nValue <= listB->m_nValue)
    {
        pNewHead = listA;
        listA = listA->m_pNext;
    }
    else
    {
        pNewHead = listB;
        listB = listB->m_pNext;
    }
    //串联 各个节点的 临时节点
    ListNode* pNextNode = pNewHead;
    pNextNode->m_pNext = nullptr;

    while (listA != nullptr && listB != nullptr)
    {
        if (listA->m_nValue <= listB->m_nValue)
        {
            pNextNode->m_pNext = listA;
            listA = listA->m_pNext;
            pNextNode = pNextNode->m_pNext;
        }
        else
        {
            pNextNode->m_pNext = listB;
            listB = listB->m_pNext;
            pNextNode = pNextNode->m_pNext;
        }
    }

    if (listA == nullptr)
    {
        pNextNode->m_pNext = listB;
    }
    if (listB == nullptr)
    {
        pNextNode->m_pNext = listA;
    }
      
    return pNewHead;
}


//作者的完成代码
ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
{
    if (pHead1 == nullptr)
    {
        return pHead1;
    }
    else if (pHead2 == nullptr)
    {
        return pHead2;
    }

    ListNode* pMergedHead = nullptr;

    if (pHead1->m_nValue < pHead2->m_nValue)
    {
        pMergedHead = pHead1;
        pMergedHead->m_pNext = Merge(pHead1->m_pNext, pHead2);
    }
    else
    {
        pMergedHead = pHead2;
        pMergedHead->m_pNext = Merge(pHead1, pHead2->m_pNext);
    }
    return pMergedHead;
}




//=============测试代码=================
ListNode* Test(char* testName, ListNode* pHead1, ListNode* pHead2)
{
    if (testName != nullptr)
    {
        printf("%s  begins: \r\n", testName);
    }

    printf("The first list is: \r\n");
    PrintList(pHead1);

    printf("The second list is: \r\n");
    PrintList(pHead2);

    printf("The merged list is: \r\n");
    ListNode* pMergedHead = MergeTwoList(pHead1, pHead2);
    PrintList(pMergedHead);
    printf("\r\n-----------------------\r\n");

    return pMergedHead;
}


//链表没有相同数字
// list1: 1->3->5
// list2: 2->4->6
void Test1()
{
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode5 = CreateListNode(5);
    ConnectListNodes(pNode1, pNode3);
    ConnectListNodes(pNode3, pNode5);

    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode4 = CreateListNode(4);
    ListNode* pNode6 = CreateListNode(6);
    ConnectListNodes(pNode2, pNode4);
    ConnectListNodes(pNode4, pNode6);

    ListNode* pMergedHead = Test("Test1", pNode1, pNode2);
    DestroyList(pMergedHead);
}



//两个链表中有重复数字
// list1: 1->3->5
// list2: 1->3->5
void Test2()
{
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode5 = CreateListNode(5);
    ConnectListNodes(pNode1, pNode3);
    ConnectListNodes(pNode3, pNode5);

    ListNode* pNode2 = CreateListNode(1);
    ListNode* pNode4 = CreateListNode(3);
    ListNode* pNode6 = CreateListNode(5);
    ConnectListNodes(pNode2, pNode4);
    ConnectListNodes(pNode4, pNode6);

    ListNode* pMergedHead = Test("Test2", pNode1, pNode2);
    DestroyList(pMergedHead);
}


//两个链表都只有一个数字
// list1: 1
// list2: 2
void Test3()
{
    ListNode* pNode1 = CreateListNode(1);

    ListNode* pNode2 = CreateListNode(2);

    ListNode* pMergedHead = Test("Test3", pNode1, pNode2);
    DestroyList(pMergedHead);
}



//一个链表为空
// list1: 1->3->5
// list2: 
void Test4()
{
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode5 = CreateListNode(5);
    ConnectListNodes(pNode1, pNode3);
    ConnectListNodes(pNode3, pNode5);

    ListNode* pNode2 = nullptr;
    
    ListNode* pMergedHead = Test("Test4", pNode1, pNode2);
    DestroyList(pMergedHead);
}



//尾部合并
// list1: 1->3->5
// list2: 7->8->9
void Test5()
{
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode5 = CreateListNode(5);
    ConnectListNodes(pNode1, pNode3);
    ConnectListNodes(pNode3, pNode5);

    ListNode* pNode2 = CreateListNode(7);
    ListNode* pNode4 = CreateListNode(8);
    ListNode* pNode6 = CreateListNode(9);
    ConnectListNodes(pNode2, pNode4);
    ConnectListNodes(pNode4, pNode6);

    ListNode* pMergedHead = Test("Test5", pNode1, pNode2);
    DestroyList(pMergedHead);
}



//头部插入
// list1: 1
// list2: 7->8->9
void Test6()
{
    ListNode* pNode1 = CreateListNode(1);

    ListNode* pNode2 = CreateListNode(7);
    ListNode* pNode4 = CreateListNode(8);
    ListNode* pNode6 = CreateListNode(9);

    ConnectListNodes(pNode2, pNode4);
    ConnectListNodes(pNode4, pNode6);
    
    ListNode* pMergedHead = Test("Test6", pNode1, pNode2);
    DestroyList(pMergedHead);
}


//尾部插入
// list1: 10
// list2: 7->8->9
void Test7()
{
    ListNode* pNode1 = CreateListNode(10);

    ListNode* pNode2 = CreateListNode(7);
    ListNode* pNode4 = CreateListNode(8);
    ListNode* pNode6 = CreateListNode(9);
    ConnectListNodes(pNode2, pNode4);
    ConnectListNodes(pNode4, pNode6);

    ListNode* pMergedHead = Test("Test7", pNode1, pNode2);
    DestroyList(pMergedHead);
}


//某个链表是为另一个链表的一部分
// list1: 1->5->8
// list2: 2->3->4
void Test8()
{
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode3 = CreateListNode(5);
    ListNode* pNode5 = CreateListNode(8);
    ConnectListNodes(pNode1, pNode3);
    ConnectListNodes(pNode3, pNode5);

    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode4 = CreateListNode(3);
    ListNode* pNode6 = CreateListNode(4);
    ConnectListNodes(pNode2, pNode4);
    ConnectListNodes(pNode4, pNode6);

    ListNode* pMergedHead = Test("Test8", pNode1, pNode2);
    DestroyList(pMergedHead);
}


// 两个链表都为空链表
// list1: 空链表
// list2: 空链表
void Test9()
{
    ListNode* pMergedHead = Test("Test9", nullptr, nullptr);
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
    Test8();
    Test9();


	cout << endl;
	system("pause");
	return 0;
}
