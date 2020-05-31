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

// 面试题53（二）：0到n-1中缺失的数字
// 题目：一个长度为n-1的递增排序数组中的所有数字都是唯一的，并且每个数字
// 都在范围0到n-1之内。在范围0到n-1的n个数字中有且只有一个数字不在该数组
// 中，请找出这个数字。



#include <iostream>
#include <algorithm>
#include <string>
#include "List.h"
using namespace std;


int findLostN(int * data, int start, int end)
{
	if (data == nullptr)
	{
		cout << "Invalid input" << endl;
		return -1;
	}

	if (start > end)
	{
		cout << " no lost data : return -2" << endl;
		return -2;
	}
	
	int middleIndex = (end - start) / 2 + start ;
	if (data[middleIndex] == middleIndex)
	{
		//TODO:这里必须要考虑边界条件。【最后面】的元素不存在。
		if (((middleIndex + 1 <= end) && (data[middleIndex + 1] != middleIndex + 1))||
			middleIndex+1>end)
		{
			cout << "Find N1:" << middleIndex + 1<<endl;
			return middleIndex+1;
		}
		start = middleIndex + 1;
		findLostN(data, start, end);
	}
	else
	{
		//TODO:这里必须要考虑边界条件。【最前面】的元素不存在。
		if (((middleIndex -1 >= start) && (data[middleIndex - 1] == middleIndex - 1))||
			middleIndex-1<start)
		{
			cout << "Find N2:" << middleIndex << endl;
			return middleIndex;
		}

		end = middleIndex - 1;
		findLostN(data, start, end);
	}
}


//=======================这是作者的写法 
///作者用的循环的写法，我那边用的是递归写法
int GetMissingNumber(const int* numbers, int length)
{
	if (numbers == nullptr || length <= 0)
		return -1;

	int left = 0;
	int right = length - 1;
	while (left <= right)
	{
		int middle = (right + left) >> 1;
		if (numbers[middle] != middle)
		{
			if (middle == 0 || numbers[middle - 1] == middle - 1)
				return middle;
			right = middle - 1;
		}
		else
			left = middle + 1;
	}

	if (left == length)
		return length;

	// 无效的输入，比如数组不是按要求排序的，
	// 或者有数字不在0到n-1范围之内
	return -1;
}



void Test(char* testName, int *data, int length, int expected)
{
	if (testName)
	{
		printf("%s begins:", testName);
	}

	if (expected == findLostN(data, 0, length-1))
	{
		printf("%s  passed !!!\r\n", testName);
	}
	else
	{
		printf("%s *** FAILED *** \r\n", testName);
	}
	printf("----------------\r\n");
}

void test1()
{
	int data[] = { 0,1,2,3,4,5,6,7,8,9,10 };
	Test("test1", data, sizeof(data)/sizeof(int), 11);
}

void test2()
{
	int data[] = {1, 2,3,4,5,6,7,8,9,10 };
	Test("test2", data, sizeof(data) / sizeof(int), 0);
}

//====================下面是作则的详细测试用例
// 缺失的是第一个数字0
void Test2_1()
{
	int numbers[] = { 1, 2, 3, 4, 5 };
	int expected = 0;
	Test("Test2_1", numbers, sizeof(numbers) / sizeof(int), expected);
}

// 缺失的是最后一个数字
void Test2_2()
{
	int numbers[] = { 0, 1, 2, 3, 4 };
	int expected = 5;
	Test("Test2_2", numbers, sizeof(numbers) / sizeof(int), expected);
}

// 缺失的是中间某个数字0
void Test2_3()
{
	int numbers[] = { 0, 1, 2, 4, 5 };
	int expected = 3;
	Test("Test2_3", numbers, sizeof(numbers) / sizeof(int), expected);
}

// 数组中只有一个数字，缺失的是第一个数字0
void Test2_4()
{
	int numbers[] = { 1 };
	int expected = 0;
	Test("Test2_4", numbers, sizeof(numbers) / sizeof(int), expected);
}

// 数组中只有一个数字，缺失的是最后一个数字1
void Test2_5()
{
	int numbers[] = { 0 };
	int expected = 1;
	Test("Test2_5", numbers, sizeof(numbers) / sizeof(int), expected);
}

// 空数组
void Test2_6()
{
	int expected = -1;
	Test("Test2_6", nullptr, 0, expected);
}


int main(int argc, char* argv[])
{
	test1();
	test2();

	Test2_1();
	Test2_2();
	Test2_3();
	Test2_4();
	Test2_5();
	Test2_6();

	cout << endl;
	system("pause");
	return 0;
}

