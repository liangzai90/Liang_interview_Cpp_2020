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

// 面试题14：剪绳子
// 题目：给你一根长度为n绳子，请把绳子剪成m段（m、n都是整数，n>1并且m≥1）。
// 每段的绳子的长度记为k[0]、k[1]、……、k[m]。k[0]*k[1]*…*k[m]可能的最大乘
// 积是多少？例如当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此
// 时得到最大的乘积18。


#include <iostream>
#include <string>
#include <exception>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

//===========================动态规划======================

int maxProductAfterCutting_solution1(int length)
{
	if (length < 2)
	{
		return 0;
	}
	if (length == 2)
	{
		return 1;
	}
	if (length == 3)
	{
		return 2;
	}

	int* products = new int[length + 1];



	//////这里的边界值确定是比较困难的*****prouct[0]~product[3]是特殊边界
	products[0] = 0;
	products[1] = 1;
	products[2] = 2;
	products[3] = 3;

	int max = 0;
	for (int i = 4; i <= length; i++)
	{
		max = 0;
		for (int j = 1; j <= i / 2; j++)
		{
			int product = products[j] * products[i - j];
			if (max < product)
			{
				max = product;
			}
			products[i] = max;
		}
	}

	max = products[length];
	delete[] products;

	cout << "  * "<< max << " * ";
	return max;
}



///////===================测试代码=======================
void test(const char* testName, int length, int expected)
{
	int result1 = maxProductAfterCutting_solution1(length);
	if (result1 == expected)
	{
		cout << "Solution1 for " << testName << " passed." << endl;
	}
	else
	{
		cout << "Solution1 for " << testName << " ***FAILED***." << endl;
	}
}


void test1()
{
	int length = 1;
	int expected = 0;
	test("test1", length, expected);
}

void test2()
{
	int length = 2;
	int expected = 1;
	test("test2", length, expected);
}

void test3()
{
	int length = 3;
	int expected = 2;
	test("test3", length, expected);
}

void test4()
{
	int length = 4;
	int expected = 4;
	test("test4", length, expected);
}

void test5()
{
	int length = 5;
	int expected = 6;
	test("test5", length, expected);
}

void test6()
{
	int length = 6;
	int expected = 9;
	test("test6", length, expected);
}

void test7()
{
	int length = 7;
	int expected = 12;
	test("test7", length, expected);
}




int main(int argc, char* argv[])
{
	test1();
	test2();
	test3();
	test4();
	test5();
	test6();
	test7();


	cout << endl;
	system("pause");
	return 0;
}
