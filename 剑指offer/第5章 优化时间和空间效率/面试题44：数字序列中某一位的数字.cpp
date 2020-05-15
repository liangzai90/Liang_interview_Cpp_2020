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

// 面试题44：数字序列中某一位的数字
// 题目：数字以0123456789101112131415…的格式序列化到一个字符序列中。在这
// 个序列中，第5位（从0开始计数）是5，第13位是1，第19位是4，等等。请写一
// 个函数求任意位对应的数字。

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int getPow10(int X)
{
	if (X <= 0)
		return 0;

	int iResult = 1;
	for (int i = 0; i < X; i++)
	{
		iResult *= 10;
	}
	return iResult;
}

//索引从0开始
int getValueOfNumIndex(int value , int index)
{
	char str[50];
	snprintf(str, sizeof(str), "%d", value);
	char iTemp = str[index];
	return  atoi(&iTemp);
}

///查找N再哪个区间,0~9， 10~99， 100~999， 等等
int getValueOfIndexN(int N)
{
	if (N <= 0)
		return 0;

	int level = 1;
	int start = 0;
	int end = 9;
	int startIndex = 0;
	int endIndex = 9;

	while (!(N >= startIndex && N <= endIndex))
	{
		///遍历每个 level 
		start = getPow10(level);
		end = getPow10(level+1)-1;
		level++;

		//再根据level计算每个 level 在数字中的 起始位置
		startIndex = endIndex + 1;
		endIndex = (end - start +1)*level + endIndex;
	}

	int leftValue = N - startIndex;
	int numA = leftValue / level + start; //是哪个数
	int numB = leftValue % level;//该数的第几位。从0开始计数的

	int iResult = getValueOfNumIndex(numA, numB);

	return getValueOfNumIndex(numA, numB);
}




//======================测试代码
void test(const char* testName, int inputIndex, int expectedOutput)
{
	if (getValueOfIndexN(inputIndex) == expectedOutput)
		cout << testName << " passed..." << endl;
	else
		cout << testName << " **FAILED**.." << endl;
}

void test()
{
	int a = getValueOfNumIndex(10, 1);
	test("Test1", 0, 0);
	test("Test2", 1, 1);
	test("Test3", 9, 9);
	test("Test4", 10, 1);
	test("Test5", 189, 9);  // 数字99的最后一位，9
	test("Test6", 190, 1);  // 数字100的第一位，1
	test("Test7", 1000, 3); // 数字370的第一位，3
	test("Test8", 1001, 7); // 数字370的第二位，7
	test("Test9", 1002, 0); // 数字370的第三位，0
}





int main(int argc, char* argv[])
{
	test();


	cout << endl;
	system("pause");
	return 0;
}



