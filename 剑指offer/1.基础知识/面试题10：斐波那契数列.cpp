/********************************
《剑指offer》做题笔记

// 面试题10：斐波那契数列
// 题目：写一个函数，输入n，求斐波那契（Fibonacci）数列的第n项。
// f(0)=0, 
// f(1)=1,
// f(n)= f(n-1) + f(n-2)
//
*******************************************/

#include <iostream>
#include <string>
#include <exception>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

//打印斐波拉契数列
int printFeibolaqi1(int n)
{
	if (0 == n)
	{
		return 0;
	}
	if (1 == n)
	{
		return 1;
	}
	return printFeibolaqi1(n - 2) + printFeibolaqi1(n - 1);
}


////////////青蛙跳台阶，一次跳1步或者2步。考察数学建模能力。。差的要命啊！！！
//循环实现
int printFeibolaqi2(int n)
{
	if (0 == n)
	{
		return 0;
	}
	if (1 == n)
	{
		return 1;
	}
	int iStart1 = 0;
	int iStart2 = 1;
	int result = 0;
	for (int i = 2; i <= n; i++)
	{
// 		iStart1 = iStart2;
// 		iStart2 = i;

		result = iStart1 + iStart2;

		iStart1 = iStart2;
		iStart2 = result;
	}

	return result;
}


////青蛙跳台阶，一次可以跳1,2,3..n步
int superJump(int n)
{
	int* jump = new int(n + 1);
	jump[0] = 0;
	jump[1] = 1;
	jump[2] = 2;
	if (n < 0)
	{
		return -1;
	}
	else if (n < 3)
	{
		return jump[n];
	}

	for (int i = 3; i <= n; i++)
	{
		jump[i] = 2 * jump[i - 1];
	}

	return jump[n];
}


//==========================测试代码========================
void Test(int n, int expected)
{
	if (printFeibolaqi1(n) == expected)
	{
		printf("Test for %d in solution1 passed.\r\n", n);
	}
	if (printFeibolaqi2(n) == expected)
	{
		printf("Test for %d in solution2 passed.\r\n", n);
	}

	printf("\r\n");
}

void test0_10()
{
	Test(0, 0);
	Test(1, 1);
	Test(2, 1);
	Test(3, 2);
	Test(4, 3);
	Test(5, 5);
	Test(6, 8);
	Test(7, 13);
	Test(8, 21);
	Test(9, 34);
	Test(10, 55);

	//测试一个较大的数字
	Test(40, 102334155);
}

int main(int argc, char* argv[])
{
	test0_10();



	cout << endl;
	system("pause");
	return 0;
}


