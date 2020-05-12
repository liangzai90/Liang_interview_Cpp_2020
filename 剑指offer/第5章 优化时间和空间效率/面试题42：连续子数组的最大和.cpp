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

// 面试题42：连续子数组的最大和
// 题目：输入一个整型数组，数组里有正数也有负数。数组中一个或连续的多个整
// 数组成一个子数组。求所有子数组的和的最大值。要求时间复杂度为O(n)。

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

bool bCheckValid(int* numbers, int length)
{
	if (numbers == nullptr || length <= 0)
		return false;
	else
		return true;
}

int MaxValueOfArrar(int* numbers, int length)
{
	int Max = numbers[0];///连续子数组最大值
	int NNumValue = numbers[0];//前n个数的值
	for (int i = 1; i < length; i++)
	{
		if (NNumValue < 0)
		{
			NNumValue = 0;
		}
		NNumValue += numbers[i];
		///要考虑所有数都为负数的特殊 测试用例
		if (NNumValue > Max)
		{
			Max = NNumValue;
		}
	}
	return Max;
}

void Test(char* testName, int* numbers, int length, int expectedValue)
{
	if (testName != nullptr)
		printf("%s begins: ", testName);

	if (bCheckValid(numbers, length))
	{
		if (MaxValueOfArrar(numbers, length) == expectedValue)
		{
			printf(" PASSED.\r\n");
		}
		else
		{
			printf("**FAILED**\r\n");
		}
	}
	else
	{
		printf("input is invalid...\r\n");
	}
}

void Test1()
{
	int array[] = { 100, -1, -2, -3, -4 };
	Test("test1", array, sizeof(array) / sizeof(int), 100);
}


void Test2()
{
	int array[] = { 100, 1, 2, 3, 4 };
	Test("test2", array, sizeof(array) / sizeof(int), 110);
}


void Test3()
{
	int array[] = { -1, -2, -3, 1,2 };
	Test("test3", array, sizeof(array) / sizeof(int), 3);
}


void Test4()
{
	int array[] = { 1, -1, -2,2, -3,3, -4 };
	Test("test4", array, sizeof(array) / sizeof(int), 3);
}


void Test5()
{
	int array[] = { 10, -100, 20, -10, 40,-20,10, };
	Test("test5", array, sizeof(array) / sizeof(int), 50);
}


void Test6()
{
	int array[] = { 1, -1, -2, -3, 6,-5,10,-1,3,-2 };
	Test("test6", array, sizeof(array) / sizeof(int), 13);
}


void Test7()
{
	int* array=nullptr;
	Test("test7", array, 0, 0);
}



//==================再补充几个作者的测试案例
// 1, -2, 3, 10, -4, 7, 2, -5
void Test8()
{
	int data[] = { 1, -2, 3, 10, -4, 7, 2, -5 };
	Test("Test8", data, sizeof(data) / sizeof(int), 18);
}


// 所有数字都是负数
// -2, -8, -1, -5, -9
void Test9()
{
	int data[] = { -2, -8, -1, -5, -9 };
	Test("Test9", data, sizeof(data) / sizeof(int), -1);
}

// -2, -8, -3, -5, -9
void Test9_2()
{
	int data[] = { -2, -8, -3, -5, -9 };
	Test("Test9_2", data, sizeof(data) / sizeof(int), -2);
}


// 所有数字都是正数
// 2, 8, 1, 5, 9
void Test10()
{
	int data[] = { 2, 8, 1, 5, 9 };
	Test("Test10", data, sizeof(data) / sizeof(int), 25);
}



//============这是作者的写法，代码简洁工整==========
//=====================================================
bool g_InvalidInput = false;

int FindGreatestSumOfSubArray(int *pData, int nLength)
{
	if ((pData == nullptr) || (nLength <= 0))
	{
		g_InvalidInput = true;
		return 0;
	}

	g_InvalidInput = false;

	int nCurSum = 0;
	int nGreatestSum = 0x80000000;
	for (int i = 0; i < nLength; ++i)
	{
		if (nCurSum <= 0)
			nCurSum = pData[i];
		else
			nCurSum += pData[i];

		if (nCurSum > nGreatestSum)
			nGreatestSum = nCurSum;
	}

	return nGreatestSum;
}
void Test_ref(char* testName, int* pData, int nLength, int expected, bool expectedFlag)
{
	if (testName != nullptr)
		printf("%s begins: \n", testName);

	int result = FindGreatestSumOfSubArray(pData, nLength);
	if (result == expected && expectedFlag == g_InvalidInput)
		printf("Passed.\n");
	else
		printf("Failed.\n");
}


//=====================================================

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
	Test9_2();
	Test10();


	cout << endl;
	system("pause");
	return 0;
}

