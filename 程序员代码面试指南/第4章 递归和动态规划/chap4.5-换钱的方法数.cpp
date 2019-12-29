/*************************************************
������Ա��������ָ��--IT�����㷨�����ݽṹ��Ŀ���Ž⡷ ����� ��

��Ǯ�ķ�����

����Ŀ��
��������arr, arr�����е�ֵ��Ϊ�����Ҳ��ظ���
ÿ��ֵ����һ����ֵ�Ļ��ң�ÿ����ֵ�Ļ��ҿ���ʹ�������ţ�
�ٸ���һ������aim������Ҫ�ҵ�Ǯ������Ǯ�ж����ַ�����

��������
arr=[5,10,25,1],aim=0
���0Ԫ�ķ���ֻ��1�֣�����������ֵ�Ļ��Ҷ����á����Է���1.

arr=[j5,10,25,1],aim=15
���15Ԫ�ķ�����6�֣�
5Y*3
10Y*1+5Y*1
10Y*1+1Y*5
1Y*10+5Y*1
5Y*2+1Y*5
1Y*15

�κη������޷����2Ԫ������aim=2�᷵��0.

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


///////////////////////////////////////////////////////�ⷨ1�������ݹ�
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

////////////////////////////////////////////////�ⷨ2�������ݹ��Ż��档��������
////p(index, aim)������һ���ݹ����.��map[index][aim]�����Ѿ�������ĵݹ���̵Ľ��
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


////////////////////////////////////////////////////////////////�ⷨ3����̬�滮�����ķ����������dp[i][j]���������һ�еõ���
//dp[i][j]�ĺ����ǣ���ʹ��arr[0...i]���ҵ�����£����Ǯ��j�ж����ַ�����
//....
//dp[N-1][aim]��ֵ�������ս��
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

	////��1�ж�Ϊ0.dp[i][0] ��Ϊ1����ʾ ���Ǯ��0�ķ���ֻ��1��
	for (int i = 0; i < length; i++)
	{
		dp[i][0] = 1;
	}

	//��1���е�ĳЩ��.dp[0][j]��ֻʹ��arr[0]���ң����������Щ��
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


////////////////////////////////////////////////�ⷨ4����̬�滮���ٴγ���
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

	////��1�ж�Ϊ0.dp[i][0] ��Ϊ1����ʾ ���Ǯ��0�ķ���ֻ��1��
	for (int i = 0; i < length; i++)
	{
		dp[i][0] = 1;
	}

	//��1���е�ĳЩ��.dp[0][j]��ֻʹ��arr[0]���ң����������Щ��
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


////////////////////////////////////////////////�ⷨ5����̬�滮���ռ�ѹ��
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

	//��1���е�ĳЩ��.dp[0][j]��ֻʹ��arr[0]���ң����������Щ��
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

////===============��������====================
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


