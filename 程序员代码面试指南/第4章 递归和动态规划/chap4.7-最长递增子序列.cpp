/***************************

《程序员代码面试指南--IT名企算法与数据结构题目最优解》 左程云 著

最长递增子序列

【题目】
给定数组arr，返回arr的最长递增子序列

【举例】
arr=[2,1,5,3,6,4,8,9,7]，返回的最长递增子序列为[1,3,4,8,9]

【要求】
如果arr长度为N，请实现时间复杂度为O(NlogN)的方法



**************************************/
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>
using namespace std;


void Printdp(int ** dp, int rows, int cols)
{
	cout << "Printdp--------------start" << endl;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << dp[i][j] << ",";
		}
		cout << endl;
	}
	cout << "Printdp--------------End" << endl;
	cout << endl;
}

int MaxNum(int A, int B)
{
	if (A > B)
	{
		return A;
	}
	else
	{
		return B;
	}
}



/////这种获取dp数组的时间复杂度为O(N^2)
void getdp1(int* arr, int length, int *dp )
{
	for (int i = 0; i < length; i++)
	{
		dp[i] = 1;
		for (int j = 0; j < i; j++)
		{
			if (arr[j] < arr[i])
			{
				dp[i] = MaxNum(dp[i], dp[j] + 1);
			}
		}
	}

	cout << "dp------------print" << endl;
	for (int i = 0; i < length; i++)
	{
		cout << dp[i] << ", ";
	}
	cout << endl;
}

void generateLIS(int *arr, int length, int* dp)
{
	int len = 0;
	int index = 0;
	for (int i = 0; i < length; i++)
	{
		if (dp[i]>len)
		{
			len = dp[i];
			index = i;
		}
	}

	int *outlist = new int[len];
	int iOutIndex = len;
	outlist[--iOutIndex] = arr[index];
	for (int i = index; i >= 0; i--)
	{
		if (arr[i] < arr[index] && dp[i] == dp[index] - 1)
		{
			outlist[--iOutIndex] = arr[i];
			index = i;
		}
	}

	/////output result
	cout << "<<<<<< output result >>>>>" << endl;
	for (int i = 0; i < len; i++)
	{
		cout << outlist[i] << ",";
	}
	cout << endl;
}

void list1(int *arr, int length)
{
	if (arr == nullptr || length <= 0)
	{
		return ;
	}

	int* dp = new int[length];

	getdp1(arr, length, dp);
	generateLIS(arr, length, dp);
}




/////////////////////////////////////////////////////对getdp函数做优化
////二分查找，将时间复杂度降为了 O(NlogN) 
void getdp2(int* arr, int length, int *dp)
{
	int* ends = new int[length];
	ends[0] = arr[0];
	dp[0] = 1;
	int right = 0;
	int L = 0;
	int R = 0;
	int M = 0;
	for (int i = 1; i < length; i++)
	{
		L = 0;
		R = right;

		/////二分查找
		while (L <= R)
		{
			M = (L + R) / 2;
			if (arr[i]>ends[M])
			{
				L = M + 1;
			}
			else
			{
				R = M - 1;
			}
		}

		right = MaxNum(right, L);
		ends[R] = arr[i];
		dp[i] = L + 1;
	}


	cout << "dp------------print" << endl;
	for (int i = 0; i < length; i++)
	{
		cout << dp[i] << ", ";
	}
	cout << endl;
}


void list2(int *arr, int length)
{
	if (arr == nullptr || length <= 0)
	{
		return;
	}

	int* dp = new int[length];

	getdp2(arr, length, dp);
	generateLIS(arr, length, dp);
}




////===============测试用例====================
void test1()
{
	int arr[] = { 2, 1, 5, 3, 6, 4, 8, 9, 7 };
	list1(arr, sizeof(arr) / sizeof(int));
	
	list2(arr, sizeof(arr) / sizeof(int));

}




int main()
{
	test1();



	cout << endl;
	system("pause");
	return 0;
}



