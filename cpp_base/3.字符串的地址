#include <iostream>
using namespace std;

int main()
{
	char str1[] = "hello world";
	char str2[] = "hello world";

	char *str3 = "hello world";
	char *str4 = "hello world";

	cout << "str1:" << (char *)str1 << ", *str1:" << (int*)str1 << ", **str1:"<< (int*)(&str1) << endl;
	cout << "str2:" << (char *)str2 << ", *str2:" << (int*)str2 << ", **str2:" << (int*)(&str2) << endl;
	cout << "str3:" << (char *)str3 << ", *str3:" << (int*)str3 << ", **str3:" << (int*)(&str3) << endl;
	cout << "str4:" << (char *)str4 << ", *str4:" << (int*)str4 << ", **str4:" << (int*)(&str4) << endl;

	if (str1 == str2)
	{
		cout << "str1 == str2" << endl;
	}
	else
	{
		cout << "str1 != str2" << endl;   //// output this line
	}

	if (str3 == str4)
	{
		cout << "str3 == str4" << endl;   //// output this line
	}
	else
	{
		cout << "str3 != str4" << endl;
	}


	cout << endl;
	system("pause");
	return 0;
}
