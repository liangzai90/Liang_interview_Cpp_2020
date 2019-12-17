/***************************
《程序员代码面试指南--IT名企算法与数据结构题目最优解》 左程云  著

矩阵的最小路径和

【题目】
给定一个矩阵m，从左上角开始每次只能向右或者向下走，最后到达右下角位置，路径上所有的数字累加起来就是路径和，返回所有路径中最小的路径和。

【举例】
如果给定的m如下：
1  3  5  9
8  1  3  4
5  0  6  1
8  8  4  0
路径1，3，1,0,6,1,0是所有路径中路径和最小的，所以返回12.


关键思路：
假设有一个M*N的数组 dp[M][N], dp[i][j]的值表示从左上角（0,0）位置走到（i,j）位置的最小路径和。
第0行和第0列比较特殊，是不断累加的结果
1 4 9 18
9,
14
22

其他行和列，dp[i][j] = Min(dp[i-1][j], dp[i][j-1]) + m[i][j];
所以，我们可以从最右下角，倒推到左上角。
从下到上思考，从上到下解决。


**************************************/

#include <iostream>
#include <stack>
#include <exception>
using namespace std;

int minOfTwoNum(int A, int B)
{
	return A > B ? B : A;
}

//申请一个M*N的二位数组空间
int MinPathRoad(int* arrPath, const int rows,const  int cols)
{
	if (arrPath == nullptr || rows < 0 || cols < 0)
	{
		throw new std::exception("Invalid para");
	}
	if (rows == 0 || cols == 0)
	{
		return 0;
	}
	int result = 0;
	int** copyPath =new int*[rows];
	for (int i = 0; i < rows; i++)
	{
		copyPath[i] = new int[cols];
	}


	///这里有可优化空间。能用一维数组解决的，不要用二维数组
	//for (int i = 0; i < rows; i++)
	//{
	//	for (int j = 0; j < cols; j++)
	//	{
	//		if (i == 0 && j == 0)
	//		{
	//			copyPath[i][j] = *(arrPath + i*cols + j);
	//		}
	//		if (i == 0 && j>0)
	//		{
	//			copyPath[i][j] = *(arrPath + i*cols + j) + *(arrPath + i*cols + j - 1);
	//		}
	//		if (j == 0 && i > 0)
	//		{
	//			copyPath[i][j] = *(arrPath + i*cols + j) + *(arrPath + (i - 1)*cols + j);
	//		}
	//	}
	//}

	copyPath[0][0] = *(arrPath);

	for (int j = 1; j < cols; j++)
	{
		copyPath[0][j] = *(arrPath + j) + *(arrPath + j - 1);
	}

	for (int i = 1; i < rows; i++)
	{
        copyPath[i][0] = *(arrPath + i*cols ) + *(arrPath + (i - 1)*cols );
	}

	////时间复杂度是O(M*N)
	for (int i = 1; i < rows; i++)
	{
		for (int j = 1; j < cols; j++)
		{
			int tempValue = minOfTwoNum(copyPath[i - 1][j], copyPath[i][j - 1]);
			copyPath[i][j] = minOfTwoNum(copyPath[i - 1][j], copyPath[i][j - 1]) + *(arrPath + i*cols + j);
		}
	}

	result = copyPath[rows - 1][cols - 1];


	for (int i = 0; i < rows; i++)
	{
		delete[] copyPath[i];
	}
	delete[] copyPath;


	return result;
}


//申请一个一维数组空间
int MinPathRoad2(int* arrPath, const int rows, const  int cols)
{
	if (arrPath == nullptr || rows < 0 || cols < 0)
	{
		throw new std::exception("Invalid para");
	}
	if (rows == 0 || cols == 0)
	{
		return 0;
	}
	int result = 0;
	//用一个一维数组来存储临时变量
	int* copyPath = new int[cols];

	for (int j = 0; j < cols; j++)
	{
		if (j == 0)
		{
			copyPath[j] = *(arrPath  + j);
		}
		if (j>0)
		{
			copyPath[j] = *(arrPath + 0*cols + j) + *(arrPath + 0*cols + j - 1);
		}
	}

	for (int i = 1; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (j == 0)
			{
				copyPath[j] = copyPath[j] + *(arrPath + i*cols + j);
			}
			else
			{
				int tempValue = minOfTwoNum(copyPath[j], copyPath[j - 1]);
				copyPath[j] = minOfTwoNum(copyPath[j], copyPath[j - 1]) + *(arrPath + i*cols + j);
			}

		}
	}

	result = copyPath[cols - 1];


	delete[] copyPath;

	return result;
}



//====================测试用例=================

void test1()
{
	int arrPath[4][4] = { { 1, 3, 5, 9 }, { 8, 1, 3, 4 }, { 5, 0, 6, 1 }, { 8, 8, 4, 0 } };
	cout << MinPathRoad((int *)arrPath, 4, 4) << endl;
}


void test2()
{
	int arrPath[4][4] = { { 1, 3, 5, 9 }, { 8, 1, 3, 4 }, { 5, 0, 6, 1 }, { 8, 8, 4, 0 } };
	cout << MinPathRoad2((int *)arrPath, 4, 4) << endl;
}



int main()
{
	test1();
	test2();


	system("pause");
	return 0;
}





