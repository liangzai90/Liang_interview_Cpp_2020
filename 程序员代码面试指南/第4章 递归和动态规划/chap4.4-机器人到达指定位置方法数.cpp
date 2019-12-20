/***************************
《程序员代码面试指南--IT名企算法与数据结构题目最优解》 左程云  著

机器人到达指定位置方法数

【题目】
假设有排成一行的N个位置，记为1~N，N一定大于或等于2。开始时机器人在其中的M位置上（M一定是1~N中的一个），
机器人可以往左走或者往右走，如果机器人来到1位置，那么下一步只能往右来到2位置；
如果机器人来到N位置，那么下一步只能往左来到N-1位置。
规定，机器人必须走K步，最终能来到P位置（P也一定是1~N中的一个）的方法有多少种。
给定4个参数N、M、K、P，返回方法数。

【要求】
时间复杂度为O(N*K)


**************************************/
#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
#include <exception>
using namespace std;




//////////////////////////////////////////暴力递归求解
//N:位置为1~N，固定参数
//cur:当前在cur位置，可变参数
//rest:还剩res步没有走，可变参数
//P:最终目标位置P，固定参数
//只能在1~N这些位置上移动，当前在cur位置，走完rest步之后，停在P位置的方法数作为返回值返回
//
int walk(int N, int cur, int rest, int P)
{
	//如果没有剩余步数了，当前的cur位置就是最后的位置
	//如果最后的位置停在P上，那么之前做的移动是有效的
	//如果最后的位置没有停在P上，那么之前做的移动是无效的
	if (rest == 0)
	{
		return cur == P ? 1 : 0;
	}

	//如果还有rest步要走，而当前的cur位置在1位置上，那么当前这步只能从1走向2
	//后续的过程就是原来到2位置上，还剩rest-1步要走
	if (cur == 1)
	{
		return walk(N, 2, rest - 1, P);
	}

	//如果还有rest步要走，而当前的cur位置在N位置上，那么当前这步只能从N走向N-1
	//后续的过程就是来到N-1位置上，还剩rest-1步要走
	if (cur == N)
	{
		return walk(N, N - 1, rest - 1, P);
	}

	//如果还有rest步要走，而当前的cur位置在中间位置上，那么可以向左走，也可以向右走
	//
	return walk(N, cur - 1, rest - 1, P) + walk(N, cur + 1, rest - 1, P);
}

int ways1(int N, int M, int K, int P)
{
	//参数无效直接返回
	if (N < 2 || K < 1 || M<1 || M>N || P<1 || P>N)
	{
		return 0;
	}

	//总共N个位置，从M点出发，还剩K步，返回最终能达到P的方法数
	return walk(N, M, K, P);
}




/////////////////////////////////////递归思路分析，循环方法解决
int ways2(int N, int M, int K, int P)
{
	//参数无效直接返回0
	if (N < 2 || K < 1 || M<1 || M>N || P<1 || P>N)
	{
		return 0;
	}
	int iResult = 0;
	int** dp = new int*[K + 1];
	for (int i = 0; i < K + 1; i++)
	{
		dp[i] = new int[N + 1];
	}

	//给第1行赋值，如果走0步，只有在p点才是有效的，其他位置无效，为0
	for (int i = 0; i < N + 1; i++)
	{
		if (i != P)
		{
			dp[0][i] = 0;
		}
		else
		{
			dp[0][i] = 1;
		}
	}
	for (int j = 0; j < K + 1; j++)
	{
		dp[j][0] = 0;
	}

	for (int i = 1; i < K + 1; i++)
	{
		for (int j = 1; j < N + 1; j++)
		{
			if (j == 1)
			{
				dp[i][j] = dp[i-1][2];
			}
			else if (j == N)
			{
				dp[i][j] = dp[i - 1][N - 1];
			}
			else
			{
				dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j + 1];
			}
		}
	}



	/////打印这个辅助数组
	printf("dp[][]------------way2----------------start\r\n");
	for (int i = 0; i < K + 1; i++)
	{
		for (int j = 0; j < N + 1; j++)
		{
			printf("%5d,", dp[i][j]);
		}
		printf("\r\n");
	}
	printf("dp[][]-------------way2---------------end\r\n");
	

	iResult = dp[K][M];

	for (int i = 0; i < K + 1; i++)
	{
		delete[] dp[i];
	}
	delete[] dp;

	return iResult;
}




///压缩到一维数组
int ways3(int N, int M, int K, int P)
{
	//参数无效直接返回0
	if (N < 2 || K < 1 || M<1 || M>N || P<1 || P>N)
	{
		return 0;
	}
	int iResult = 0;
	int* dp = new int[N + 1];

	//给第1行赋值，如果走0步，只有在p点才是有效的，其他位置无效，为0
	for (int i = 0; i < N + 1; i++)
	{
		if (i != P)
		{
			dp[i] = 0;
		}
		else
		{
			dp[i] = 1;
		}
	}

	for (int i = 1; i < K + 1; i++)
	{
		int LeftUp = dp[1];
		for (int j = 1; j < N + 1; j++)
		{
			int tempLeft = dp[j];
			if (j == 1)
			{
				dp[j] = dp[j+1];
			}
			else if (j == N)
			{
				dp[j] = LeftUp;
			}
			else
			{
				dp[j] = LeftUp + dp[j + 1];
			}

			LeftUp = tempLeft; ///保存旧的的左值
		}
	}




	iResult = dp[M];
	delete[] dp;

	return iResult;
}


//==================测试用例====================
void test1()
{
	//5,2,3,3,
	//7,4,9,5
	int N = 0;
	int M = 0;
	int K = 0;
	int P = 0;
	cout << "Test1---------------------------------" << endl;
	N = 7;	M = 4;	K = 9;	P = 5;
	//cout << "way1:" << ways1(N, M, K, P) << endl;;
	cout << "way2:" << ways2(N, M, K, P) << endl;;
	cout << "way3:" << ways3(N, M, K, P) << endl << endl;;;
}

void test2()
{
	//5,2,3,3,
	//7,4,9,5
	int N = 0;
	int M = 0;
	int K = 0;
	int P = 0;
	cout << "Test2---------------------------------" << endl;
	N = 7;	M = 2;	K = 13;	P = 5;
	//cout << "way1:" << ways1(N, M, K, P) << endl;;
	cout << "way2:" << ways2(N, M, K, P) << endl;;
	cout << "way3:" << ways3(N, M, K, P) << endl << endl;;
}


void test3()
{
	int N = 0;
	int M = 0;
	int K = 0;
	int P = 0;
	cout << "Test3---------------------------------" << endl;
	N = 5;	M = 2;	K = 3;	P = 3;
	//cout << "way1:" << ways1(N, M, K, P) << endl;;
	cout << "way2:" << ways2(N, M, K, P) << endl;;
	cout << "way3:" << ways3(N, M, K, P) << endl << endl;;
}




int main()
{
	test1();
	test2();
	test3();



	cout << endl;
	system("pause");
	return 0;
}





