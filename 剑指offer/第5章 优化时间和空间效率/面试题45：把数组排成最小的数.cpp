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

// 面试题45：把数组排成最小的数
// 题目：输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼
// 接出的所有数字中最小的一个。例如输入数组{3, 32, 321}，则打印出这3个数
// 字能排成的最小数字321323。

#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
using namespace std;


//比较2个数字，如果A “小于” B，返回true
bool NumLess(int A, int B)
{
	char arrA[50];
	char arrB[50];
	snprintf(arrA, sizeof(arrA), "%d", A);
	snprintf(arrB, sizeof(arrB), "%d", B);
	char seriesAB[100];
	char seriesBA[100];
	snprintf(seriesAB, sizeof(seriesAB), "%s%s", arrA, arrB);
	snprintf(seriesBA, sizeof(seriesBA), "%s%s", arrB, arrA);

	int iResult = strcmp(seriesAB, seriesBA);
	if (iResult >= 0)
		return false;
	else
		return true;
}

void groupMinNum(int* arr, int length)
{
	std::sort(arr, arr+length , NumLess);

	for (int i = 0; i < length; i++)
		cout << *(arr + i);

	printf("\r\n -------------------------- \r\n");
}



//=================== 测试案例不能少 ======================

void Test(const char* testName, int* arr, int length, const char* expectedResult)
{
	if (testName != nullptr)
		printf("%s begins:\r\n", testName);

	if (expectedResult != nullptr)
		printf("Expected result is: %s \r\n", expectedResult);

	printf("Actucal  result is: ");

	groupMinNum(arr, length);
}

void Test1()
{
	int numbers[] = { 3, 5, 1, 4, 2 };
	Test("test1", numbers, sizeof(numbers) / sizeof(int), "12345");
}

void Test2()
{
	int numbers[] = { 3, 32, 321 };
	Test("test1", numbers, sizeof(numbers) / sizeof(int), "321323");
}

void Test3()
{
	int numbers[] = { 3,323,32123 };
	Test("test1", numbers, sizeof(numbers) / sizeof(int), "321233233");
}

void Test4()
{
	int numbers[] = { 1,11,111};
	Test("test1", numbers, sizeof(numbers) / sizeof(int), "111111");
}

void Test5()
{
	int numbers[] = { 321 };
	Test("test1", numbers, sizeof(numbers) / sizeof(int), "321");
}

void Test6()
{
	Test("test1", nullptr, 0, "Don't print anything.");
}


void Test7()
{
	int numbers[] = { 1,11,2,111 };
	Test("test1", numbers, sizeof(numbers) / sizeof(int), "1111112");
}




//====================== 作者的解法
int compare(const void* strNumber1, const void* strNumber2);
//int型整数用十进制表示最多只有10位
const int g_MaxNumberLength = 10;
char* g_StrCombine1 = new char[g_MaxNumberLength * 2 + 1];
char* g_StrCombine2 = new char[g_MaxNumberLength * 2 + 1];

void PrintMinNumber(const int* numbers, int length)
{
	if (numbers == nullptr || length <= 0)
		return;

	char** strNumbers = (char**)(new int[length]);
	for (int i = 0; i < length; ++i)
	{
		strNumbers[i] = new char[g_MaxNumberLength + 1];
		sprintf(strNumbers[i], "%d", numbers[i]);
	}

	qsort(strNumbers, length, sizeof(char*), compare);

	for (int i = 0; i < length; i++)
	{
		printf("%s", strNumbers[i]);
	}
	printf("\r\n");

	for (int i = 0; i < length; ++i)
	{
		delete[] strNumbers[i];
	}
	delete[] strNumbers;
}


// 如果[strNumber1][strNumber2] > [strNumber2][strNumber1], 返回值大于0
// 如果[strNumber1][strNumber2] = [strNumber2][strNumber1], 返回值等于0
// 如果[strNumber1][strNumber2] < [strNumber2][strNumber1], 返回值小于0
int compare(const void* strNumber1, const void* strNumber2)
{
	// [strNumber1][strNumber2]
	strcpy(g_StrCombine1, *(const char**)strNumber1);
	strcat(g_StrCombine1, *(const char**)strNumber2);

	// [strNumber2][strNumber1]
	strcpy(g_StrCombine2, *(const char**)strNumber2);
	strcat(g_StrCombine2, *(const char**)strNumber1);

	return strcmp(g_StrCombine1, g_StrCombine2);
}

void Test_solution2()
{
	int numbers[] = { 3, 5, 1, 4, 2 };
	printf("--------solution2---------\r\n");
	printf("Expected : 12345 \r\n");
	printf("Actual is: ");
	PrintMinNumber(numbers, sizeof(numbers) / sizeof(int));
	printf("\r\n");
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

	Test_solution2();


	//cout << "8,321:" << NumLess(8, 321) << endl;
	//cout << "321,32:" << NumLess(321, 32) << endl;
	//int arr[] = { 8, 321,32, 9 };
	//int length = sizeof(arr) / sizeof(int);
	//std::sort(arr, arr + length , NumLess);
	//printf("the result is: \r\n");
	//for (int i = 0; i < length; i++)
	//	cout << *(arr + i)<<",";


	cout << endl;
	system("pause");
	return 0;
}

