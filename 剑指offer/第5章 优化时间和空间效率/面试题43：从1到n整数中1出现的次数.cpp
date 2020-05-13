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

// 面试题43：从1到n整数中1出现的次数
// 题目：输入一个整数n，求从1到n这n个整数的十进制表示中1出现的次数。例如
// 输入12，从1到12这些整数中包含1 的数字有1，10，11和12，1一共出现了5次。

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;



//==================================这是我写的代码
int OneNumber(int number)
{
	if (number <= 0)
		return 0;

	int iCount = 0;
	while (number > 0)
	{
		if (number % 10 == 1)
		{
			iCount++;
		}
		// 每次while循环，就移动一位数字（之前写错地方了，写在了if，造成了死循环）
		number = number / 10;
	}
	return iCount;
}

int ToNNumber(int N)
{
	int iTotal = 0;
	for (int i = 0; i <= N; i++)
	{
		iTotal += OneNumber(i);
	}
	return iTotal;
}



//====================这是作者写的====代码更加严谨

//方法1 -------- 效率不高
int NumberOf1(unsigned int n)
{
	int number = 0;
	while (n)
	{
		if (n % 10 == 1)
		{
			number++;
		}

		n = n / 10;
	}
	return number;
}


int NumberOf1Between1AndN_Solution1(unsigned int n)
{
	int number = 0;
	for (unsigned int i = 1; i <= n; ++i)
	{
		number += NumberOf1(i);
	}

	return number;
}

//方法2  ---- 效率更高
int NumberOf1(const char* strN);
int PowerBase10(unsigned int n);

int NumberOf1Between1AndN_Solution2(int n)
{
	if (n <= 0)
		return 0;
	char strN[50];
	sprintf(strN, "%d", n);
	//现将数字转为字符串，然后找规律求出1出现次数
	return NumberOf1(strN);
}

int NumberOf1(const char* strN)
{
	if (!strN || *strN<'0' || *strN>'9' || *strN == '\0')
		return 0;

	int first = *strN - '0';
	unsigned int length = static_cast<unsigned int>(strlen(strN));

	if (length == 1 && first == 0)
		return 0;
	if (length == 1 && first > 0)
		return 1;

	//假设strN是"21345"
	//numFirstDigit是数字 10000-19999的第一位中1的数目
	int numFirstDigit = 0;
	if (first > 1)
		numFirstDigit = PowerBase10(length - 1);
	else if (first == 1)
		numFirstDigit = atoi(strN + 1) + 1;



	//******* 这一部分，理解比较困难 *******
	//numOtherDigits 是 01346-21345 除了第一位（比如，这里是万位）之外的数位中，1的数目
	int numOtherDigits = first * (length - 1) * PowerBase10(length - 2);


	//numRecursive 是 1-1345 中1的数目
	int numRecursive = NumberOf1(strN + 1);

	return numFirstDigit + numOtherDigits + numRecursive;
}

int PowerBase10(unsigned int n)
{
	int result = 1;
	for (unsigned int i = 0; i < n; ++i)
	{
		result *= 10;
	}
	return result;
}




//=====================================================
void Test(const char* testName, int n, int expected)
{
	if (testName != nullptr)
		printf("%s begins: \r\n", testName);

	if (ToNNumber(n) == expected)
		printf("passed.\r\n");
	else
		printf("**FAILED**\r\n");

	printf("\r\n");
}

void Test()
{
	Test("Test1", 1, 1);
	Test("Test2", 5, 1);
	Test("Test3", 10, 2);
	Test("Test4", 55, 16);
	Test("Test5", 99, 20);
	Test("Test6", 10000, 4001);
	Test("Test7", 21345, 18821);
	Test("Test8", 0, 0);
}


int main(int argc, char* argv[])
{
	Test();

	if (18821 == NumberOf1Between1AndN_Solution2(21345))
		printf("****** solution2 pass.****** \r\n");
	else
		printf("****** solution2 FAILED.****** \r\n");

	cout << endl;
	system("pause");
	return 0;
}





