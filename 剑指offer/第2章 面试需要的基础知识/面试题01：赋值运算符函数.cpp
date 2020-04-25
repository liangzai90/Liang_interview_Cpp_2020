/********************************
《剑指offer》做题笔记


面试题1：赋值运算符函数

如下为CMyString的声明，请为该类型添加赋值运算符函数。

class CMyString
{
public:
CMyString(char* pData = nullptr);
CMyString(const CMyString& str);
~CMyString();

private:
char* m_pData;
};


*******************************************/

#include <iostream>
#include <assert.h>
using namespace std;

class CMyString
{
public:
	CMyString(char* pData = nullptr);
	CMyString(const CMyString& str);
	~CMyString();

	CMyString& operator=(const CMyString& str);
	void printStr();

private:
	char* m_pData;
};

CMyString::CMyString(char* pData)
{
	if (pData == nullptr)
	{		
		m_pData = new char[1];
		m_pData = '\0';
	}
	else
	{
		m_pData = new char[strlen(pData)+1];
		strcpy(m_pData, pData);
	}
}

CMyString::CMyString(const CMyString& str)
{
	m_pData = new char[strlen(str.m_pData) + 1];
	strcpy(m_pData, str.m_pData);
}

CMyString::~CMyString()
{
	delete[] m_pData;
}

CMyString& CMyString::operator=(const CMyString& str)
{
	if (&str != this)
	{
		char* m_pNewData = new char[strlen(str.m_pData) + 1];
		strcpy(m_pNewData, str.m_pData);

		delete[] m_pData;
		m_pData = m_pNewData;
	}

	return *this;
}

void CMyString::printStr()
{
	cout << m_pData << endl;
}


/////////////测试用例
//基本功能测试 
void test1()
{
	cout << "---------- test1 ----------"<<endl;
	CMyString testA = "ABCDE";
	CMyString testB("FGHIJ");
	CMyString testC = testA;
	testA.printStr();
	testB.printStr();
	testC.printStr();
}

//自赋值
void test2()
{
	cout << "---------- test2 ----------" << endl;
	CMyString strA("abc");
	strA = strA;
	strA.printStr();
}

//连续赋值
void test3()
{
	cout << "---------- test3 ----------" << endl;
	CMyString strA("AAA");
	CMyString strB("BBB");
	CMyString strC("CCC");
	strC = strB = strA;
	strA.printStr();
	strB.printStr();
	strC.printStr();

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

