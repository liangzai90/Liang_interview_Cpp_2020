/********************************
《剑指offer》做题笔记


面试题2：实现Singleton模式

题目：
设计一个类，我们只能生成该类的一个实例。



*******************************************/

#include <iostream>
#include <assert.h>
#include <mutex>
#include <string>
using namespace std;

class SingletonClassA
{
public:
	static SingletonClassA* getClassAInstancePtr();
	static SingletonClassA* m_instance;

	void print();

private:
	SingletonClassA();
	SingletonClassA(const SingletonClassA& other){};
	SingletonClassA& operator = (const SingletonClassA& str){};
	static mutex m_mutex;
};

SingletonClassA* SingletonClassA::m_instance = nullptr;

SingletonClassA::SingletonClassA()
{
}


//2判断，1次枷锁，确保在多线程环境中能够高效率地工作
SingletonClassA* SingletonClassA::getClassAInstancePtr()
{
	//多加1层if判断，减少不必要的枷锁操作（枷锁很耗资源），可以提高效率
	if (m_instance == nullptr)
	{
		m_mutex.lock();
		if (m_instance == nullptr)
		{
			m_instance = new SingletonClassA();
		}
		m_mutex.unlock();
	}
	return m_instance;
}

void print()
{
	cout << "print" << endl;
}

int main()
{
	SingletonClassA* testA = SingletonClassA::getClassAInstancePtr();
	SingletonClassA* testB = SingletonClassA::getClassAInstancePtr();

	cout << testA << endl;
	cout << testB << endl;

	cout << endl;
	system("pause");
	return 0;
}

