/********************************
《剑指offer》做题笔记


面试题3：数组中重复的数字

题目二：不修改数组，找出数组中重复的数字

在一个长度为n的数组里的所有数字都在0~n-1的范围内。
数组中某写数字是重复的，但不知道有几个数字重复了，
也不知道每个数字重复了几次。请找出数组中任意一个重复的数字，
但不能修改输入的数组。
例如，如果输入长度为7的数组{2,3,,1,0,2,5,3}，
那么对应的输出是重复的数字2或者3



测试用例：

1.长度为n的数组里包含一个或多个重复的数字
2.数组中不包含重复数字
3.无效输入测试用例（输入空指针，长度为n的数组中包含0~n-1之外的数字）

*******************************************/

#include <iostream>
#include <assert.h>
#include <mutex>
#include <string>
#include <map>
#include <stdlib.h>
using namespace std;


//统计数组，在某个区间的数字出现的次数
int countRange(const int* numbers, int length, int iStart, int iEnd)
{
	if (numbers == nullptr || length <= 0)
	{
		return 0;
	}
	int iCount = 0;
	for (int i = 0; i < length; i++)
	{
		if (numbers[i] >= iStart && numbers[i] <= iEnd)
		{
			iCount++;
		}
	}
	return iCount;
}


//二分查找，定位重复元素位置
int getDuplication(const int* numbers, int length)
{
	if (numbers == nullptr || length <= 0)
	{
		return -1;
	}

	int iStart = 1;
	int iEnd = length - 1;
	int iMiddle = (iEnd - iStart)/2+iStart;

	//这里必须有等于，，，我们最终的目标就是去查找这个数出现的次数...
	while (iStart <= iEnd)
	{
		iMiddle = (iEnd - iStart) / 2 + iStart;
		int iCount = countRange(numbers, length, iStart, iMiddle);


		/////这里的结束条件易错。。刚开始做的时候，这里错了..20191120
		//什么时候是重复的，那就是 iEnd==iStart（在数组中查找某个数字），而且它出现的次数大于1
		if (iStart == iEnd)
		{
			if (iCount > 1)
			{
				return iStart;
			}
			else
			{
				break;
			}
		}

		if (iCount >(iMiddle - iStart + 1))
		{
			//front
			iEnd = iMiddle;
		}
		else
		{
			//behind
			iStart = iMiddle+1;
		}		
	}

	return -1;
}


// =====================测试代码=======================
void test(const char* testName, int *numbers, int length, int *duplications, int dupLength)
{
	int result = getDuplication(numbers, length);
	for (int i = 0; i < dupLength; ++i)
	{
		if (result == duplications[i])
		{
			cout << testName << " passed." << endl;
			return;
		}
	}

	cout << testName << " FAILED." << endl;
}

//多个重复的数字
void test1()
{
	int numbers[] = { 2, 3, 5, 4, 3, 2, 6, 7 };
	int duplications[] = { 2, 3 };
	test("test1", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int));
}

//1个重复的数字
void test2()
{
	int numbers[] = { 3, 2, 1, 4, 4, 5, 6, 7 };
	int duplications[] = { 4 };
	test("test2", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int));
}


//重复的数字使数组中最小的
void test3()
{
	int numbers[] = { 1, 2, 3, 4, 5, 6, 7, 1, 8 };
	int duplications[] = {1 };
	test("test3", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int));
}

//重复的数字使数组中最大的
void test4()
{
	int numbers[] = { 1, 7, 3, 4, 5, 6, 8, 2, 8 };
	int duplications[] = { 8};
	test("test4", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int));
}


//数组中只有2个数字
void test5()
{
	int numbers[] = { 1,1};
	int duplications[] = { 1 };
	test("test5", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int));
}

//重复的数字位于数组中
void test6()
{
	int numbers[] = { 3, 2, 1, 3, 4, 5, 6, 7 };
	int duplications[] = { 3 };
	test("test6", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int));
}


// 多个重复的数字
void test7()
{
	int numbers[] = { 1, 2, 2, 6, 4, 5, 6 };
	int duplications[] = { 2,6 };
	test("test7", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int));
}

// 一个数字重复三次
void test8()
{
	int numbers[] = { 1, 2, 2, 6, 4, 5, 2 };
	int duplications[] = { 2 };
	test("test8", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int));
}

// 没有重复的数字
void test9()
{
	int numbers[] = { 1, 2, 6, 4, 5, 3 };
	int duplications[] = { -1 };
	test("test9", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int));
}

// 无效的输入
void test10()
{
	int* numbers = nullptr;
	int duplications[] = { -1 };
	test("test10", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int));
}




int main()
{
	test1();
	test2();
	test3();
	test4();
	test5();
	test6();
	test7();
	test8();
	test9();
	test10();

	cout << endl;
	system("pause");
	return 0;
}

