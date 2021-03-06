/********************************
《剑指offer》做题笔记


面试题3：数组中重复的数字

题目一：找出数组中重复的数字

在一个长度为n的数组里的所有数字都在0~n-1的范围内。
数组中某写数字是重复的，但不知道有几个数字重复了，
也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。
例如，如果输入长度为7的数组{2,3,,1,0,2,5,3}，
那么对应的输出是重复的数字2或者3


题目地址：
https://www.nowcoder.com/practice/623a5ac0ea5b4e5f95552655361ae0a8?tpId=13&tqId=11203&rp=3&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking


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



//参考了作者的解题思路来写的
bool duplicate(int numbers[], int length, int* duplication)
{
	if (length <= 0 || nullptr == numbers)
	{
		return false;
	}

	//对数组内的元素合法性做一次判断（我漏掉了）
	for (int i = 0; i < length; ++i)
	{
		if (numbers[i] < 0 || numbers[i] > length - 1)
			return false;
	}

	bool bFind = false;

	for (int i = 0; i < length; i++)
	{
		while (numbers[i] != i)
		{
			////请画一个二维图形来辅助理解
			if (numbers[i] == numbers[numbers[i]])
			{
				bFind = true;
				*duplication = numbers[i];
				break;
			}

			///swap numbers[i] and numbers[numbers[i]]
			int iTemp = numbers[i];
			numbers[i] = numbers[iTemp];
			numbers[iTemp] = iTemp;
		}

		if (bFind)
		{
			break;
		}
	}

	return bFind;
}

///////////测试用例不能少、不能马虎、认真对待
//====================测试代码========================
bool contains(int array[], int length, int number)
{
	for (int i = 0; i < length; i++)
	{
		if (array[i] == number)
		{
			return true;
		}
	}
	return false;
}

void test(char* testName, int numbers[], int lengthNumbers, int expected[], int expectedExpected, bool validArgument)
{
	printf("%s begins:", testName);

	int duplication = 0;
	bool validInput = duplicate(numbers, lengthNumbers, &duplication);

	if (validArgument == validInput)
	{
		if (validArgument)
		{
			if (contains(expected, expectedExpected, duplication))
			{
				printf("Passed. \r\n");
			}
			else
			{
				printf("FAILED. \r\n");
			}
		}
		else
		{
			printf("Passed.\r\n");
		}
	}
	else
	{
		printf("FAILED.\r\n");
	}
}



//重复的数字是数组中最小的数字
void test1()
{
	int numbers[] = {2, 1, 3, 1, 4};
	int duplications[] = { 1 };
	test("Test1", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int), true);
}

//重复的数字是数组中最大的数字
void test2()
{
	int numbers[] = { 2, 4, 3, 1, 4 };
	int duplications[] = { 4 };
	test("Test2", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int), true);
}

//数组中存在多个重复的数字
void test3()
{
	int numbers[] = { 2, 4, 2, 1, 4 };
	int duplications[] = { 2,4 };
	test("Test3", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int), true);
}

//没有重复的数字
void test4()
{
	int numbers[] = { 2, 1, 3, 0, 4 };
	int duplications[] = { -1 };// not in the test function
	test("Test4", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int), false);
}

//没有重复的数字
void test5()
{
	int numbers[] = { 2, 1, 4, 5, 4 };//5是合法的数字
	int duplications[] = { 4 };// not in the test function
	test("Test5", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int), false);
}


//无效的输入
void test6()
{
	int *numbers = nullptr;
	int duplications[] = { -1 };
	test("Test6", numbers, 0, duplications, sizeof(duplications) / sizeof(int), false);
}


int main()
{
	test1();
	test2();
	test3();
	test4();
	test5();
	test6();

	cout << endl;
	system("pause");
	return 0;
}

