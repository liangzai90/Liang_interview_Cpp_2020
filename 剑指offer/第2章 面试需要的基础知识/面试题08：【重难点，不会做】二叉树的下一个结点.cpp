/********************************
《剑指offer》做题笔记


// 面试题8：二叉树的下一个结点
// 题目：给定一棵二叉树和其中的一个结点，如何找出中序遍历顺序的下一个结点？
// 树中的结点除了有两个分别指向左右子结点的指针以外，还有一个指向父结点的指针。



*******************************************/

#include <iostream>
#include <string>
#include <exception>
#include <stdlib.h>
#include <stdio.h>
using namespace std;


struct BinaryTreeNode
{
	int  m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
	BinaryTreeNode* m_pParent;
};

BinaryTreeNode* GetNext(BinaryTreeNode* pNode)
{
	if (pNode == nullptr)
		return nullptr;

	BinaryTreeNode* pNext = nullptr;
	if (pNode->m_pRight != nullptr)
	{
		BinaryTreeNode* pRight = pNode->m_pRight;
		while (pRight->m_pLeft != nullptr)
			pRight = pRight->m_pLeft;

		pNext = pRight;
	}
	else if (pNode->m_pParent != nullptr)
	{
		BinaryTreeNode* pCurrent = pNode;
		BinaryTreeNode* pParent = pNode->m_pParent;
		while (pParent != nullptr && pCurrent == pParent->m_pRight)
		{
			pCurrent = pParent;
			pParent = pParent->m_pParent;
		}

		pNext = pParent;
	}

	return pNext;
}

// ==================== 辅助代码用来构建二叉树 ====================
BinaryTreeNode* CreateBinaryTreeNode2(int value)
{
	BinaryTreeNode* pNode = new BinaryTreeNode();
	pNode->m_nValue = value;
	pNode->m_pLeft = nullptr;
	pNode->m_pRight = nullptr;
	pNode->m_pParent = nullptr;

	return pNode;
}

void ConnectTreeNodes2(BinaryTreeNode* pParent, BinaryTreeNode* pLeft, BinaryTreeNode* pRight)
{
	if (pParent != nullptr)
	{
		pParent->m_pLeft = pLeft;
		pParent->m_pRight = pRight;

		if (pLeft != nullptr)
			pLeft->m_pParent = pParent;
		if (pRight != nullptr)
			pRight->m_pParent = pParent;
	}
}

void PrintTreeNode(BinaryTreeNode* pNode)
{
	if (pNode != nullptr)
	{
		printf("value of this node is: %d\n", pNode->m_nValue);

		if (pNode->m_pLeft != nullptr)
			printf("value of its left child is: %d.\n", pNode->m_pLeft->m_nValue);
		else
			printf("left child is null.\n");

		if (pNode->m_pRight != nullptr)
			printf("value of its right child is: %d.\n", pNode->m_pRight->m_nValue);
		else
			printf("right child is null.\n");
	}
	else
	{
		printf("this node is null.\n");
	}

	printf("\n");
}

void PrintTree(BinaryTreeNode* pRoot)
{
	PrintTreeNode(pRoot);

	if (pRoot != nullptr)
	{
		if (pRoot->m_pLeft != nullptr)
			PrintTree(pRoot->m_pLeft);

		if (pRoot->m_pRight != nullptr)
			PrintTree(pRoot->m_pRight);
	}
}

void DestroyTree2(BinaryTreeNode* pRoot)
{
	if (pRoot != nullptr)
	{
		BinaryTreeNode* pLeft = pRoot->m_pLeft;
		BinaryTreeNode* pRight = pRoot->m_pRight;

		delete pRoot;
		pRoot = nullptr;

		DestroyTree2(pLeft);
		DestroyTree2(pRight);
	}
}

// ====================测试代码====================
void Test(char* testName, BinaryTreeNode* pNode, BinaryTreeNode* expected)
{
	if (testName != nullptr)
		printf("%s begins: ", testName);

	BinaryTreeNode* pNext = GetNext(pNode);
	if (pNext == expected)
		printf("Passed.\n");
	else
		printf("FAILED.\n");
}

//            8
//        6      10
//       5 7    9  11
void Test1_7()
{
	BinaryTreeNode* pNode8 = CreateBinaryTreeNode2(8);
	BinaryTreeNode* pNode6 = CreateBinaryTreeNode2(6);
	BinaryTreeNode* pNode10 = CreateBinaryTreeNode2(10);
	BinaryTreeNode* pNode5 = CreateBinaryTreeNode2(5);
	BinaryTreeNode* pNode7 = CreateBinaryTreeNode2(7);
	BinaryTreeNode* pNode9 = CreateBinaryTreeNode2(9);
	BinaryTreeNode* pNode11 = CreateBinaryTreeNode2(11);

	ConnectTreeNodes2(pNode8, pNode6, pNode10);
	ConnectTreeNodes2(pNode6, pNode5, pNode7);
	ConnectTreeNodes2(pNode10, pNode9, pNode11);

	PrintTree(pNode8);

	Test("Test1", pNode8, pNode9);
	Test("Test2", pNode6, pNode7);
	Test("Test3", pNode10, pNode11);
	Test("Test4", pNode5, pNode6);
	Test("Test5", pNode7, pNode8);
	Test("Test6", pNode9, pNode10);
	Test("Test7", pNode11, nullptr);

	DestroyTree2(pNode8);
}


//            5
//          4
//        3
//      2
void Test8_11()
{
	BinaryTreeNode* pNode5 = CreateBinaryTreeNode2(5);
	BinaryTreeNode* pNode4 = CreateBinaryTreeNode2(4);
	BinaryTreeNode* pNode3 = CreateBinaryTreeNode2(3);
	BinaryTreeNode* pNode2 = CreateBinaryTreeNode2(2);

	ConnectTreeNodes2(pNode5, pNode4, nullptr);
	ConnectTreeNodes2(pNode4, pNode3, nullptr);
	ConnectTreeNodes2(pNode3, pNode2, nullptr);

	Test("Test8", pNode5, nullptr);
	Test("Test9", pNode4, pNode5);
	Test("Test10", pNode3, pNode4);
	Test("Test11", pNode2, pNode3);

	DestroyTree2(pNode5);
}

//        2
//         3
//          4
//           5
void Test12_15()
{
	BinaryTreeNode* pNode2 = CreateBinaryTreeNode2(2);
	BinaryTreeNode* pNode3 = CreateBinaryTreeNode2(3);
	BinaryTreeNode* pNode4 = CreateBinaryTreeNode2(4);
	BinaryTreeNode* pNode5 = CreateBinaryTreeNode2(5);

	ConnectTreeNodes2(pNode2, nullptr, pNode3);
	ConnectTreeNodes2(pNode3, nullptr, pNode4);
	ConnectTreeNodes2(pNode4, nullptr, pNode5);

	Test("Test12", pNode5, nullptr);
	Test("Test13", pNode4, pNode5);
	Test("Test14", pNode3, pNode4);
	Test("Test15", pNode2, pNode3);

	DestroyTree2(pNode2);
}

void Test16()
{
	BinaryTreeNode* pNode5 = CreateBinaryTreeNode2(5);

	Test("Test16", pNode5, nullptr);

	DestroyTree2(pNode5);
}





int main(int argc, char* argv[])
{
	Test1_7();
	Test8_11();
	Test12_15();
	Test16();


	cout << endl;
	system("pause");
	return 0;
}


