/***************************
������Ա��������ָ��--IT�����㷨�����ݽṹ��Ŀ���Ž⡷ �����  ��

��Ǯ�����ٻ�����

����Ŀ��
  ��������arr, arr�����е�ֵ��Ϊ�����Ҳ��ظ���ÿ��ֵ����һ����ֵ�Ļ��ң�ÿ����ֵ�Ļ��ҿ���ʹ�������ţ�
�ٸ���һ������aim������Ҫ�ҵ�Ǯ���������aim�����ٻ�������

��������
arr=[5,2,3],aim=20
4��5Ԫ�������20Ԫ��������Ǯ������Ҫʹ�ø���Ļ��ң����Է���4.

arr=[5,2,3],aim=0
�����κλ��ҾͿ������0Ԫ������0

arr=[3,5],aim=2
����û�����2Ԫ��Ǯ�����ҿ��������Ĭ�Ϸ���-1.




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


//��ǰ���ǵ���ֵ��arr[i],��ʣrest��Ǯ��Ҫ����
//�������-1��˵������ʹ�� arr[i...N-1]��ֵ������£��������Ҳ�޷�����rest
//������ز���-1����������ʹ��arr[i...N-1]��ֵ������£�����rest��Ҫ����������
int process(int *arr, int length, int i, int rest)
{
	//base case
	//�Ѿ�û����ֵ�ܹ�������
	//�����ʱʣ���ǮΪ0������0��
	//�����ʱʣ���Ǯ����0������-1
	if (i >= length)
	{
		if (rest == 0)
		{
			cout << "====================="<<endl;
		}
		return rest == 0 ? 0 : -1;
	}

	//������������ʼʱΪ-1����Ϊ��û�ҵ���Ч��
	int res = -1;
	//���γ���ʹ�õ�ǰ��ֵ(arr[i])0�š�1�š�k�ţ������ܳ���rest
	for (int k = 0; k*arr[i] <= rest; k++)
	{
		//ʹ����k��aim[i]��ʣ�µ�ǮΪ rest - k*arr[i]
		//����ʣ�µ���ֵȥ�㶨 (arr[i+1...N-1])
		int next = process(arr, length, i + 1, rest - k*arr[i]);

		//˵���������������Ч
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


	//�������һ�ŵ�ֵ,��dp[N][0]Ϊ0�⣬��������-1
	dp[N][0] = 0;
	for (int col = 1; col <= aim; col++)
	{
		dp[N][col] = -1;
	}

	//�ӵ������ϼ���ÿһ��
	for (int i = N - 1; i >= 0; i--)
	{
		//ÿһ�ж�������
		for (int rest = 0; rest <= aim; rest++)
		{
			dp[i][rest] = -1;//��ʼʱ������dp[i][rest]��ֵ��Ч

			//�����ֵ�����Ч
			if (dp[i + 1][rest] != -1)
			{
				dp[i][rest] = dp[i + 1][rest];//������Ϊ�����ֵ
			}

			//�����ߵ�λ�ò�Խ������Ч
			if (rest - arr[i] >= 0 && dp[i][rest - arr[i]] != -1)
			{
				//���֮ǰ�����ֵ��Ч
				if (dp[i][rest] == -1)
				{
					dp[i][rest] = dp[i][rest - arr[i]] + 1;
				}
				else
				{
					//˵���������ߵ�ֵ����Ч��ȥ��С��
					dp[i][rest] = GetMinNum(dp[i][rest], dp[i][rest - arr[i]] + 1);
				}
			}
		}
	}



	////��ά�����ӡ���е㲻��Ϥ������
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


//====================��������=================
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





