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

// 面试题49：丑数
// 题目：我们把只包含因子2、3和5的数称作丑数（Ugly Number）。求按从小到
// 大的顺序的第1500个丑数。例如6、8都是丑数，但14不是，因为它包含因子7。
// 习惯上我们把1当做第一个丑数。



#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

bool IsUgly(int number)
{
	while (number % 2 == 0)
		number /= 2;
	while (number % 3 == 0)
		number /= 3;
	while (number % 5 == 0)
		number /= 5;
	if (1 == number)
		return true;
	else
		return false;
}

int GetUglyNumber_Solution1(int index)
{
	if (index <= 0)
		return 0;

	int number = 0;
	int uglyFound = 0;
	while (uglyFound < index)
	{
		++number;
		if (IsUgly(number))
			++uglyFound;
	}
	return number;
}


int Min(int A2, int A3, int A5)
{
	int min1 = A2 < A3 ? A2 : A3;
	int min2 = min1 < A5 ? min1 : A5;
	return min2;
}


int GetUglyNumber_Solution2(int index)
{
	if (index <= 0)
		return 0;
	int* uglyArr = new int[index];
	int *uglyA2 = uglyArr;
	int *uglyA3 = uglyArr;
	int *uglyA5 = uglyArr;
	uglyArr[0] = 1;
	int countUgly = 1;
	while (countUgly < index)
	{
		int min = Min(*uglyA2 * 2, *uglyA3 * 3, *uglyA5 * 5);
		uglyArr[countUgly] = min;

		while (*uglyA2 * 2 <= uglyArr[countUgly])
			++uglyA2;
		while (*uglyA3 * 3 <= uglyArr[countUgly])
			++uglyA3;
		while (*uglyA5 * 5 <= uglyArr[countUgly])
			++uglyA5;

		++countUgly;
	}

	int result = uglyArr[countUgly-1];
	delete uglyArr;
	return result;
}


// ====================测试代码====================
void Test(int index, int expected)
{
	if (GetUglyNumber_Solution1(index) == expected)
		printf("solution1 passed\n");
	else
		printf("solution1 failed\n");

	if (GetUglyNumber_Solution2(index) == expected)
		printf("solution2 passed\n");
	else
		printf("solution2 failed\n");
}


int main(int argc, char* argv[])
{
	Test(1, 1);

	Test(2, 2);
	Test(3, 3);
	Test(4, 4);
	Test(5, 5);
	Test(6, 6);
	Test(7, 8);
	Test(8, 9);
	Test(9, 10);
	Test(10, 12);
	Test(11, 15);

	Test(1500, 859963392);

	Test(0, 0);

	cout << endl;
	system("pause");
	return 0;
}

