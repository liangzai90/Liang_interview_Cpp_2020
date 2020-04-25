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

*******************************************/

#include <iostream>
#include <assert.h>
#include <mutex>
#include <string>
#include <map>
using namespace std;

#define MAX_ARR_LENGTH  10

//方法1：使用map容器
void findRepeatNum1(int Arr[], int arrLength)
{
	map<int, int>  myMap;
	for (int i = 0; i < arrLength; i++)
	{
		if (myMap.empty())
		{
			myMap.insert(pair<int ,int>(Arr[i], i));
		}
		else
		{
			if (myMap.end() != myMap.find(Arr[i]))
			{
				//find
				cout << "RepartNum:"<< Arr[i] << endl;
			}
			else
			{
				myMap.insert(pair<int, int>(Arr[i], i));
			}
		}
	}
}


///方法2：先快速排序，然后再for循环一次，比较数组里面前后2个元素是否相等
//快速排序.从小到达. 1, 2, 3, 4,...
void quickSort(int Arr[], int startIndex, int endIndex)
{
	if (startIndex >= endIndex)
	{
		return;
	}
	int base = Arr[startIndex];

	int iLeft = startIndex;
	int iRight = endIndex;
	int iPos = 0;

	while (iLeft < iRight)
	{
		//基准点在左边，让右边先走
		while (Arr[iRight] >= base && iLeft < iRight)
		{
			//左边大于等于基准值，且 iLeft不等于iRight，就继续移动
			iRight--;
		}

		while (Arr[iLeft] <= base && iLeft <iRight)
		{
			//左边小于等于基准值，且 iLeft不等于iRight，就继续移动
			iLeft++;
		}

		if (iLeft < iRight)
		{
			int iTemp = Arr[iLeft];
			Arr[iLeft] = Arr[iRight];
			Arr[iRight] = iTemp;
		}
	}

	if (iLeft == iRight)
	{
		iPos = iRight;//停下来的位置就是基准点在数组中的正确位置
		int iTemp = Arr[startIndex];
		Arr[startIndex] = Arr[iPos];
		Arr[iPos] = iTemp;
	}

	quickSort(Arr, startIndex, iPos-1);
	quickSort(Arr, iPos + 1, endIndex);

	return;
}




//不使用map容器
void findRepeatNum2(int Arr[], int arrLength)
{
	bool bFind = false;
	int iNum = 0;
	quickSort(Arr, 0, arrLength);

	for (int i = 1; i < arrLength; i++)
	{
		if (Arr[i - 1] == Arr[i])
		{
			iNum = Arr[i];
			bFind = true;
			break;
		}
	}
}



//测试基本功能
void test1()
{
	int arrTest[MAX_ARR_LENGTH] = { 1, 2, 3, 4, 5, 6, 7, 8 ,8 ,7};
	findRepeatNum1(arrTest, MAX_ARR_LENGTH);
}

//测试基本功能
void test2()
{
	int arrTest[MAX_ARR_LENGTH] = { 5, 6, 7, 8, 8, 7, 1, 2, 3, 4 };

	quickSort(arrTest, 0, MAX_ARR_LENGTH - 1);

	int test2 = 0;
}

int main()
{
	test1();
	test2();

  //还有一种思路是，利用hash表来存放这n个数，(关键在如何解决hash冲突)
  //然后从头到尾按顺序扫描数组的每个数字，没扫描到一个数字的时候，
  //都可以用O(1)的时间来判断哈希表里面是否已经包含了该数字。。


	cout << endl;
	system("pause");
	return 0;
}

