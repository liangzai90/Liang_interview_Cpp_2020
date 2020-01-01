/***************************

������Ա��������ָ��--IT�����㷨�����ݽṹ��Ŀ���Ž⡷ ����� ��

�������������

����Ŀ��
����һ������arr������һ���з���������ÿ��һ�������ܻ�÷��������������ķ���ΪX����÷����Ĺ������£�
1�������������������û�б��򱬵������ҵ��뱻��������������򣬼������ΪL��
�������������ұ���û�б��򱬵������ҵ��뱻��������������򣬼������ΪR����÷���ΪL*X*R��
2�������������������û�б��򱬵������ҵ��뱻��������������򣬼������ΪL��
�������������ұ����������Ѿ����򱬡���÷���ΪL*X��
3��������������������е������Ѿ����򱬣�
�������������ұ���û�б��򱬵������ҵ��뱻��������������򣬼������ΪR����÷���ΪX*R��
4����������������ߺ��ұ����е������Ѿ����򱬡���÷���ΪX��

Ŀ���Ǵ��������򣬻��ÿ�δ򱬵ķ�����ͨ��ѡ��������˳�򣬿��Եõ���ͬ���ܷ֣�
�뷵���ܻ�õ���������

��������
arr = [3,2,5]

����ȴ�3�����3*2���ٴ�2�����2*5������5�����5������ܷ�21.
����ȴ�3�����3*2���ٴ�5�����2*5������2�����2������ܷ�18.
����ȴ�2�����3*2*5���ٴ�3�����3*5������5�����5������ܷ�50.
����ȴ�2�����3*2*5���ٴ�5�����3*5������3�����3������ܷ�48.
...�ȵȣ���6�д������˳��ȫ���У�
�ܻ�õ�������Ϊ50.

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

/////////////////////////////////////////////////////////////����1�������ݹ����
//��arr[L...R]��Χ�ϵ��������򣬷������ķ���
//����arr[L-1]��arr[R+1]һ��û�б���
int process(int *arr, int length, int L, int R)
{
	if (L == R)//���arr[L...R]��Χ��ֻ��һ������ֱ�Ӵ򱬼���
	{
		return arr[L - 1] * arr[L] * arr[R + 1];
	}

	//����arr[L]�ķ���������arr[R]�ķ������ȱȽ�һ��
	int max = MaxNum(arr[L - 1] * arr[L] * arr[R + 1] + process(arr, length, L + 1, R), arr[L - 1] * arr[R] * arr[R + 1] + process(arr, length, L, R - 1));

	//�����м�λ�õ�������󱻴򱬵�ÿһ�ַ���
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



/////////////////////////////////////////////////////////////�ⷨ2��
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

	/////�Խ����ϵ�. L==R�����...
	for (int i = 1; i <= N ; i++)
	{
		dp[i][i] = help[i - 1] * help[i] * help[i + 1];
	}

	for (int L = N; L >= 1; L--)
	{
		for (int R = L + 1; R <= N; R++)
		{
			//���dp[L][R]����ʾhelp[L...R]�ϴ����������������

			///���� help[L] �ķ���
			int finalL = help[L - 1] * help[L] * help[R + 1] + dp[L + 1][R];

			//���� help[R] �ķ���
			int finalR = help[L - 1] * help[R] * help[R + 1] + dp[L][R - 1];

			//���� help[L] ������ help[R] �ķ����Ƚ�һ��
			dp[L][R] = max(finalL, finalR);

			//�����м�λ�õ�������󱻴򱬵�ÿһ�ַ���
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


//////////////////////////////�ͽⷨ2��ͬ�����ǵص���C++��ʽ�Ľⷨ���õ���vector
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
		//dp[l][r]��ʾ��[l,r]�ϴ����������������
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



////===============��������====================
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



