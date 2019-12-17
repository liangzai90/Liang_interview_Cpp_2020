/***************************
《程序员代码面试指南--IT名企算法与数据结构题目最优解》 左程云  著

斐波拉契数列问题的递归和动态规划

【题目】：
给定整数N,返回斐波拉契数列的第N项。

补充问题1：给定整数N，代表台阶数，一次可以跨2个或者1个台阶，返回有多少种走法。

补充问题2：假设农场中成熟的母牛每年只会生产1头小母牛，并且永远不会死。第一年农场只有1只成熟的母牛，
从第2年开始，母牛开始生产小母牛。每只小母牛3年后成熟又可以生产小母牛。给定整数N，求出N年后牛的数量。



【举例】
斐波拉契数列
f(0)=0, f(1)=1,f(2)=f(1)+f(0),f(3)=f(2)+f(1),
f(N)=f(N-1)+f(N-2)  ///后一项是前两项之和


【举例】
青蛙跳台阶：
N=1，1种跳法
N=2，2种跳法
如果台阶N级，最后跳上第N级的情况，要么是从N-2台阶直接跨2级台阶，要么是从N-1级台阶跨1级台阶。
所以台阶有N级的方法为 f(N-2) + f(N-1)


【举例】
母牛问题：
第1年，a
第2年，a,b  //b出生了
第3年，a,b,c
第4年，a,b,c,d
第5年，a,b,c,d,  e,[b']  //b成熟了
第6年，a,b,c,d,e,[b']  f, b'', c'  //c,b成熟了
第N年，S(N) = S(N-1)+S(N-3)


问题进阶：可以用更快的时间复杂度解决问题。
最快可达到O(log(N))，需要用到矩阵乘法、状态矩阵、加速矩阵乘法等等数学知识。
限于本人数学功底薄弱，无法达到这个境界，看不懂。这里只是提出来，有更快解决方案。


**************************************/

#include <iostream>
#include <stack>
#include <exception>
using namespace std;


////时间复杂度是O(2^N)，指数级的，不推荐
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


//改进后的算法。时间复杂度为O(N)。减少重复的计算。
//自下而上分析，自上而下解决。递归的思路分析，循环的思路写代码。
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


////时间复杂度O(N)
////如果想节约内存空间，可以只声明3个变量来存储计算结果，进行累加计算
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


////时间复杂度O(N)
////青蛙跳台阶，利用临时变量累加
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


////时间复杂度O(N)
////青蛙跳台阶，利用数组实现累加（理解更方便，但是需要一定的额外内存空间）
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


////时间复杂度O(N)
///母牛产子问题
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

////时间复杂度O(N)
///母牛产子问题
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





//==========================测试用例====================================
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
	cout << fibnac2(50) << endl;///数字太大越界了

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





