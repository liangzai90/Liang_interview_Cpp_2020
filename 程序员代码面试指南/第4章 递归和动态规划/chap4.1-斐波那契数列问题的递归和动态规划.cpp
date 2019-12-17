/***************************
������Ա��������ָ��--IT�����㷨�����ݽṹ��Ŀ���Ž⡷ �����  ��

쳲�������������ĵݹ�Ͷ�̬�滮

����Ŀ����
��������N,����쳲��������еĵ�N�

��������1����������N������̨������һ�ο��Կ�2������1��̨�ף������ж������߷���

��������2������ũ���г����ĸţÿ��ֻ������1ͷСĸţ��������Զ����������һ��ũ��ֻ��1ֻ�����ĸţ��
�ӵ�2�꿪ʼ��ĸţ��ʼ����Сĸţ��ÿֻСĸţ3�������ֿ�������Сĸţ����������N�����N���ţ��������



��������
쳲���������
f(0)=0, f(1)=1,f(2)=f(1)+f(0),f(3)=f(2)+f(1),
f(N)=f(N-1)+f(N-2)  ///��һ����ǰ����֮��


��������
������̨�ף�
N=1��1������
N=2��2������
���̨��N����������ϵ�N���������Ҫô�Ǵ�N-2̨��ֱ�ӿ�2��̨�ף�Ҫô�Ǵ�N-1��̨�׿�1��̨�ס�
����̨����N���ķ���Ϊ f(N-2) + f(N-1)


��������
ĸţ���⣺
��1�꣬a
��2�꣬a,b  //b������
��3�꣬a,b,c
��4�꣬a,b,c,d
��5�꣬a,b,c,d,  e,[b']  //b������
��6�꣬a,b,c,d,e,[b']  f, b'', c'  //c,b������
��N�꣬S(N) = S(N-1)+S(N-3)


������ף������ø����ʱ�临�ӶȽ�����⡣
���ɴﵽO(log(N))����Ҫ�õ�����˷���״̬���󡢼��پ���˷��ȵ���ѧ֪ʶ��
���ڱ�����ѧ���ױ������޷��ﵽ������磬������������ֻ����������и�����������


**************************************/

#include <iostream>
#include <stack>
#include <exception>
using namespace std;


////ʱ�临�Ӷ���O(2^N)��ָ�����ģ����Ƽ�
int fibnac(int n)
{
	if (n < 0)
	{
		throw new std::exception("Invalid para");		
		return -1;
	}
	if (n == 0)
	{
		return 0;
	}
	if (n <= 2)
	{
		return 1;
	}

	return fibnac(n - 1) + fibnac(n - 2);
}


//�Ľ�����㷨��ʱ�临�Ӷ�ΪO(N)�������ظ��ļ��㡣
//���¶��Ϸ��������϶��½�����ݹ��˼·������ѭ����˼·д���롣
unsigned long long fibnac2(int n)
{
	if (n < 0)
	{
		throw new std::exception("Invalid para");
	}
	unsigned long long *fibNums = new unsigned long long[n + 1];
	fibNums[0] = 0;
	fibNums[1] = 1;
	fibNums[2] = 1;
	fibNums[3] = 2;
	for (unsigned long long i = 2; i <= n; i++)
	{
		fibNums[i] = fibNums[i - 1] + fibNums[i - 2];
	}
	return fibNums[n];
}


////ʱ�临�Ӷ�O(N)
////������Լ�ڴ�ռ䣬����ֻ����3���������洢�������������ۼӼ���
unsigned long long fibnac3(int n)
{
	if (n < 0)
	{
		throw new std::exception("Invalid para");
	}
	unsigned long long pre = 0;
	unsigned long long now = 1;
	if (n == 0)
	{
		return 0;
	}
	else if (n == 1 || n == 2)
	{
		return 1;
	}

	unsigned long long preTemp = 0;
	for (int i = 2; i <= n; i++)
	{
		preTemp = now;
		now += pre ;
		pre = preTemp;
	}
	return now;
}


////ʱ�临�Ӷ�O(N)
////������̨�ף�������ʱ�����ۼ�
unsigned long long jump(int n)
{
	if (n < 0)
	{
		throw new std::exception("Invalid para");
	}
	if (n == 0)
	{
		return 0;
	}
	if (n <= 2)
	{
		return n;
	}

	unsigned long long llPre1 = 1;//n==1
	unsigned long long llNow = 2;//n==2

	unsigned long long llTemp = 0;
	for (int i = 3; i <= n; i++)//n>=3
	{
		llTemp = llNow;

		llNow += llPre1;//n>=3

		llPre1 = llTemp;
	}
	return llNow;
}


////ʱ�临�Ӷ�O(N)
////������̨�ף���������ʵ���ۼӣ��������㣬������Ҫһ���Ķ����ڴ�ռ䣩
unsigned long long jump2(int n)
{
	if (n < 0)
	{
		throw new std::exception("Invalid para");
	}
	if (n == 0)
	{
		return 0;
	}
	if (n <= 2)
	{
		return n;
	}

	unsigned long long *jumpArr = new unsigned long long[n + 1];
	jumpArr[0] = 0;
	jumpArr[1] = 1;
	jumpArr[2] = 2;

	for (int i = 3; i <= n; i++)//n>=3
	{
		jumpArr[i] = jumpArr[i-1] + jumpArr[i-2];
	}

	return jumpArr[n];
}


////ʱ�临�Ӷ�O(N)
///ĸţ��������
unsigned long long cowBron(int n)
{
	if (n < 0)
	{
		throw new std::exception("Invalid para");
	}
	if (n == 0)
	{
		return 0;
	}
	else if (n == 1 || n == 2 || n==3)
	{
		return n;
	}
	unsigned long long llprepre = 1;
	unsigned long long llpre = 2;
	unsigned long long llRes = 3;

	unsigned long long lltemp1 = 0;
	unsigned long long lltemp2 = 0;
	for (int i = 4; i <= n; i++)
	{
		lltemp1 = llpre;
		lltemp2 = llRes;

		llRes = llRes + llprepre;

		llprepre = lltemp1;
		llpre  = lltemp2;
	}
	return llRes;
}

////ʱ�临�Ӷ�O(N)
///ĸţ��������
unsigned long long cowBron2(int n)
{
	if (n < 0)
	{
		throw new std::exception("Invalid para");
	}
	if (n == 0)
	{
		return 0;
	}
	else if (n == 1 || n == 2 || n == 3)
	{
		return n;
	}

	unsigned long long *llcowCounts = new unsigned long long[n + 1];
	llcowCounts[0] = 0;
	llcowCounts[1] = 1;
	llcowCounts[2] = 2;
	llcowCounts[3] = 3;

	for (int i = 4; i <= n; i++)
	{
		llcowCounts[i] = llcowCounts[i - 1] + llcowCounts[i - 3];
	}

	return llcowCounts[n];
}





//==========================��������====================================
void test1()
{
	cout << fibnac(0) << endl;;
	cout << fibnac(1) << endl;;
	cout << fibnac(2) << endl;;
	cout << fibnac(10) << endl;;
	cout << fibnac(100) << endl;;

	//cout << fibnac(-5) << endl;;
}

void test2()
{
	cout << fibnac2(0) << endl;
	cout << fibnac2(1) << endl;
	cout << fibnac2(2) << endl;
	cout << fibnac2(10) << endl;
	cout << fibnac2(11) << endl;
	cout << fibnac2(12) << endl;
	cout << fibnac2(50) << endl;///����̫��Խ����

//	cout << fibnac2(-5) << endl;
}

void test3()
{
	cout << "----------------test3-------------------" << endl;
	cout << 0<<": "<<jump(0) << endl;
	cout << 1 << ": " << jump(1) << endl;
	cout << 2 << ": " << jump(2) << endl;
	cout << 3 << ": " << jump(3) << endl;
	cout << 4 << ": " << jump(4) << endl;
	cout << 5 << ": " << jump(5) << endl;
	cout << 14 << ": " << jump(14) << endl;
	cout << 15 << ": " << jump(15) << endl;
	cout << 16 << ": " << jump(16) << endl;

	cout << "-----------jump2-----------" << endl;

	cout << 0 << ": " << jump2(0) << endl;
	cout << 1 << ": " << jump2(1) << endl;
	cout << 2 << ": " << jump2(2) << endl;
	cout << 3 << ": " << jump2(3) << endl;
	cout << 4 << ": " << jump2(4) << endl;
	cout << 5 << ": " << jump2(5) << endl;
	cout << 14 << ": " << jump2(14) << endl;
	cout << 15 << ": " << jump2(15) << endl;
	cout << 16 << ": " << jump2(16) << endl;
}


void test4()
{

	cout << "----------------test4-------------------" << endl;
	cout << 0 << ": " << cowBron(0) << endl;
	cout << 1 << ": " << cowBron(1) << endl;
	cout << 2 << ": " << cowBron(2) << endl;
	cout << 3 << ": " << cowBron(3) << endl;
	cout << 4 << ": " << cowBron(4) << endl;
	cout << 5 << ": " << cowBron(5) << endl;
	cout << 6 << ": " << cowBron(6) << endl;
	cout << 7 << ": " << cowBron(7) << endl;
	cout << 8 << ": " << cowBron(8) << endl;
	cout << 9 << ": " << cowBron(9) << endl;
	cout << 14 << ": " << cowBron(14) << endl;
	cout << 15 << ": " << cowBron(15) << endl;
	cout << 16 << ": " << cowBron(16) << endl;

	cout << "-----------cowBron2-----------" << endl;
	cout << 0 << ": " << cowBron2(0) << endl;
	cout << 1 << ": " << cowBron2(1) << endl;
	cout << 2 << ": " << cowBron2(2) << endl;
	cout << 3 << ": " << cowBron2(3) << endl;
	cout << 4 << ": " << cowBron2(4) << endl;
	cout << 5 << ": " << cowBron2(5) << endl;
	cout << 6 << ": " << cowBron2(6) << endl;
	cout << 7 << ": " << cowBron2(7) << endl;
	cout << 8 << ": " << cowBron2(8) << endl;
	cout << 9 << ": " << cowBron2(9) << endl;
	cout << 14 << ": " << cowBron2(14) << endl;
	cout << 15 << ": " << cowBron2(15) << endl;
	cout << 16 << ": " << cowBron2(16) << endl;

}



int main()
{
	//test1();
	test2();
	test3();
	test4();

	system("pause");
	return 0;
}





