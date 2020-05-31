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

// 面试题53（三）：数组中数值和下标相等的元素
// 题目：假设一个单调递增的数组里的每个元素都是整数并且是唯一的。请编程实
// 现一个函数找出数组中任意一个数值等于其下标的元素。例如，在数组{-3, -1,
// 1, 3, 5}中，数字3和它的下标相等。



#include <iostream>
#include <algorithm>
#include <string>
#include "List.h"
using namespace std;



///我自己写的二分查找
int findCore(int* data, int length, int iStart, int iEnd)
{
	if (iStart > iEnd || iStart<0 || iEnd<0 || iStart>length-1 || iEnd>length-1)
	{
		cout << " find -1" << endl;
		return -1;
	}
	int middle = (iStart + iEnd) / 2;
	if (data[middle] == middle)
	{
		cout << "Find Index :" << middle << endl;
		return middle;
	}
	else if (data[middle] < middle)
	{
		return findCore(data, length, middle + 1, iEnd);
	}
	else
	{
		return findCore(data, length, iStart, middle - 1);
	}

	cout << " find -1 [2]" << endl;

	return -1;
}

int FindIndexN(int* data, int length)
{
	if (data == nullptr || length <= 0)
	{
		return -1;
	}

	return findCore(data, length, 0, length - 1);
}




void Test(char* testName, int* data, int length, int expected)
{
	if (testName != nullptr)
		printf("%s begins:\r\n", testName);

	if (FindIndexN(data, length) == expected)
	{
		printf(" passed ... \r\n");
	}
	else
	{
		printf(" *** FAILED ***\r\n");
	}

	printf("%s end.\r\n", testName);
	printf("----------------------------\r\n");
}


void test1()
{
	int data[] = { -3,-1,1,3,5 };
	Test("test1", data, sizeof(data) / sizeof(int), 3);
}





//===================这里的递增数字是有规律的
/*
当数值(m)和下标(i)不相等的时候，如果m>i,即数字的值大于它的下标。
由于数字都唯一并且单调递增，那么对于任意大于0的k，位于下标i+k的数字的值大于或等于m+k。
因为m>i，所以m+k>i+k。因此，位于下标i+k的数字的值一定大于对应的下标。
这意味着，如果第i个数字的值大于i，那么它右边的数字都大于对应的下标，因此都可以忽略。
下一轮查找从它左边的数字中查找即可。

同理，m<i的情况也是类似的
*/
//============下面是作者的解法：
int GetNumberSameAsIndex(const int* numbers, int length)
{
	if (numbers == nullptr || length <= 0)
	{
		return -1;
	}

	int left = 0;
	int right = length - 1;
	while (left <= right)
	{
		int middle = left + ((right - left) >> 1);
		if (numbers[middle] == middle)
			return middle;

		if (numbers[middle] > middle)
			right = middle - 1;
		else
			left = middle + 1;
	}
	return -1;
}


//=======================测试代码================
void Test_A(const char* testName, int numbers[], int length, int expected)
{
	if (GetNumberSameAsIndex(numbers, length) == expected)
		printf("%s passed.\n", testName);
	else
		printf("%s FAILED.\n", testName);
	printf("=======================\r\n");
}


void TestA1()
{
	int numbers[] = { -3, -1, 1, 3, 5 };
	int expected = 3;
	Test("TestA1", numbers, sizeof(numbers) / sizeof(int), expected);

	Test_A("TestA1", numbers, sizeof(numbers) / sizeof(int), expected);
}

void TestA2()
{
	int numbers[] = { 0, 1, 3, 5, 6 };
	int expected = 0;
	Test("TestA2", numbers, sizeof(numbers) / sizeof(int), expected);
}

void TestA3()
{
	int numbers[] = { -1, 0, 1, 2, 4 };
	int expected = 4;
	Test("TestA3", numbers, sizeof(numbers) / sizeof(int), expected);
}

void TestA4()
{
	int numbers[] = { -1, 0, 1, 2, 5 };
	int expected = -1;
	Test("TestA4", numbers, sizeof(numbers) / sizeof(int), expected);
}

void TestA5()
{
	int numbers[] = { 0 };
	int expected = 0;
	Test("TestA5", numbers, sizeof(numbers) / sizeof(int), expected);
}

void TestA6()
{
	int numbers[] = { 10 };
	int expected = -1;
	Test("TestA6", numbers, sizeof(numbers) / sizeof(int), expected);
}

void TestA7()
{
	Test("TestA7", nullptr, 0, -1);
}



int main(int argc, char* argv[])
{
	test1();

	TestA1();
	TestA2();
	TestA3();
	TestA4();
	TestA5();
	TestA6();
	TestA7();


	cout << endl;
	system("pause");
	return 0;
}

