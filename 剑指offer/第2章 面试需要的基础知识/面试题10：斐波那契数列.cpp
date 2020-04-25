/********************************
����ָoffer������ʼ�

// ������10��쳲���������
// ��Ŀ��дһ������������n����쳲�������Fibonacci�����еĵ�n�
// f(0)=0, 
// f(1)=1,
// f(n)= f(n-1) + f(n-2)
//
*******************************************/

#include <iostream>
#include <string>
#include <exception>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

//��ӡ쳲���������
int printFeibolaqi1(int n)
{
	if (0 == n)
	{
		return 0;
	}
	if (1 == n)
	{
		return 1;
	}
	return printFeibolaqi1(n - 2) + printFeibolaqi1(n - 1);
}


////////////������̨�ף�һ����1������2����������ѧ��ģ�����������Ҫ����������
//ѭ��ʵ��
int printFeibolaqi2(int n)
{
	if (0 == n)
	{
		return 0;
	}
	if (1 == n)
	{
		return 1;
	}
	int iStart1 = 0;
	int iStart2 = 1;
	int result = 0;
	for (int i = 2; i <= n; i++)
	{
// 		iStart1 = iStart2;
// 		iStart2 = i;

		result = iStart1 + iStart2;

		iStart1 = iStart2;
		iStart2 = result;
	}

	return result;
}


////������̨�ף�һ�ο�����1,2,3..n��
int superJump(int n)
{
	int* jump = new int(n + 1);
	jump[0] = 0;
	jump[1] = 1;
	jump[2] = 2;
	if (n < 0)
	{
		return -1;
	}
	else if (n < 3)
	{
		return jump[n];
	}

	for (int i = 3; i <= n; i++)
	{
		jump[i] = 2 * jump[i - 1];
	}

	return jump[n];
}


//==========================���Դ���========================
void Test(int n, int expected)
{
	if (printFeibolaqi1(n) == expected)
	{
		printf("Test for %d in solution1 passed.\r\n", n);
	}
	if (printFeibolaqi2(n) == expected)
	{
		printf("Test for %d in solution2 passed.\r\n", n);
	}

	printf("\r\n");
}

void test0_10()
{
	Test(0, 0);
	Test(1, 1);
	Test(2, 1);
	Test(3, 2);
	Test(4, 3);
	Test(5, 5);
	Test(6, 8);
	Test(7, 13);
	Test(8, 21);
	Test(9, 34);
	Test(10, 55);

	//����һ���ϴ������
	Test(40, 102334155);
}

int main(int argc, char* argv[])
{
	test0_10();



	cout << endl;
	system("pause");
	return 0;
}


