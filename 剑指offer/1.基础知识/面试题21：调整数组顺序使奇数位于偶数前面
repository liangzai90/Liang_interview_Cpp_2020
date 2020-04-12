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

// 面试题21：调整数组顺序使奇数位于偶数前面
// 题目：输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有
// 奇数位于数组的前半部分，所有偶数位于数组的后半部分。


#include <iostream>
using namespace std;




////方法1：
////arr[1,2,3,4,5]
void SortArr(int* arr, int arrLength)
{
	if (arr == nullptr || arrLength <= 0)
	{
		return;
	}

	int *pBegin = arr;
	int *pEnd = arr+arrLength - 1;
	///奇数在前，偶数在后
	while (pBegin < pEnd)
	{
		///iEnd，偶数忽略，奇数停下
		while (*pEnd % 2 == 0 && pBegin < pEnd)
		{
			pEnd--;
		}

		///iBegin，奇数忽略，偶数停下
		while (*pBegin % 2 == 1 && pBegin < pEnd)
		{
			pBegin++;
		}
		if (pBegin < pEnd)
		{
			int iTemp = *pEnd;
			*pEnd = *pBegin;
			*pBegin = iTemp;
		}
	}

	//printf("Sorted result:");
	//////打印输出arr
	//for (int i = 0; i < arrLength; i++)
	//{
	//	printf("%d,", arr[i]);
	//}
	//printf("\r\n");
}



//================方法2：=================
////抽象逻辑框架，利用函数指针，来解耦函数
void Reorder(int *pData, unsigned int length, bool(*func)(int))
{
	if (pData == nullptr || length == 0)
	{
		return;
	}

	int *pBegin = pData;
	int *pEnd = pData + length - 1;
	while (pBegin < pEnd)
	{
		while (pBegin < pEnd && !func(*pBegin))
		{
			pBegin++;
		}

		while (pBegin < pEnd && (func(*pEnd)))
		{
			pEnd--;
		}

		if (pBegin < pEnd)
		{
			int temp = *pBegin;
			*pBegin = *pEnd;
			*pEnd = temp;
		}
	}
}


////判断标准解耦 
////1.奇数在前，偶数在后
////2.负数在前，非负数在后
////3.能被3整除的数在前，其他数在后
bool isEven(int n)
{
	return (n & 1) == 0;
}

void ReorderOddEven(int *pData, unsigned int length)
{
	Reorder(pData, length, isEven);
}


///================测试代码===================
void PrintArray(int numbers[], int length)
{
	if (length < 0)
	{
		return;
	}

	for (int i = 0; i < length; i++)
	{
		printf("%d \t", numbers[i]);
	}

	printf("\r\n");
}

void Test(char* testName, int numbers[], int length)
{
	if (testName != nullptr)
	{
		printf("%s begins: \r\n", testName);
	}
	int* copy = new int[length];
	for (int i = 0; i < length; i++)
	{
		copy[i] = numbers[i];
	}
	printf("Test for solution 1:\r\n");
	PrintArray(numbers, length);
	SortArr(numbers, length);
	PrintArray(numbers, length);

	printf("Test for solution 2:\r\n");
	PrintArray(copy, length);
	ReorderOddEven(copy, length);
	PrintArray(copy, length);

	delete[] copy;
	printf("-----------------------------------------------\r\n\r\n");
}

void Test1()
{
	int numbers[] = { 1, 2, 3, 4, 5, 6, 7 };
	Test("Test1", numbers, sizeof(numbers) / sizeof(int));
}


void Test2()
{
	int numbers[] = { 2, 4, 6, 1, 3, 5, 7 };
	Test("Test2", numbers, sizeof(numbers) / sizeof(int));
}

void Test3()
{
	int numbers[] = { 1, 3, 5, 7, 2, 4, 6 };
	Test("Test3", numbers, sizeof(numbers) / sizeof(int));
}

void Test4()
{
	int numbers[] = { 1 };
	Test("Test4", numbers, sizeof(numbers) / sizeof(int));
}

void Test5()
{
	int numbers[] = { 2 };
	Test("Test5", numbers, sizeof(numbers) / sizeof(int));
}

void Test6()
{
	Test("Test6", nullptr, 0);
}




int main(int argc, char* argv[])
{
	Test1();
	Test2();
	Test3();
	Test4();
	Test5();
	Test6();

	cout << endl;
	system("pause");
	return 0;
}


