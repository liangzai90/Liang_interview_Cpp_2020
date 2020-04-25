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

// 面试题17：打印1到最大的n位数
// 题目：输入数字n，按顺序打印出从1最大的n位十进制数。比如输入3，则
// 打印出1、2、3一直到最大的3位数即999。


/////////大数问题
////1.在字符串表达式的数字上模拟加法；2.把字符串表达式的数字打印出来

#include <iostream>
#include <string>
#include <exception>
#include <stdlib.h>
#include <stdio.h>
#include <cmath>
using namespace std;


/////////////////////////////////////////解法1：利用大数的加法处理
void PrintNumber(char* number);
bool Increment(char* number);
void Print1ToMaxOfNDigitsRecursively(char* number, int length, int index);

////大数的加法
bool Increment(char* number)
{
	bool isOverflow = false;
	int nTakeOver = 0;
	int nLength = strlen(number);

	//////产生进位的时候，for循环会执行n多次
	for (int i = nLength - 1; i >= 0; i--)
	{
		int nSum = number[i] - '0' + nTakeOver; ////这里有进位****
		if (i == nLength - 1)
		{
			nSum++;
		}
		if (nSum >= 10)
		{
			if (i == 0)
			{
				isOverflow = true;////最高位为0，溢出
			}
			else
			{
				nSum -= 10;
				nTakeOver = 1;
				number[i] = '0' + nSum;
			}
		}
		else
		{
			number[i] = '0' + nSum;
			break;
		}
	}

	return isOverflow;
}


///////////////打印大数（避免打印094这类数字，要打印94）
void PrintNumber(char* number)
{
	bool isBeginning0 = true;
	int nLength = strlen(number);
	for (int i = 0; i < nLength; i++)
	{
		if (isBeginning0 && number[i] != '0')
		{
			isBeginning0 = false;
		}
		if (!isBeginning0)
		{
			printf("%c", number[i]);
		}
	}
	printf("\t");
}



void Print1ToMaxOfNDigits_1(int n)
{
	if (n < 0)
	{
		return;
	}

	char* number = new char[n + 1];
	memset(number, '0', n);/////初始化为字符串 '0'，后面要用这里面的值进行加减的
	number[n] = '\0';

	while (!Increment(number))
	{
		PrintNumber(number);
	}
	delete[] number;
}




///////////////////////////////解法2:全排列
void Print1ToMaxOfNDigits_2(int n)
{
	if (n <= 0)
	{
		return;
	}

	char* number = new char[n + 1];
	number[n] = '\0';
	for (int i = 0; i < 10; i++)
	{
		number[0] = i + '0';
		Print1ToMaxOfNDigitsRecursively(number, n, 0);
	}
	delete[] number;
}

void Print1ToMaxOfNDigitsRecursively(char* number, int length, int index)
{
	if (index == length - 1)
	{
		PrintNumber(number);
		return;
	}

	for (int i = 0; i < 10; i++)
	{
		number[index + 1] = i + '0';
		Print1ToMaxOfNDigitsRecursively(number, length, index + 1);
	}
}






////////////////////////////测试用例
void test(int n)
{
	printf("Test for %d begins: \r\n", n);

	Print1ToMaxOfNDigits_2(n);

	printf("\r\n Test for %d ends.\r\n", n);
}


int main(int argc, char* argv[])
{
	test(1);
	test(2);
	test(3);
	test(0);
	test(-1);


	cout << endl;
	system("pause");
	return 0;
}
