/***************************
《程序员代码面试指南--IT名企算法与数据结构题目最优解》 左程云  著

换钱的最少货币数

【题目】
  给定数组arr, arr中所有的值都为正数且不重复。每个值代表一种面值的货币，每种面值的货币可以使用任意张，
再给定一个整数aim，代表要找的钱数，求组成aim的最少货币数。

【举例】
arr=[5,2,3],aim=20
4张5元可以组成20元，其他找钱方案都要使用更多的货币，所以返回4.

arr=[5,2,3],aim=0
不用任何货币就可以组成0元，返回0

arr=[3,5],aim=2
根本没法组成2元，钱不能找开的情况下默认返回-1.




**************************************/
#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
#include <exception>
using namespace std;

#define INT_MAX   1000



int GetMinNum(int A, int B)
{
	return A > B ? B : A;
}

int process(int *arr,int length, int i, int rest);

int minCoins1(int* arr, int length, int aim)
{
	if (arr == nullptr || length <= 0 || aim <= 0)
	{
		return -1;
	}

	return process(arr, length, 0, aim);
}


//当前考虑的面值是arr[i],还剩rest的钱需要找零
//如果返回-1，说明自由使用 arr[i...N-1]面值的情况下，无论如何也无法找零rest
//如果返回不是-1，代表自由使用arr[i...N-1]面值的情况下，找零rest需要的最少张数
int process(int *arr, int length, int i, int rest)
{
	//base case
	//已经没有面值能够考虑了
	//如果此时剩余的钱为0，返回0张
	//如果此时剩余的钱不是0，返回-1
	if (i >= length)
	{
		if (rest == 0)
		{
			cout << "====================="<<endl;
		}
		return rest == 0 ? 0 : -1;
	}

	//最少张数，初始时为-1，因为还没找到有效解
	int res = -1;
	//依次尝试使用当前面值(arr[i])0张、1张、k张，但不能超过rest
	for (int k = 0; k*arr[i] <= rest; k++)
	{
		//使用了k张aim[i]，剩下的钱为 rest - k*arr[i]
		//交给剩下的面值去搞定 (arr[i+1...N-1])
		int next = process(arr, length, i + 1, rest - k*arr[i]);

		//说明这个后续过程有效
		if (next != -1)
		{
			res = res == -1 ? next + k : GetMinNum(res, next + k);
		}
	}


	cout << "res" << res << endl;
	return res;
}



void printDPArray(int* dp, int cols)
{
	for (int j = 0; j < cols; j++)
	{
		printf("%d,", (int)(*(dp + j)));
	}
	cout << endl;
}

int minCoin2(int* arr, int length, int aim)
{
	if (arr == nullptr || length <= 0 || aim < 0)
	{
		return -1;
	}
	int N = length;
	int** dp = new int*[N + 1];
	for (int i = 0; i < N+1; i++)
	{
		dp[i] = new int[aim + 1];
	}

	for (int i = 0; i < N + 1; i++)
	{
		for (int j = 0; j < aim + 1; j++)
		{
			dp[i][j] = 0;
		}
	}


	//设置最后一排的值,除dp[N][0]为0外，其他都是-1
	dp[N][0] = 0;
	for (int col = 1; col <= aim; col++)
	{
		dp[N][col] = -1;
	}

	//从底下往上计算每一行
	for (int i = N - 1; i >= 0; i--)
	{
		//每一行都从左到右
		for (int rest = 0; rest <= aim; rest++)
		{
			dp[i][rest] = -1;//初始时先设置dp[i][rest]的值无效

			//下面的值如果有效
			if (dp[i + 1][rest] != -1)
			{
				dp[i][rest] = dp[i + 1][rest];//先设置为下面的值
			}

			//如果左边的位置不越界且有效
			if (rest - arr[i] >= 0 && dp[i][rest - arr[i]] != -1)
			{
				//如果之前下面的值无效
				if (dp[i][rest] == -1)
				{
					dp[i][rest] = dp[i][rest - arr[i]] + 1;
				}
				else
				{
					//说明下面和左边的值都有效，去最小的
					dp[i][rest] = GetMinNum(dp[i][rest], dp[i][rest - arr[i]] + 1);
				}
			}
		}
	}



	////二维数组打印，有点不熟悉。。。
	for (int i = 0; i < N + 1; i++)
	{
		printDPArray(*(dp+i),aim + 1);
	}
	cout << endl;
	cout << endl;

	cout << "printDPArray====================start" << endl;
	for (int i = 0; i < N + 1; i++)
	{
		printf("Row:%d.  ", i);
		for (int j = 0; j < aim + 1; j++)
		{
			printf("%d,", dp[i][j]);
		}
		cout << endl;
	}
	cout << "printDPArray====================end" << endl;

/*
    printDPArray == == == == == == == == == == start
	Row : 0.  0, -1, 1, 1, 2, 1, 2, 2, 2, 3, 2, 3, 3, 3, 4, 3, 4, 4, 4, 5, 4,
    Row : 1.  0, -1, 1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7,
	Row : 2.  0, -1, 1, -1, 2, -1, 3, -1, 4, -1, 5, -1, 6, -1, 7, -1, 8, -1, 9, -1, 10,
	Row : 3.  0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
	printDPArray == == == == == == == == == == end
*/


	return dp[0][aim];
}

void PrintDPArr2(vector<int>& dp)
{
	for (vector<int>::iterator it1 = dp.begin(); it1 != dp.end(); ++it1)
	{
		cout << *it1<<",";
	}
	cout << endl;
}

void MiniCoin3(int* arr, int length, int aim)
{
	cout << "MiniCoin3======================" << endl;
	vector<int> dp(aim + 1, INT_MAX);
	dp[0] = 0;

	for (int i = 0; i < length; ++i)
	{
		for (int j = arr[i]; j <= aim; ++j)
		{
			if (dp[j - arr[i]] != INT_MAX)
			{
				dp[j] = min(dp[j], dp[j - arr[i]] + 1);
			}
		}
		PrintDPArr2(dp);
	}

	if (dp[aim] == INT_MAX) cout << "-1" << endl;
	else  cout << "dp[aim] "<<dp[aim] << endl;

	/* aim=6,arr=[2,1,3]
	0,1000,1,1000,2,1000,3,
	0,1,1,2,2,3,3,
	0,1,1,1,2,2,2,
	dp[aim] 2	
	*/
}


//====================测试用例=================
void test1()
{
	int arrCoin1[3] = {2,1,3};
	int arrCoin2[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 60, 62, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 112, 113, 114, 115, 116, 117 };
	//int arrCoin2[] = { 1,3,5,6 };

	//cout << "Test1================" << endl;
	//cout << "expected:4. " << minCoin2(arrCoin1, sizeof(arrCoin1) / sizeof(int), 6) << endl;;
	
	MiniCoin3(arrCoin1, sizeof(arrCoin1) / sizeof(int), 6);
	//MiniCoin3(arrCoin2, sizeof(arrCoin2) / sizeof(int), 122);

	
	//cout << "expected:2. " << minCoins1(arrCoin2, sizeof(arrCoin2) / sizeof(int), 122) << endl;;
}




int main()
{
	test1();



	cout << endl;
	system("pause");
	return 0;
}





