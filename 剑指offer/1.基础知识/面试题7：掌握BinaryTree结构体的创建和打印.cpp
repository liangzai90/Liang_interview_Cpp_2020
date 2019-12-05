/********************************
《剑指offer》做题笔记


//二叉树的创建、和打印
//理解一棵树的结构体，如何创建。

*******************************************/

#include <iostream>
#include <string>
#include <exception>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

//二叉树结构体
struct BinaryTreeNode
{
	int  m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};


//创建一个二叉树节点
BinaryTreeNode* CreateBinaryTreeNode(int value)
{
	BinaryTreeNode* pNode = new BinaryTreeNode();
	pNode->m_nValue = value;
	pNode->m_pLeft = nullptr;
	pNode->m_pRight = nullptr;
	return pNode;
}

//将节点和左右孩子节点连接起来
void ConnectTreeNodes(BinaryTreeNode* pParent, BinaryTreeNode* pLeft, BinaryTreeNode *pRight)
{
	if (pParent != nullptr)
	{
		pParent->m_pLeft = pLeft;
		pParent->m_pRight = pRight;
	}
}

//打印节点
void PrintTreeNode(const BinaryTreeNode* pNode)
{
	if (pNode != nullptr)
	{
		printf("value of this node is : %d \r\n", pNode->m_nValue);

		if (pNode->m_pLeft != nullptr)
		{
			printf("value of its left child is: %d \r\n", pNode->m_pLeft->m_nValue);
		}
		else
		{
			printf("left child is nullptr. \r\n");
		}

		if (pNode->m_pRight != nullptr)
		{
			printf("value of its right child is: %d \r\n", pNode->m_pRight->m_nValue);
		}
		else
		{
			printf("right child is nullptr. \r\n");
		}
	}
	else
	{
		printf("this node is nullptr.\r\n");
	}
	printf("\r\n");
}


//前序遍历（根左右）打印二叉树
void PrintTree(const BinaryTreeNode* pRoot)
{
	PrintTreeNode(pRoot);

	if (pRoot != nullptr)
	{
		if (pRoot->m_pLeft != nullptr)
		{
			PrintTree(pRoot->m_pLeft);
		}

		if (pRoot->m_pRight != nullptr)
		{
			PrintTree(pRoot->m_pRight);
		}
	}
}

//销毁一棵二叉树
void DestroyTree(BinaryTreeNode* pRoot)
{
	if (pRoot != nullptr)
	{
		BinaryTreeNode* pLeft = pRoot->m_pLeft;
		BinaryTreeNode* pRight = pRoot->m_pRight;

		delete pRoot;
		pRoot = nullptr;

		DestroyTree(pLeft);
		DestroyTree(pRight);
	}
}




//===================测试代码=======================

//        1
//     2     3
//   4  5   6  7
//  8    9
void test1()
{
	BinaryTreeNode* pRoot = CreateBinaryTreeNode(1);
	BinaryTreeNode* pNode2 = CreateBinaryTreeNode(2);
	BinaryTreeNode* pNode3 = CreateBinaryTreeNode(3);
	BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
	BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
	BinaryTreeNode* pNode6 = CreateBinaryTreeNode(6);
	BinaryTreeNode* pNode7 = CreateBinaryTreeNode(7);
	BinaryTreeNode* pNode8 = CreateBinaryTreeNode(8);
	BinaryTreeNode* pNode9 = CreateBinaryTreeNode(9);

	ConnectTreeNodes(pRoot, pNode2, pNode3);
	ConnectTreeNodes(pNode2, pNode4, pNode5);
	ConnectTreeNodes(pNode3, pNode6, pNode7);
	ConnectTreeNodes(pNode4, pNode8, nullptr);
	ConnectTreeNodes(pNode5, nullptr, pNode9);
	ConnectTreeNodes(pNode6, nullptr, nullptr);
	ConnectTreeNodes(pNode7, nullptr, nullptr);
	ConnectTreeNodes(pNode8, nullptr, nullptr);
	ConnectTreeNodes(pNode9, nullptr, nullptr);

	PrintTree(pRoot);
}



int main(int argc, char* argv[])
{
	test1();


	cout << endl;
	system("pause");
	return 0;
}


