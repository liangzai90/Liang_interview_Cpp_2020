/*
C++基础
林锐《高质量程序设计指南>

类String的构造函数、析构函数、拷贝构造函数、拷贝赋值函数

函数strlen()返回的是有效字符串长度，不把结束符'\0'计算在内
函数strcpy()会连'\0'也一起复制


*/

#include <iostream>
using namespace std;


class String
{
public:
	String(const char *str = "");//默认构造函数
	
	String(const String& copy);//拷贝构造函数
	
	~String();//析构函数

	String& operator=(const String& assign);//赋值函数

	//打印字符
	void printString();
	void swap(String& other);//交换两个String对象的成员

private:
	size_t   m_size;
	char     *m_data;//char数组
};


//String的默认构造函数
String::String(const char* str)
{
	if (str == NULL)
	{
		m_data = new char[1];
		*m_data = '\0';
		m_size = 0;
	}
	else
	{
		int length = strlen(str);
		m_data = new char[length + 1];
		strcpy(m_data, str);
		m_size = length;
	}
}

//String的析构函数
String::~String()
{
	delete[] m_data;
}


//拷贝构造函数
String::String(const String& other)
{
	//提示，允许操作other的私有成员变量m_data
	size_t  len = strlen(other.m_data);
	m_data = new char[len + 1];
	strcpy(m_data, other.m_data);
	m_size = len;
}

//打印字符
void String::printString()
{
	printf("%s", m_data);
}


/////////////////////////////拷贝赋值函数  operator= 函数
//1.返回类型必须是String&,  参数必须是const String&.
String& String::operator=(const String& other)
{
	//2.检查自赋值
	if (this != &other)
	{
		//3.分配新的内存资源，并赋值内容（出于【异常安全】的考虑，这个一定要在delete之前申请）
		char *temp = new char[strlen(other.m_data) + 1];
		strcpy(temp, other.m_data);

		//4.释放原有内存资源
		delete[]  m_data; //这里是char数组，所以是 delete [] 

		m_data = temp;
		m_size = strlen(other.m_data);
	}

	//5.返回本对象的引用，目的是为了实现如 a=b=c这样的链式表达式
	return *this;
}

/////////////////////////////////////////////////提升异常安全性的若干做法
void String::swap(String& other)
{
	std::swap(m_data, other.m_data);  //异常安全的！
	std::swap(m_size, other.m_size);  //异常安全的！
}
//String& String::operator=(const String& other)
//{
//	String temp = other;//调用String的 拷贝构造函数
//	temp.swap(*this);     //当前对象与临时对象交换，异常安全！！！
//	return (*this);
//}
//
//String& String::operator=(String other)  //值传递，将调用拷贝构造函数
//{
//	other.swap(*this);      //直接与临时对象交换，异常安全！！！
//	return (*this);
//}
//


//测试用例：
//1.把 String 实例赋值给另外一个实例
//2.把 String 实例赋值给它自己
//3.连续赋值
void test1()
{
	String strA("ABCDEFG");
	String strB = strA;
	strA.printString();
	cout << endl;
	strB.printString();
	cout << endl;
}

void test2()
{
	String strA("ABCDEFG");
	strA = strA;
	strA.printString();
	cout << endl;
}

void test3()
{
	String strA("ABCDEFG");
	String strB;
	String strC;
	strC = strB = strA;
	strA.printString();
	cout << endl;
	strB.printString();
	cout << endl;
	strC.printString();
	cout << endl;
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


