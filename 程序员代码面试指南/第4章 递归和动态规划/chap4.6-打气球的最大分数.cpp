/***************************

《程序员代码面试指南--IT名企算法与数据结构题目最优解》 左程云 著

打气球的最大分数

【题目】
给定一个数组arr，代表一排有分数的气球。每打爆一个气球都能获得分数，假设打爆气球的分数为X，获得分数的规则如下：
1）如果被打爆气球的左边有没有被打爆的气球，找到离被打爆气球最近的气球，假设分数为L；
如果被打爆气球的右边有没有被打爆的气球，找到离被打爆气球最近的气球，假设分数为R。获得分数为L*X*R。
2）如果被打爆气球的左边有没有被打爆的气球，找到离被打爆气球最近的气球，假设分数为L；
如果被打爆气球的右边所有气球都已经被打爆。获得分数为L*X。
3）如果被打爆气球的左边所有的气球都已经被打爆；
如果被打爆气球的右边有没有被打爆的气球，找到离被打爆气球最近的气球，假设分数为R。获得分数为X*R。
4）如果被打爆气球的左边和右边所有的气球都已经被打爆。获得分数为X。

目标是打爆所有气球，获得每次打爆的分数。通过选择打爆气球的顺序，可以得到不同的总分，
请返回能获得的最大分数。

【举例】
arr = [3,2,5]

如果先打爆3，获得3*2；再打爆2，获得2*5；最后打爆5，获得5，最后总分21.
如果先打爆3，获得3*2；再打爆5，获得2*5；最后打爆2，获得2，最后总分18.
如果先打爆2，获得3*2*5；再打爆3，获得3*5；最后打爆5，获得5，最后总分50.
如果先打爆2，获得3*2*5；再打爆5，获得3*5；最后打爆3，获得3，最后总分48.
...等等，有6中打气球的顺序（全拍列）
能获得的最大分数为50.

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

/////////////////////////////////////////////////////////////方法1：暴力递归求解
//打爆arr[L...R]范围上的所有气球，返回最大的分数
//假设arr[L-1]和arr[R+1]一定没有被打爆
int process(int *arr, int length, int L, int R)
{
	if (L == R)//如果arr[L...R]范围上只有一个气球，直接打爆即可
	{
		return arr[L - 1] * arr[L] * arr[R + 1];
	}

	//最后打爆arr[L]的方案与最后打爆arr[R]的方案，先比较一下
	int max = MaxNum(arr[L - 1] * arr[L] * arr[R + 1] + process(arr, length, L + 1, R), arr[L - 1] * arr[R] * arr[R + 1] + process(arr, length, L, R - 1));

	//尝试中间位置的气球最后被打爆的每一种方案
	for (int i = L + 1; i < R; i++)
	{
		max = MaxNum(max, arr[L - 1] * arr[i] * arr[R + 1] + process(arr, length, L, i - 1) + process(arr, length, i + 1, R));
	}
	return max;
}

int MaxCoins1(int *arr, int length)
{
	if (arr == nullptr || length <= 0)
	{
		return 0;
	}
	if (length == 1)
	{
		return arr[0];
	}

	int N = length;
	int *help = new int[N + 2];
	help[0] = 1;
	help[N + 1] = 1;
	for (int i = 0; i < N; i++)
	{
		help[i + 1] = arr[i];
	}

	int iResult = process(help, N, 1, N);

	return iResult;
}



/////////////////////////////////////////////////////////////解法2：
int MaxCoins2(int *arr, int length)
{
	if (arr == nullptr || length <= 0)
	{
		return 0;
	}

	if (length == 1)
	{
		return arr[0];
	}

	int N = length;
	int * help = new int[N + 2];
	help[0] = 1;
	help[N + 1] = 1;
	for (int i = 0; i <N; i++)
	{
		help[i + 1] = arr[i];
	}

	int **dp = new int*[N + 2];
	for (int i = 0; i < N + 2; i++)
	{
		dp[i] = new int[N + 2];
	}

	for (int i = 0; i < N + 2; i++)
	{
		for (int j = 0; j < N + 2; j++)
		{
			dp[i][j] = 0;
		}
	}

	/////对角线上的. L==R的情况...
	for (int i = 1; i <= N ; i++)
	{
		dp[i][i] = help[i - 1] * help[i] * help[i + 1];
	}

	for (int L = N; L >= 1; L--)
	{
		for (int R = L + 1; R <= N; R++)
		{
			//求解dp[L][R]，表示help[L...R]上打爆所有气球的最大分数

			///最后打爆 help[L] 的方案
			int finalL = help[L - 1] * help[L] * help[R + 1] + dp[L + 1][R];

			//最后打爆 help[R] 的方案
			int finalR = help[L - 1] * help[R] * help[R + 1] + dp[L][R - 1];

			//最后打爆 help[L] 和最后打爆 help[R] 的方案比较一下
			dp[L][R] = max(finalL, finalR);

			//尝试中间位置的气球最后被打爆的每一种方案
			for (int i = L + 1; i < R; i++)
			{
				dp[L][R] = max(dp[L][R], help[L - 1] * help[i] * help[R + 1] + dp[L][i - 1] + dp[i + 1][R]);
			}
		}
	}
	
	int  iResult = dp[1][N];


	Printdp(dp, N + 2, N + 2);

	return iResult;
}


//////////////////////////////和解法2相同，这是地道的C++方式的解法。用到了vector
int MaxCoins3()
{
	int n = 3;
	vector<int> arr(n + 2, 1);
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}

	vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

	for (int i = 1; i <= n; i++)
	{
		dp[i][i] = arr[i - 1] * arr[i] * arr[i + 1];
	}

	for (int l = n; l >= 1; l--)
	for (int r = l + 1; r <= n; r++)
		//dp[l][r]表示在[l,r]上打爆所有气球的最大分数
	{
		int finall = arr[l - 1] * arr[l] * arr[r + 1] + dp[l + 1][r];
		int finalr = arr[l - 1] * arr[r] * arr[r + 1] + dp[l][r - 1];
		dp[l][r] = max(finall, finalr);
		for (int i = l + 1; i <= r - 1; i++)
			dp[l][r] = max(dp[l][r], arr[l - 1] * arr[i] * arr[r + 1] + dp[l][i - 1] + dp[i + 1][r]);
	}

	for (int i = 0; i < n + 1; i++)
	{
		for (int j = 0; j < n + 1; j++)
		{
			cout << dp[i][j] << ",";
		}
		cout << endl;
	}
	cout << endl;
	cout << dp[1][n] << endl;
}



////===============测试用例====================
void test1()
{
	int arr[] = { 3,2,5 };
	int iResult1 = MaxCoins1(arr, sizeof(arr) / sizeof(int));
	cout << "iResult1:" << iResult1 << endl;

	int iResult2 = MaxCoins2(arr, sizeof(arr) / sizeof(int));
	cout << "iResult2:" << iResult2 << endl;

}




int main()
{
	test1();



	cout << endl;
	system("pause");
	return 0;
}



