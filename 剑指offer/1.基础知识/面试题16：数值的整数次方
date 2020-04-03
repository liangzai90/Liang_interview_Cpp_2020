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

// 面试题16：数值的整数次方
// 题目：实现函数double Power(double base, int exponent)，求base的exponent
// 次方。不得使用库函数，同时不需要考虑大数问题。


#include <iostream>
#include <string>
#include <exception>
#include <stdlib.h>
#include <stdio.h>
#include <cmath>
using namespace std;


/////整数次方，可能存在负数的情况。。。例如，5的-4次方问题。。。
bool g_InvalidInput = false;

//
bool equal(double num1, double num2)
{
	if ((num1 - num2 > -0.00000000001) && (num1 - num2 < 0.000000001))
		return true;
	else
		return false;
}


/////指数为整数的求解情况
double PowerWithUnsignedExponent(double base, unsigned int  absExponent)
{
	double result = 1.0f;
	for (int i = 1; i <= absExponent; i++)
	{
		result *= base;
	}
	return result;
}


//////////////////////解法1
double Power(double base, int exponent)
{
	if (0.0f == base )
	{
		g_InvalidInput = true;
		return 0.0f;
	}

	unsigned int absExponent = (unsigned int)(exponent);
	if (exponent < 0)
	{
		absExponent = (unsigned int)(-exponent);
	}

	double result = PowerWithUnsignedExponent(base, absExponent);
	if (exponent < 0)
	{
		result = 1.0f / result;
	}
	return result;
}




////////////////////解法2，递归调用
double PowWithUnsignedExponent_2(double base, unsigned int exponent)
{
	////0的0次方，当做1处理的
	if (0 == exponent )
		return 1;
	if (1 == exponent)
		return base;

	double result = PowWithUnsignedExponent_2(base, exponent >> 1);

	result *= result;

	if ((exponent & 0x1) == 1)
	{
		result *= base;
	}
	return result;
}

double Power_2(double base, int exponent)
{
	if (0.0f == base && exponent<0)
	{
		g_InvalidInput = true;
		return 0.0f;
	}

	unsigned int absExponent = (unsigned int)(exponent);
	if (exponent < 0)
	{
		absExponent = (unsigned int)(-exponent);
	}

	double result = PowWithUnsignedExponent_2(base, absExponent);
	if (exponent < 0)
	{
		result = 1.0f / result;
	}
	return result;
}



////////////////////////////测试用例
void test(const char* testName, double base, int exponent, double expectedResult, bool expectedFlag)
{
	double result = Power_2(base, exponent);
	if (equal(result, expectedResult) && g_InvalidInput == expectedFlag)
	{
		cout << testName << " Passed " << endl;
	}
	else
	{
		cout << testName << " *** FAILED ***" << endl;
	}

}


int main(int argc, char* argv[])
{
	////底数、指数都为正数
	test("Test1", 2, 10, 1024, false);
	
	//底数为负数，指数为正数
	test("Test2", -2, 3, -8, false);

	//指数为负数
	test("Test3", 2, -3, 1.0f/8, false);

	//指数为0
	test("Test4", 2, 0, 1, false);

	//底数、指数都为0
	test("Test5", 0, 0, 1, false);/////0的0次方，当做1处理的

	//底数为0，指数为正数
	test("Test6", 0, 2, 0.0f, false);

	//底数为0，指数为负数
	test("Test7", 0, -4, 0.0f, true);



	cout << endl;
	system("pause");
	return 0;
}
