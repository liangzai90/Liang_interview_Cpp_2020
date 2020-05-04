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

// 面试题33：二叉搜索树的后序遍历序列
// 题目：输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。
// 如果是则返回true，否则返回false。假设输入的数组的任意两个数字都互不相同。



#include <iostream>
#include <assert.h>
#include "BinaryTree.h"
#include <queue>
#include <stack>
using namespace std;

bool VerifySqueueofBST(int sequence[], int length)
{
    if (sequence == nullptr || length <= 0)
        return false;

    int root = sequence[length - 1];

    //在二叉搜索树中左子树的节点小于根节点
    int index_left=0;
    for (; index_left < length - 1; index_left++)
    {
        if (sequence[index_left]>root)
            break;
    }

    //在二叉搜索树中右子树的节点大于根节点
    int index_right = index_left;
    for (; index_right < length - 1; index_right++)
    {
        if (sequence[index_right] < root)
            return false;
    }

    //开始递归判断，左子树是不是二叉搜索树
    bool left = true;
    if (index_left>0)
        left = VerifySqueueofBST(sequence, index_left);

    //开始递归判断，右子树是不是二叉搜索树
    bool right = true;
    if (index_left < length - 1)
        right = VerifySqueueofBST(sequence + index_left, length - index_left - 1);

    return (left && right);
}



// ====================测试代码====================
void Test(const char* testName, int sequence[], int length, bool expected)
{
    if (testName != nullptr)
        printf("%s  begins: ", testName);

    if (VerifySqueueofBST(sequence, length) == expected)
        printf("passed.\r\n");
    else
        printf("FAILED.....\r\n");
    printf("-----------------------------------\r\n");
}

//
//        10
//     6      14
//   4   8  12   16
//
void Test1()
{
    int data[] = { 4, 8, 6, 12, 16, 14, 10 };
    Test("test1", data, sizeof(data) / sizeof(int), true);
}


//           5
//          / \
//         4   7
//            /
//           6
void Test2()
{
    int data[] = { 4, 6, 7, 5 };
    Test("Test2", data, sizeof(data) / sizeof(int), true);
}

//               5
//              /
//             4
//            /
//           3
//          /
//         2
//        /
//       1
void Test3()
{
    int data[] = { 1, 2, 3, 4, 5 };
    Test("Test3", data, sizeof(data) / sizeof(int), true);
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
void Test4()
{
    int data[] = { 5, 4, 3, 2, 1 };
    Test("Test4", data, sizeof(data) / sizeof(int), true);
}

// 树中只有1个结点
void Test5()
{
    int data[] = { 5 };
    Test("Test5", data, sizeof(data) / sizeof(int), true);
}

void Test6()
{
    int data[] = { 7, 4, 6, 5 };
    Test("Test6", data, sizeof(data) / sizeof(int), false);
}

void Test7()
{
    int data[] = { 4, 6, 12, 8, 16, 14, 10 };
    Test("Test7", data, sizeof(data) / sizeof(int), false);
}

void Test8()
{
    Test("Test8", nullptr, 0, false);
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

	cout << endl;
	system("pause");
	return 0;
}





