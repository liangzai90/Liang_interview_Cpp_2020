/*******************************************************************
Copyright(c) 2016, Harry He
All rights reserved.
/*******************************************************************
Copyright(c) 2016, Harry He
All rights reserved.

Distributed under the BSD license.
(See accompanying file LICENSE.txt at
https://github.com/zhedahht/CodingInterviewChinese2/blob/master/LICENSE.txt)
*******************************************************************/

//==================================================================
// 《剑指Offer——名企面试官精讲典型编程题》代码
// 作者：何海涛
//==================================================================

// 面试题31：栈的压入、弹出序列
// 题目：输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是
// 否为该栈的弹出顺序。假设压入栈的所有数字均不相等。例如序列1、2、3、4、
// 5是某栈的压栈序列，序列4、5、3、2、1是该压栈序列对应的一个弹出序列，但
// 4、3、5、1、2就不可能是该压栈序列的弹出序列。



/*
      总结入栈、出栈的过程：
我们可以找到判定一个序列是不是栈的弹出序列的规律：
  如果下一个弹出的数字刚好是栈顶数字，那么直接弹出；
  如果下一个弹出的数字不在栈顶，则把压栈序列中还没有入栈的数字压入辅助栈，
直到把下一个需要弹出的数字压入栈顶为止；
  如果所有数字都压入栈后仍然没有找到下一个弹出的数字，那么该序列不可能是一个弹出序列。

*/



#include <iostream>
#include <stack>
#include <assert.h>
using namespace std;

bool IsPopOrder(const int* pPush, const int* pPop, int nLength)
{
    bool bPossible = false;

    ///[1,2,3,4,5]，就是我们的pPush，这些数据要 push 到 stackData 辅助栈，而且在pop中找到相同元素，还会弹出
    //
    //[4,5,3,2,1]就是我们的pPop，
    //
    //
    if (pPush != nullptr && pPop != nullptr && nLength > 0)
    {
        const int* pNextPush = pPush;
        const int* pNextPop = pPop;
        std::stack<int> stackData;

        while (pNextPop - pPop < nLength)
        {
            //当辅助的栈顶元素不是要弹出的元素
            //先压入一些数字入栈
            while (stackData.empty() || stackData.top() != *pNextPop)
            {
                //如果所有数字都压入辅助栈了，退出循环
                if (pNextPush - pPush == nLength)
                {
                    break;
                }
                stackData.push(*pNextPush);
                pNextPush++;
            }

            if (stackData.top() != *pNextPop)
            {
                break;
            }

            stackData.pop();
            pNextPop++;
        }

        //判定条件
        if (stackData.empty() && pNextPop - pPop == nLength)
        {
            bPossible = true;
        }
    }

    return bPossible;
}


//============== 测试代码 ==================
void Test(const char* testName, const int* pPush, const int* pPop, int nLength, bool expected)
{
    if (testName != nullptr)
    {
        printf("%s begins: ", testName);
    }

    if (IsPopOrder(pPush, pPop, nLength) == expected)
    {
        printf("PASSED.\r\n");
    }
    else
    {
        printf("FAILED**********\r\n");
    }
}

void Test1()
{
    const int nLength = 5;
    int push[nLength] = { 1, 2, 3, 4, 5 };
    int pop[nLength] = { 4, 5, 3, 2, 1 };

    Test("Test1", push, pop, nLength, true);
}

void Test2()
{
    const int nLength = 5;
    int push[nLength] = { 1, 2, 3, 4, 5 };
    int pop[nLength] = { 3, 5, 4, 2, 1 };

    Test("Test2", push, pop, nLength, true);
}


void Test3()
{
    const int nLength = 5;
    int push[nLength] = { 1, 2, 3, 4, 5 };
    int pop[nLength] = { 4, 3, 5, 1, 2 };

    Test("Test3", push, pop, nLength, false);
}

void Test4()
{
    const int nLength = 5;
    int push[nLength] = { 1, 2, 3, 4, 5 };
    int pop[nLength] = { 3, 5, 4, 1, 2 };

    Test("Test4", push, pop, nLength, false);
}

// push和pop序列只有一个数字
void Test5()
{
    const int nLength = 1;
    int push[nLength] = { 1 };
    int pop[nLength] = { 2 };

    Test("Test5", push, pop, nLength, false);
}

void Test6()
{
    const int nLength = 1;
    int push[nLength] = { 1 };
    int pop[nLength] = { 1 };

    Test("Test6", push, pop, nLength, true);
}

void Test7()
{
    Test("Test7", nullptr, nullptr, 0, false);
}

int main(int argc, char* argv[])
{

    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    Test7();




	cout << endl;
	system("pause");
	return 0;
}





