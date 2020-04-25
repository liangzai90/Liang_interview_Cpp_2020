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

// 面试题15：二进制中1的个数
// 题目：请实现一个函数，输入一个整数，输出该数二进制表示中1的个数。例如
// 把9表示成二进制是1001，有2位是1。因此如果输入9，该函数输出2。


#include <iostream>
#include <string>
#include <exception>
#include <stdlib.h>
#include <stdio.h>
using namespace std;


/////为了避免死循环（n为负数），我们可以不右移n，先把n和1做与运算，判断n的低位是不是1.
//接着把1左移1位（得到2（二进制表示为10）），再和n做与运算....
int NumberOf1_Solution1(int n)
{
	int count = 0;
	unsigned int flag = 1;
	while (flag)
	{
		if (n & flag)
		{
			count++;
		}
		flag = flag << 1;
	}
	return count;
}


///////把一个整数减去1，再和原整数做与运算，会把该整数最右边的1变成0.
int NumberOf2_Solution2(int n)
{
	int count = 0;
	while (n)
	{
		count++;
		n = (n - 1)&n;
	}
	return count;
}


///////===================测试代码=======================
void test(int number, int expected)
{
	int actual = NumberOf1_Solution1(number);
	if (actual == expected)
	{
		///// %p 是转为十六进制的输出
		printf("Solution1:Test for %p  passed.\r\n", number);
	}
	else
	{
		printf("Solution1:Test for %p  ***FAILED***.\r\n", number);
	}

	actual = NumberOf2_Solution2(number);
	if (actual == expected)
	{
		printf("Solution2:Test for %p  passed.\r\n", number);
	}
	else
	{
		printf("Solution2:Test for %p  ***FAILED***.\r\n", number);
	}
	cout << endl;
}



int main(int argc, char* argv[])
{
	//输入0，期待输出0
	test(0, 0);

	//输入1，期待的输出是1
	test(1, 1);

	//输入10，期待的输出是2
	test(10, 2);

	//输入0x7FFFFFFF期待的输出是31
	test(0x7FFFFFFF, 31);

	//输入0xFFFFFFFF（负数），期待的输出是32
	test(0xFFFFFFFF, 32);

	//输入0x80000000（负数），期待的输出是1
	test(0x80000000, 1);


	cout << endl;
	system("pause");
	return 0;
}

