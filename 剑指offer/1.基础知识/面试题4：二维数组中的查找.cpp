/********************************
《剑指offer》做题笔记


面试题4：二维数组中的查找

题目：
在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。
请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。

测试用例：
1.二维数组中包含查找的数字（查找的数字是数组中的最大值和最小值；查找的数字介于数组中的最大值和最小值之间）
2.二维数组中没有查找的数字（查找的数字大于数组中的最大值；查找的数字小于数组中的最小值；查找的数字在最大值和最小值之间，但数组中没有数字
3.特殊输入测试（输入空指针）


当我们需要解决一个复杂的问题时，一个很有效的办法就是从一个具体的问题入手，
通过分析简单具体的例子，试图寻找普遍规律。



*******************************************/

#include <iostream>
#include <assert.h>
#include <mutex>
#include <string>
#include <map>
#include <stdlib.h>
using namespace std;

//左下查找
bool FindNumInSortedArray1(int *matrix, int rows, int columns, int target)
{
	if (matrix == nullptr || rows <= 0 || columns <= 0)
	{
		return false;
	}
	bool bFind = false;

	int iStartRow = rows - 1;
	int iStartColumn = 0;

	while (iStartRow >= 0 && iStartColumn<columns)
	{
		if (matrix[iStartRow*columns + iStartColumn] == target)
		{
			bFind = true;
			return bFind;
		}
		else if (matrix[iStartRow*columns + iStartColumn] > target)
		{
			iStartRow--;
		}
		else
		{
			iStartColumn++;
		}
	}


	return bFind;
}


//右上查找
bool FindNumInSortedArray2(int *matrix, int rows, int columns, int target)
{
	if (matrix == nullptr || rows <= 0 || columns <= 0)
	{
		return false;
	}
	bool bFind = false;

	int iStartRow = 0;
	int iStartColumn = columns-1;

	while (iStartRow < rows && iStartColumn>=0)
	{
		if (matrix[iStartRow*columns + iStartColumn] == target)
		{
			bFind = true;
			return bFind;
		}
		else if (matrix[iStartRow*columns + iStartColumn] > target)
		{
			iStartColumn--;
		}
		else
		{
			iStartRow++;
		}
	}


	return bFind;
}



// ====================测试代码====================
void Test(char* testName, int* matrix, int rows, int columns, int number, bool expected)
{
	if (testName != nullptr)
		printf("%s begins: ", testName);

	bool result = FindNumInSortedArray1(matrix, rows, columns, number);
	if (result == expected)
		printf("Passed.\n");
	else
		printf("Failed.\n");
}

//  1   2   8   9
//  2   4   9   12
//  4   7   10  13
//  6   8   11  15
// 要查找的数在数组中
void Test1()
{
	int matrix[][4] = { { 1, 2, 8, 9 }, { 2, 4, 9, 12 }, { 4, 7, 10, 13 }, { 6, 8, 11, 15 } };
	Test("Test1", (int*)matrix, 4, 4, 7, true);
}

//  1   2   8   9
//  2   4   9   12
//  4   7   10  13
//  6   8   11  15
// 要查找的数不在数组中
void Test2()
{
	int matrix[][4] = { { 1, 2, 8, 9 }, { 2, 4, 9, 12 }, { 4, 7, 10, 13 }, { 6, 8, 11, 15 } };
	Test("Test2", (int*)matrix, 4, 4, 5, false);
}

//  1   2   8   9
//  2   4   9   12
//  4   7   10  13
//  6   8   11  15
// 要查找的数是数组中最小的数字
void Test3()
{
	int matrix[][4] = { { 1, 2, 8, 9 }, { 2, 4, 9, 12 }, { 4, 7, 10, 13 }, { 6, 8, 11, 15 } };
	Test("Test3", (int*)matrix, 4, 4, 1, true);
}

//  1   2   8   9
//  2   4   9   12
//  4   7   10  13
//  6   8   11  15
// 要查找的数是数组中最大的数字
void Test4()
{
	int matrix[][4] = { { 1, 2, 8, 9 }, { 2, 4, 9, 12 }, { 4, 7, 10, 13 }, { 6, 8, 11, 15 } };
	Test("Test4", (int*)matrix, 4, 4, 15, true);
}

//  1   2   8   9
//  2   4   9   12
//  4   7   10  13
//  6   8   11  15
// 要查找的数比数组中最小的数字还小
void Test5()
{
	int matrix[][4] = { { 1, 2, 8, 9 }, { 2, 4, 9, 12 }, { 4, 7, 10, 13 }, { 6, 8, 11, 15 } };
	Test("Test5", (int*)matrix, 4, 4, 0, false);
}

//  1   2   8   9
//  2   4   9   12
//  4   7   10  13
//  6   8   11  15
// 要查找的数比数组中最大的数字还大
void Test6()
{
	int matrix[][4] = { { 1, 2, 8, 9 }, { 2, 4, 9, 12 }, { 4, 7, 10, 13 }, { 6, 8, 11, 15 } };
	Test("Test6", (int*)matrix, 4, 4, 16, false);
}

// 鲁棒性测试，输入空指针
void Test7()
{
	Test("Test7", nullptr, 0, 0, 16, false);
}



int main()
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

