/*

实现 strcpy 函数

题目描述：
重写strcpy函数，要求不能使用C++的字符串操作库函数。
函数原型为:
char* strcpy(char* strDest,const char *strSrc)

*strDest表示目标字符串指针
*strSrc表示源字符串指针


*/

#include <iostream>
#include <stdlib.h>
#include <string>
#include <assert.h>
using namespace std;

char* strcpy(char* strDest, const char* strSrc)
{
	assert(strDest != NULL && strSrc != NULL);

	const char* ptrSrc = strSrc;
	char* ptrDest = strDest;

	while (ptrSrc != NULL && *ptrSrc != '\0')
	{
		*ptrDest++ = *ptrSrc++;
	}
	*ptrDest = '\0';
	return strDest;
}



int main()
{
	char *strSrc = "Test string.何亮到此一游.20191102.";
	char *strDest = new char[strlen(strSrc) + 1];
	strcpy(strDest, strSrc);
	cout << strDest << endl;


	cout << endl;
	system("pause");
	return 0;
}
