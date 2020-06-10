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

// 面试题57（二）：为s的连续正数序列
// 题目：输入一个正数s，打印出所有和为s的连续正数序列（至少含有两个数）。
// 例如输入15，由于1+2+3+4+5=4+5+6=7+8=15，所以结果打印出3个连续序列1～5、
// 4～6和7～8。


#include <iostream>
#include <algorithm>
#include <string>
#include <exception>
using namespace std;

//从iStart累加到iEnd,  iTotal > S,返回1，相等返回0，小于返回-1
int cmpTotalWithS(int iStart, int iEnd, int S)
{
	int iTotal = (iStart + iEnd)*(iEnd - iStart + 1) / 2;
	if (iTotal == S)
	{
		return 0;
	}
	else if (iTotal > S)
	{
		return 1;
	}
	else
	{
		return -1;
	}
}

void printSeq(int iSmall, int Big)
{
	cout << "printSeq:" << endl;
	for (int i = iSmall; i <= Big; i++)
	{
		cout << i <<", ";
	}
	cout << endl;
}

bool FindS(int S)
{
	if ( S < 3)
	{
		cout << "Invalid input" << endl;
		return false;
	}
	int iStart = S/2;
	int iEnd = S/2+1;
	bool bFind = false;
	while (iEnd >= 2 && iEnd>iStart && iStart>0)
	{
		if (0 == cmpTotalWithS(iStart, iEnd, S))
		{
			bFind = true;
			printSeq(iStart, iEnd);
			iEnd--;
			iStart = iEnd - 1;
		}
		else if(1 == cmpTotalWithS(iStart, iEnd, S)) {
			iEnd--;
			iStart = iEnd - 1;
		}
		else
		{
			iStart--;
		}
	}
	return bFind;
}


//=====================测试代码
void Test(const char* testName, int sum)
{
	if (testName != nullptr)
		printf("%s for %d begins: \r\n", testName,sum);

	FindS(sum);
	cout << "----------------" << endl;
}


//===============作者的写法
void PrintContinuousSequence(int small, int big);
void FindContinuousSequence(int sum)
{
	if (sum < 3)
		return;

	int small = 1;
	int big = 2;
	int middle = (1 + sum) / 2;
	int curSum = small + big;

	while (small < middle)
	{
		if (curSum == sum)
			PrintContinuousSequence(small, big);

		while (curSum > sum && small < middle)
		{
			curSum -= small;
			small++;

			if (curSum == sum)
				PrintContinuousSequence(small, big);
		}

		big++;
		curSum += big;
	}
}

void PrintContinuousSequence(int small, int big)
{
	for (int i = small; i <= big; ++i)
		printf("%d ", i);

	printf("\n");
}


// ====================测试代码====================
void Test2(const char* testName, int sum)
{
	if (testName != nullptr)
		printf("%s for %d begins: \n", testName, sum);

	FindContinuousSequence(sum);
}




int main(int argc, char* argv[])
{
	Test("test1", 1);
	Test("test2", 3);
	Test("test3", 4);
	Test("test4", 9);
	Test("test5", 15);
	Test("test6", 100);

	Test2("test1", 1);
	Test2("test2", 3);
	Test2("test3", 4);
	Test2("test4", 9);
	Test2("test5", 15);
	Test2("test6", 100);


	cout << endl;
	system("pause");
	return 0;
}

