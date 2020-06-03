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

// 面试题55（二）：平衡二叉树
// 题目：输入一棵二叉树的根结点，判断该树是不是平衡二叉树。如果某二叉树中
// 任意结点的左右子树的深度相差不超过1，那么它就是一棵平衡二叉树。


#include <iostream>
#include <algorithm>
#include <string>
#include "BinaryTree.h"
using namespace std;



//这种判别方式，只能找到叶子节点的深度，，，不能用来判断平衡二叉树。。。有缺陷。。。
void TreeDeepMin(const BinaryTreeNode* pRoot, int deep ,int& MinDeep)
{
	if (pRoot == nullptr)
		return ;
	deep++;
	if (deep < MinDeep && pRoot->m_pLeft==nullptr && pRoot->m_pRight==nullptr)
	{
		MinDeep = deep;
	}
	
	TreeDeepMin(pRoot->m_pLeft, deep, MinDeep);
	TreeDeepMin(pRoot->m_pRight, deep, MinDeep);

	//if (pRoot->m_pLeft != nullptr)
	//{
	//	
	//}
	//else if (pRoot->m_pRight != nullptr)
	//{
	//}
}

int TreeDeepMax(const BinaryTreeNode* pRoot)
{
	if (pRoot == nullptr)
		return 0;

	int nLeft = TreeDeepMax(pRoot->m_pLeft);
	int nRight = TreeDeepMax(pRoot->m_pRight);
	
	return  (nLeft>nRight)? (nLeft+1):(nRight+1);
}

bool TreeIsBalance(const BinaryTreeNode* pRoot)
{
	if (pRoot == nullptr)
	{
		return true;
	}

	int Min = 999;
	TreeDeepMin(pRoot, 0, Min);
	int Max = TreeDeepMax(pRoot);
	cout << "Max:" << Max << ", min:" << Min << endl;
	if (Max - Min <= 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}



//=========================


// ====================测试代码====================
void Test(const char* testName, const BinaryTreeNode* pRoot, bool expected)
{
	if (testName != nullptr)
		printf("%s begins:\n", testName);

	printf("My Solution begins: ");
	if (TreeIsBalance(pRoot) == expected)
		printf("Passed.\n");
	else
		printf("Failed.\n");
	printf("------------------------------\r\n");


}

// 完全二叉树
//             1
//         /      \
//        2        3
//       /\       / \
//      4  5     6   7
void Test1()
{
	BinaryTreeNode* pNode1 = CreateBinaryTreeNode(1);
	BinaryTreeNode* pNode2 = CreateBinaryTreeNode(2);
	BinaryTreeNode* pNode3 = CreateBinaryTreeNode(3);
	BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
	BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
	BinaryTreeNode* pNode6 = CreateBinaryTreeNode(6);
	BinaryTreeNode* pNode7 = CreateBinaryTreeNode(7);

	ConnectTreeNodes(pNode1, pNode2, pNode3);
	ConnectTreeNodes(pNode2, pNode4, pNode5);
	ConnectTreeNodes(pNode3, pNode6, pNode7);

	Test("Test1", pNode1, true);

	DestroyTree(pNode1);
}

// 不是完全二叉树，但是平衡二叉树
//             1
//         /      \
//        2        3
//       /\         \
//      4  5         6
//        /
//       7
void Test2()
{
	BinaryTreeNode* pNode1 = CreateBinaryTreeNode(1);
	BinaryTreeNode* pNode2 = CreateBinaryTreeNode(2);
	BinaryTreeNode* pNode3 = CreateBinaryTreeNode(3);
	BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
	BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
	BinaryTreeNode* pNode6 = CreateBinaryTreeNode(6);
	BinaryTreeNode* pNode7 = CreateBinaryTreeNode(7);

	ConnectTreeNodes(pNode1, pNode2, pNode3);
	ConnectTreeNodes(pNode2, pNode4, pNode5);
	ConnectTreeNodes(pNode3, nullptr, pNode6);
	ConnectTreeNodes(pNode5, pNode7, nullptr);

	Test("Test2", pNode1, true);

	DestroyTree(pNode1);
}


// 不是完全二叉树，但是平衡二叉树
//             1
//         /      \
//        2        3
//       /\      
//      4  5         
//        /
//       7
//      /
//     8 
void Test2_2()
{
	BinaryTreeNode* pNode1 = CreateBinaryTreeNode(1);
	BinaryTreeNode* pNode2 = CreateBinaryTreeNode(2);
	BinaryTreeNode* pNode3 = CreateBinaryTreeNode(3);
	BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
	BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
	BinaryTreeNode* pNode6 = CreateBinaryTreeNode(6);
	BinaryTreeNode* pNode7 = CreateBinaryTreeNode(7);

	BinaryTreeNode* pNode8 = CreateBinaryTreeNode(8);

	ConnectTreeNodes(pNode1, pNode2, pNode3);
	ConnectTreeNodes(pNode2, pNode4, pNode5);
//	ConnectTreeNodes(pNode3, pNode6, pNode8);
	ConnectTreeNodes(pNode5, pNode7, nullptr);
	ConnectTreeNodes(pNode7, pNode8, nullptr);

	Test("Test2_2", pNode1, false);

	DestroyTree(pNode1);
}

// 不是平衡二叉树
//             1
//         /      \
//        2        3
//       /\         
//      4  5        
//        /
//       6
void Test3()
{
	BinaryTreeNode* pNode1 = CreateBinaryTreeNode(1);
	BinaryTreeNode* pNode2 = CreateBinaryTreeNode(2);
	BinaryTreeNode* pNode3 = CreateBinaryTreeNode(3);
	BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
	BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
	BinaryTreeNode* pNode6 = CreateBinaryTreeNode(6);

	ConnectTreeNodes(pNode1, pNode2, pNode3);
	ConnectTreeNodes(pNode2, pNode4, pNode5);
	ConnectTreeNodes(pNode5, pNode6, nullptr);

	Test("Test3", pNode1, false);

	DestroyTree(pNode1);
}


//               1
//              /
//             2
//            /
//           3
//          /
//         4
//        /
//       5
void Test4()
{
	BinaryTreeNode* pNode1 = CreateBinaryTreeNode(1);
	BinaryTreeNode* pNode2 = CreateBinaryTreeNode(2);
	BinaryTreeNode* pNode3 = CreateBinaryTreeNode(3);
	BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
	BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);

	ConnectTreeNodes(pNode1, pNode2, nullptr);
	ConnectTreeNodes(pNode2, pNode3, nullptr);
	ConnectTreeNodes(pNode3, pNode4, nullptr);
	ConnectTreeNodes(pNode4, pNode5, nullptr);

	Test("Test4", pNode1, false);

	DestroyTree(pNode1);
}

// 1
//  \
//   2
//    \
//     3
//      \
//       4
//        \
//         5
void Test5()
{
	BinaryTreeNode* pNode1 = CreateBinaryTreeNode(1);
	BinaryTreeNode* pNode2 = CreateBinaryTreeNode(2);
	BinaryTreeNode* pNode3 = CreateBinaryTreeNode(3);
	BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
	BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);

	ConnectTreeNodes(pNode1, nullptr, pNode2);
	ConnectTreeNodes(pNode2, nullptr, pNode3);
	ConnectTreeNodes(pNode3, nullptr, pNode4);
	ConnectTreeNodes(pNode4, nullptr, pNode5);

	Test("Test5", pNode1, false);

	DestroyTree(pNode1);
}

// 树中只有1个结点
void Test6()
{
	BinaryTreeNode* pNode1 = CreateBinaryTreeNode(1);
	Test("Test6", pNode1, true);

	DestroyTree(pNode1);
}

// 树中没有结点
void Test7()
{
	Test("Test7", nullptr, true);
}



int main(int argc, char* argv[])
{
	
	Test1();
	Test2();
	Test2_2();
	Test3();
	Test4();
	Test5();
	Test6();
	Test7();



	cout << endl;
	system("pause");
	return 0;
}

