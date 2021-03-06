/********************************
《剑指offer》做题笔记


面试题5：替换空格

题目：
请实现一个函数，把字符串中的每个空格替换成 "%20"。
例如，输入"We are happy."，则输出"We%20are%20happy."。

测试用例：
1.输入的字符串中包含空格（空格位于字符串的最前面；空格位于字符串的最后面；空格位于字符串的中间；字符串中有连续多个空格）。
2.输入的字符串中没有空格
3.特殊输入测试（字符串是一个nullptr指针；字符串是一个空字符串；字符串只有一个空字符；字符串中有连续2个空字符）

*******************************************/

#include <iostream>
#include <string>
using namespace std;


//方法1：创建新的字符串...提升对字符串的认识。。append是加入一个字符串，必须'\0'结尾
void replaceString1(string& str)
{
	string strNew;
 	for (int i = 0; i < str.length(); i++)
 	{
 		if (str[i] == ' ')
 		{
 			strNew.append("%20");
 		}
 		else
 		{
			//////特别注意，append是加入一个字符串，需要以 '\0' 结尾
			char newStr[2];
			newStr[0] = str.at(i);
			newStr[1] = '\0';
			strNew.append(newStr);
 		}
 	}
	str.clear();
	str =  strNew;
}

void test0()
{
	string str1 = "We are happy.123";
	replaceString1(str1);
	cout << "str1:" << str1 << endl;
}







/////方法2：在原来的字符串上面替换

bool TwoSameArray(char *A1, char *A2)
{
	if (nullptr == A1 ||
		nullptr == A2 ||
		strlen(A1) <= 0 ||
		strlen(A2) <= 0 ||
		strlen(A1) != strlen(A2))
	{
		return false;
	}

	int iPos = 0;
	while (A1[iPos] != '\0')
	{
		if (A1[iPos] != A2[iPos])
		{
			return false;
		}
		iPos++;
	}

	return true;
}

void replaceString2(char* str, int arrLength)
{
	////刚开始这里缺少字符串不为空但是长度为0的判断
	if (nullptr == str || strlen(str) == 0 || arrLength<=0)
	{
		return;
	}
	int iStrlength = strlen(str);
	int KonggeNum = 0;
	for (int i = 0; i < iStrlength; i++)
	{
		if (str[i] == ' ')
		{
			KonggeNum++; 
		}
	}

	////注意了，这里也不要缺少异常判断
	if (KonggeNum * 2 + iStrlength >arrLength)
	{
		return;
	}

	int iLastIndex = iStrlength-1;
	str[KonggeNum * 2 + iStrlength] = '\0';
	int iLastPos = KonggeNum * 2 + iStrlength-1;

	for (; iLastIndex>=0; iLastIndex--)
	{
		if (str[iLastIndex] == ' ')
		{
			str[iLastPos--] = '0';
			str[iLastPos--] = '2';
			str[iLastPos--] = '%';

		}
		else
		{
			str[iLastPos--] = str[iLastIndex];
		}
	}
}


// ========================测试用例============================
void contains(char* testName, char* strTest, int arrLength, char* expectedArr, bool expectedResult)
{
	cout << testName <<": ";
	replaceString2(strTest, arrLength);
	bool bCheckResult = TwoSameArray(strTest, expectedArr);

	if (expectedResult == bCheckResult)
	{
		cout << "pass." << endl;
	}
	else
	{
		cout << "FAILED." << endl;
	}

}


//空格在字符串中间
void test1()
{
	char str[100] = "We are happy.";
	char expextedStr[100] = "We%20are%20happy.";
	contains("test1", str,100, expextedStr, true);
}

//空格在字符串头部
void test2()
{
	char str[100] = " ABCD";
	char expextedStr[100] = "%20ABCD";
	contains("test2", str, 100, expextedStr, true);
}

//空格在字符串尾部
void test3()
{
	char str[100] = "ABCD ";
	char expextedStr[100] = "ABCD%20";
	contains("test3", str, 100, expextedStr, true);
}

//多个空格的情况
void test4()
{
	char str[100] = " AB C  D E ";
	char expextedStr[100] = "%20AB%20C%20%20D%20E%20";
	contains("test4", str, 100, expextedStr, true);
}

//只有空格的情况
void test5()
{
	char str[100] = "  ";
	char expextedStr[100] = "%20%20";
	contains("test5", str, 100, expextedStr, true);
}

//没有空格的情况
void test6()
{
	char str[100] = "ABC";
	char expextedStr[100] = "ABC";
	contains("test6", str, 100, expextedStr, true);
}

//非法输入，空字符串
void test7()
{
	char *str = "";
	char expextedStr[100] = "";
	contains("test7", str, 100, expextedStr, false);
}

//非法输入
void test8()
{
	char *str = nullptr;
	char *expextedStr = nullptr;
	contains("test8", str, 100, expextedStr, false);
}

////代码10分钟，测试 案例写了100分钟。
/////////还是不习惯写测试案例，以及没有这方面的思想。不够熟练。。。
int main()
{
	test1();
	test2();
	test3();
	test4();
	test5();
	test6();
	test7();
	test8();




	cout << endl;
	system("pause");
	return 0;
}

