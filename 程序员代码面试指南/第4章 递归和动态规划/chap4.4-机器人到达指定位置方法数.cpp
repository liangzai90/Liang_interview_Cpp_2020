/***************************
������Ա��������ָ��--IT�����㷨�����ݽṹ��Ŀ���Ž⡷ �����  ��

�����˵���ָ��λ�÷�����

����Ŀ��
�������ų�һ�е�N��λ�ã���Ϊ1~N��Nһ�����ڻ����2����ʼʱ�����������е�Mλ���ϣ�Mһ����1~N�е�һ������
�����˿��������߻��������ߣ��������������1λ�ã���ô��һ��ֻ����������2λ�ã�
�������������Nλ�ã���ô��һ��ֻ����������N-1λ�á�
�涨�������˱�����K��������������Pλ�ã�PҲһ����1~N�е�һ�����ķ����ж����֡�
����4������N��M��K��P�����ط�������

��Ҫ��
ʱ�临�Ӷ�ΪO(N*K)


**************************************/
#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
#include <exception>
using namespace std;




//////////////////////////////////////////�����ݹ����
//N:λ��Ϊ1~N���̶�����
//cur:��ǰ��curλ�ã��ɱ����
//rest:��ʣres��û���ߣ��ɱ����
//P:����Ŀ��λ��P���̶�����
//ֻ����1~N��Щλ�����ƶ�����ǰ��curλ�ã�����rest��֮��ͣ��Pλ�õķ�������Ϊ����ֵ����
//
int walk(int N, int cur, int rest, int P)
{
	//���û��ʣ�ಽ���ˣ���ǰ��curλ�þ�������λ��
	//�������λ��ͣ��P�ϣ���ô֮ǰ�����ƶ�����Ч��
	//�������λ��û��ͣ��P�ϣ���ô֮ǰ�����ƶ�����Ч��
	if (rest == 0)
	{
		return cur == P ? 1 : 0;
	}

	//�������rest��Ҫ�ߣ�����ǰ��curλ����1λ���ϣ���ô��ǰ�ⲽֻ�ܴ�1����2
	//�����Ĺ��̾���ԭ����2λ���ϣ���ʣrest-1��Ҫ��
	if (cur == 1)
	{
		return walk(N, 2, rest - 1, P);
	}

	//�������rest��Ҫ�ߣ�����ǰ��curλ����Nλ���ϣ���ô��ǰ�ⲽֻ�ܴ�N����N-1
	//�����Ĺ��̾�������N-1λ���ϣ���ʣrest-1��Ҫ��
	if (cur == N)
	{
		return walk(N, N - 1, rest - 1, P);
	}

	//�������rest��Ҫ�ߣ�����ǰ��curλ�����м�λ���ϣ���ô���������ߣ�Ҳ����������
	//
	return walk(N, cur - 1, rest - 1, P) + walk(N, cur + 1, rest - 1, P);
}

int ways1(int N, int M, int K, int P)
{
	//������Чֱ�ӷ���
	if (N < 2 || K < 1 || M<1 || M>N || P<1 || P>N)
	{
		return 0;
	}

	//�ܹ�N��λ�ã���M���������ʣK�������������ܴﵽP�ķ�����
	return walk(N, M, K, P);
}




/////////////////////////////////////�ݹ�˼·������ѭ���������
int ways2(int N, int M, int K, int P)
{
	//������Чֱ�ӷ���0
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

	//����1�и�ֵ�������0����ֻ����p�������Ч�ģ�����λ����Ч��Ϊ0
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



	/////��ӡ�����������
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




///ѹ����һά����
int ways3(int N, int M, int K, int P)
{
	//������Чֱ�ӷ���0
	if (N < 2 || K < 1 || M<1 || M>N || P<1 || P>N)
	{
		return 0;
	}
	int iResult = 0;
	int* dp = new int[N + 1];

	//����1�и�ֵ�������0����ֻ����p�������Ч�ģ�����λ����Ч��Ϊ0
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

			LeftUp = tempLeft; ///����ɵĵ���ֵ
		}
	}




	iResult = dp[M];
	delete[] dp;

	return iResult;
}


//==================��������====================
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





