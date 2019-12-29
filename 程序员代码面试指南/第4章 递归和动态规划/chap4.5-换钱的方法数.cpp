/*************************************************
《程序员代码面试指南--IT名企算法与数据结构题目最优解》 左程云 著

换钱的方法数

【题目】
给定数组arr, arr中所有的值都为正数且不重复。
每个值代表一种面值的货币，每种面值的货币可以使用任意张，
再给定一个整数aim，代表要找的钱数，求换钱有多少种方法。

【举例】
arr=[5,10,25,1],aim=0
组成0元的方法只有1种，就是所有面值的货币都不用。所以返回1.

arr=[j5,10,25,1],aim=15
组成15元的方法有6种，
5Y*3
10Y*1+5Y*1
10Y*1+1Y*5
1Y*10+5Y*1
5Y*2+1Y*5
1Y*15

任何方法都无法组成2元，所以aim=2会返回0.

******************************************************/

#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
#include <exception>
using namespace std;

void PrintMap(int ** map, int rows, int cols)
{
	cout << "PrintMap--------------start" << endl;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << map[i][j] << ",";
		}
		cout << endl;
	}
	cout << "PrintMap--------------End" << endl;
	cout << endl;
}


///////////////////////////////////////////////////////解法1：暴力递归
int process1(int *arr, int length, int index, int aim)
{
	int res = 0;
	if (index == length)
	{
		res = aim == 0 ? 1 : 0;
	}
	else
	{
		for (int i = 0; arr[index] * i <= aim; i++)
		{
			res += process1(arr, length, index + 1, aim - arr[index] * i);
		}
	}
	return res;
}

int coins1(int *arr, int length, int aim)
{
	if (arr == nullptr || length <= 0 || aim <= 0)
	{
		return 0;
	}
	return process1(arr, length, 0, aim);
}

////////////////////////////////////////////////解法2：暴力递归优化版。记忆搜索
////p(index, aim)这样的一个递归过程.用map[index][aim]保存已经计算过的递归过程的结果
int process2(int *arr, int length, int index, int aim, int **map, int rows, int cols)
{
	int res = 0;
	if (index == length)
	{
		res = aim == 0 ? 1 : 0;
	}
	else
	{
		int mapValue = 0;
		for (int i = 0; arr[index] * i <= aim; i++)
		{
			mapValue = map[index + 1][aim - arr[index] * i];

			if (mapValue != 0)
			{
				res += mapValue == -1 ? 0 : mapValue;
			}
			else
			{
				res += process2(arr, length, index + 1, aim - arr[index] * i, map, rows, cols);
			}
		}
	}

	map[index][aim] = res == 0 ? -1 : res;

	return res;
}


int coins2(int *arr, int length, int aim)
{
	if (arr == nullptr || length <= 0 || aim <= 0)
	{
		return 0;
	}
	int**map = new int*[length + 1];
	for (int i = 0; i < length + 1; i++)
	{
		map[i] = new int[aim + 1];
	}
	for (int i = 0; i < length + 1; i++)
	{
		for (int j = 0; j < aim + 1; j++)
		{
			map[i][j] = 0;
		}
	}

	int iResult = process2(arr, length, 0, aim, map, length + 1, aim + 1);

	PrintMap(map, length + 1, aim + 1);

	return iResult;
}


////////////////////////////////////////////////////////////////解法3：动态规划分析的方法、抽象出dp[i][j]是如何由上一行得到的
//dp[i][j]的含义是，在使用arr[0...i]货币的情况下，组成钱数j有多少种方法。
//....
//dp[N-1][aim]的值就是最终结果
int coins3(int *arr, int length, int aim)
{
	if (arr == nullptr || length <= 0 || aim <= 0)
	{
		return 0;
	}
	int**dp = new int*[length];
	for (int i = 0; i < length; i++)
	{
		dp[i] = new int[aim + 1];
	}
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < aim + 1; j++)
		{
			dp[i][j] = 0;
		}
	}

	////第1列都为0.dp[i][0] 都为1，表示 组成钱数0的方法只有1种
	for (int i = 0; i < length; i++)
	{
		dp[i][0] = 1;
	}

	//第1行中的某些项.dp[0][j]，只使用arr[0]货币，可以组成哪些数
	for (int j = 1; j * arr[0] < aim + 1; j++)
	{
		dp[0][j*arr[0]] = 1;
	}

	int num = 0;
	for (int i = 1; i < length; i++)
	{
		for (int j = 1; j < aim + 1; j++)
		{
			num = 0;
			for (int k = 0; j - arr[i] * k >= 0; k++)
			{
				num += dp[i - 1][j - arr[i] * k];
			}
			dp[i][j] = num;
		}
	}

	int iResult = dp[length - 1][aim];

	PrintMap(dp, length, aim + 1);

	return iResult;
}


////////////////////////////////////////////////解法4：动态规划，再次抽象
//dp[i][j] = dp[i-1][j] + dp[i][j-arr[i]]
//
int coins4(int *arr, int length, int aim)
{
	if (arr == nullptr || length <= 0 || aim <= 0)
	{
		return 0;
	}
	int**dp = new int*[length];
	for (int i = 0; i < length; i++)
	{
		dp[i] = new int[aim + 1];
	}
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < aim + 1; j++)
		{
			dp[i][j] = 0;
		}
	}

	////第1列都为0.dp[i][0] 都为1，表示 组成钱数0的方法只有1种
	for (int i = 0; i < length; i++)
	{
		dp[i][0] = 1;
	}

	//第1行中的某些项.dp[0][j]，只使用arr[0]货币，可以组成哪些数
	for (int j = 1; j * arr[0] < aim + 1; j++)
	{
		dp[0][j*arr[0]] = 1;
	}

	int num = 0;
	for (int i = 1; i < length; i++)
	{
		for (int j = 1; j < aim + 1; j++)
		{
			dp[i][j] = dp[i - 1][j];
			dp[i][j] += j - arr[i] >= 0 ? dp[i][j - arr[i]] : 0;
		}
	}

	int iResult = dp[length - 1][aim];

	PrintMap(dp, length, aim + 1);

	return iResult;
}


////////////////////////////////////////////////解法5：动态规划，空间压缩
//dp[i][j] = dp[i-1][j] + dp[i][j-arr[i]]
int coins5(int *arr, int length, int aim)
{
	if (arr == nullptr || length <= 0 || aim <= 0)
	{
		return 0;
	}
	int*dp = new int[aim + 1];
	for (int j = 0; j < aim + 1; j++)
	{
		dp[j] = 0;
	}

	//第1行中的某些项.dp[0][j]，只使用arr[0]货币，可以组成哪些数
	for (int j = 1; j * arr[0] < aim + 1; j++)
	{
		dp[j*arr[0]] = 1;
	}

	for (int i = 1; i < length; i++)
	{
		for (int j = 1; j < aim + 1; j++)
		{
			dp[j] += j - arr[i] >= 0 ? dp[j - arr[i]] : 0;
		}
	}

	int iResult = dp[aim];

	return iResult;
}

////===============测试用例====================
void test1()
{
	int arr[4] = { 5, 10, 25, 1 };
	//    int iResult1 = coins1(arr, sizeof(arr) / sizeof(int), 15);
	//    cout << "iResult1:" << iResult1 << endl;


	//int iResult2 = coins2(arr, sizeof(arr) / sizeof(int), 15);
	//cout << "iResult2:" << iResult2 << endl;


	//    int iResult3 = coins3(arr, sizeof(arr) / sizeof(int), 15);
	//    cout << "iResult3:" << iResult3 << endl;

	//    int iResult4 = coins4(arr, sizeof(arr) / sizeof(int), 15);
	//    cout << "iResult4:" << iResult4 << endl;

	int iResult5 = coins5(arr, sizeof(arr) / sizeof(int), 15);
	cout << "iResult5:" << iResult5 << endl;

}


int main()
{
	test1();

	cout << endl;
	system("pause");
	return 0;
}


