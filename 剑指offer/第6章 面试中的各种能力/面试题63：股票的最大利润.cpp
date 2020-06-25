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

// 面试题63：股票的最大利润
// 题目：假设把某股票的价格按照时间先后顺序存储在数组中，请问买卖交易该股
// 票可能获得的利润是多少？例如一只股票在某些时间节点的价格为{9, 11, 8, 5,
// 7, 12, 16, 14}。如果我们能在价格为5的时候买入并在价格为16时卖出，则能
// 收获最大的利润11。

/*
这类题有个特点，就是可以直接用2层循环解决。但是效率很低；
而且，前后2层循环之间，还有特别的联系。
比如，这里，前一个数，就是 数组 [0~i-1] 里面最小的那个值
而，这个最小值，可以在遍历的时候，顺便保存起来。从2开始遍历即可。。。。
*/

#include <iostream>
#include <cstdio>
#include <math.h>
#include <list>
#include <vector>
using namespace std;

//我的解法，不可取，不可靠，过于简单粗暴
int MaxProfile(const int *numbers, int length)
{
	if (length <= 1 || numbers == nullptr)
	{
		return 0;
	}
	int GapDiff = numbers[1] - numbers[0];
	for (int i = 0; i < length; i++)
	{
		for (int j = i + 1; j < length ; j++)
		{
			if (numbers[j] - numbers[i] > GapDiff)
			{
				GapDiff = numbers[j] - numbers[i];
			}
		}
	}
 	return GapDiff;
}


//=======作者的解法，一层for循环。 每次循环，保留之前的最小值数值（就可以省去一层循环）
////TODO:这种通过保存中间变量的方式，可以去掉一层循环。。应用非常广泛！！！！
////TODO:这种通过保存中间变量的方式，可以去掉一层循环。。应用非常广泛！！！！
////TODO:这种通过保存中间变量的方式，可以去掉一层循环。。应用非常广泛！！！！

int MaxDiff(const int *numbers, unsigned length)
{
	if (numbers == nullptr && length < 2)
	{
		return 0;
	}

	//保存最小值
	int min = numbers[0];
	int maxDiff = numbers[1] - min;

	for (int i = 2; i < length; i++)
	{
		if (numbers[i - 1] < min)
		{
			min = numbers[i - 1];//更新最小值
		}
		int currentDiff = numbers[i] - min;
		if (currentDiff > maxDiff)
		{
			maxDiff = currentDiff;
		}
	}
	return maxDiff;
}


//================可以用dp表来辅助理解
//dp表存放的就是当前的最小值
int MaxDiff2(const int *numbers, unsigned length)
{
	if (numbers == nullptr && length < 2)
	{
		return 0;
	}
	//保存最小值
	int* minDp = new int[length];
	minDp[0] = numbers[0];
	int maxDiff = numbers[1] - minDp[0];

	for (int i = 2; i < length; i++)
	{
		if (numbers[i - 1] < minDp[i-2])
		{
			minDp[i-1] = numbers[i - 1];//更新最小值
		}
		else
		{
			minDp[i - 1] = minDp[i - 2];
		}
		int currentDiff = numbers[i] - minDp[i-1];
		if (currentDiff > maxDiff)
		{
			maxDiff = currentDiff;
		}
	}

	cout << "minDp:=====";
	for (int i = 0; i < length-1; i++)
	{
		cout << minDp[i] << ",";
	}
	cout << endl;
	// numbers {4,1,3,2,5 }
	//    dp   [4,1,1,1, ]

	// numbers {9,11,8,5,7,12,16,14}
	//    dp   [9,9, 8,5,5, 5, 5,  ]

	//这里要把握循环的起点，从2开始；
	// 将numbers[i-1] 和dp[i-2]比较

	return maxDiff;
}




//===================== test code ===================
void Test(const char* testName, const int* numbers, unsigned int length, int expected)
{
	if (testName != nullptr)
		printf("%s begins: ", testName);

	//if (MaxProfile(numbers, length) == expected)
	//	printf("PASSED .\r\n");
	//else
	//	printf("**** FAILED ****\r\n");


	if (MaxDiff(numbers, length) == expected)
		printf("PASSED .\r\n");
	else
		printf("**** FAILED ****\r\n");

}

void Test1()
{
	int numbers[] = { 4,1,3,2,5 };
	Test("Test1", numbers, sizeof(numbers) / sizeof(int), 4);
}


//价格递增
void Test2()
{
	int numbers[] = { 1,2,4,7,11,16 };
	Test("Test2", numbers, sizeof(numbers) / sizeof(int), 15);
}

//价格递减
void Test3()
{
	int numbers[] = { 16,11,7,4,2,1 };
	Test("Test3", numbers, sizeof(numbers) / sizeof(int), -1);
}

//价格全部相同
void Test4()
{
	int numbers[] = { 16, 16, 16, 16, 16 };
	Test("Test4", numbers, sizeof(numbers) / sizeof(int), 0);
}

//不要简单理解为2个指针同时走，这个例子是相遇点在数组偏左的位置
void Test5()
{
	int numbers[] = { 9, 11,5,7,16, 1,4, 2,7,8 };
	Test("Test5", numbers, sizeof(numbers) / sizeof(int), 11);
}

//边界条件
void Test6()
{
	int numbers[] = { 2,4 };
	Test("Test6", numbers, sizeof(numbers) / sizeof(int), 2);
}

//边界条件
void Test7()
{
	int numbers[] = {4,2 };
	Test("Test7", numbers, sizeof(numbers) / sizeof(int), -2);
}

void Test8()
{
	Test("Test8", nullptr, 0, 0);
}



int main(int argc, char* argv[])
{

	Test1();
	Test2();
	Test3();
	Test4();
	Test5();
	Test6();
	Test7();
	Test8();

	system("pause");
	return 0;
}

