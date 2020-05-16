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
	/*
	level =1, start:0,          end:9
                  startIndex:0,     endIndex:9
--------------------------------------------------
	level =2, start:10,         end:99
		  startIndex:10,    endIndex: 189 = (end - start +1)*level + endIndex;
--------------------------------------------------
	level =3, start:100,        end:999
		  startIndex:190,   endIndex:1989
--------------------------------------------------
	*/
	int leftGap = N - startIndex;
	int numA = leftGap / level + start; //是哪个数
	int numB = leftGap % level;//该数的第几位。从0开始计数的

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

/*
这一题的测试用例非常重要！！！！
各种边界条件测试
为0的情况，为1的情况，为9的情况，为10的情况，
99，,100，等等。通过边界测试，会发现自己代码的很多漏洞。。
*/
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





//================ 下面的解法，是作者的 ====================
int countOfIntegers(int digits);
int digitAtIndex(int index, int digits);
int beginNumber(int digits);

int digitAtIndex(int index)
{
	if (index < 0)
		return -1;

	int digits = 1;
	while (true)
	{
		int numbers = countOfIntegers(digits);
		if (index < numbers * digits)
			return digitAtIndex(index, digits);

		index -= digits * numbers;
		digits++;
	}
	return -1;
}

//10, 90, 900
int countOfIntegers(int digits)
{
	if (digits == 1)
		return 10;

	int count = (int)std::pow(10, digits - 1);
	return 9 * count;
}


//这里的index，相当于是一个偏移量了。
//0, 10, 190...
int digitAtIndex(int index, int digits)
{
	//该索引落在 哪个 数字 上 .
	int number = beginNumber(digits) + index / digits;
	int indexFromRight = digits - index % digits;
	for (int i = 1; i < indexFromRight; ++i)
	{
		number /= 10;//12345
	}

	return number % 10;
}

//0, 10, 100, 1000
int beginNumber(int digits)
{
	if (digits == 1)
		return 0;

	return (int)std::pow(10, digits - 1);
}

void test2(const char* testName, int inputIndex, int expectedOutput)
{
	if (digitAtIndex(inputIndex) == expectedOutput)
		cout << testName << " passed. " << endl;
	else
		cout << testName << " FAILED***** " << endl;
}

void test2()
{
	int a = getValueOfNumIndex(10, 1);
	test2("Test1", 0, 0);
	test2("Test2", 1, 1);
	test2("Test3", 9, 9);
	test2("Test4", 10, 1);
	test2("Test5", 189, 9);  // 数字99的最后一位，9
	test2("Test6", 190, 1);  // 数字100的第一位，1
	test2("Test7", 1000, 3); // 数字370的第一位，3
	test2("Test8", 1001, 7); // 数字370的第二位，7
	test2("Test9", 1002, 0); // 数字370的第三位，0
}


int main(int argc, char* argv[])
{
	test();
	test2();

	cout << endl;
	system("pause");
	return 0;
}
