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

// 面试题39：数组中出现次数超过一半的数字
// 题目：数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。例
// 如输入一个长度为9的数组{1, 2, 3, 2, 2, 2, 5, 4, 2}。由于数字2在数组中
// 出现了5次，超过数组长度的一半，因此输出2。


#include <iostream>
using namespace std;

//Random Partition
int RandomInRange(int min, int max)
{
    int random = rand() % (max - min + 1) + min;
    return random;
}

void Swap(int* num1, int* num2)
{
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

//让start~end 区间内，某个元素归为，返回值就是这个 归为元素的索引。
//在这个元素左侧，都是比这个元素小的；右侧都是比这个元素大的。..类似于快速排序的基数归为。
int Partition(int data[], int length, int start, int end)
{
    if (data == nullptr || length <= 0 || start < 0 || end >= length)
    {
        throw new std::exception("Invalid Parameters");
    }

    int index = RandomInRange(start, end);
    Swap(&data[index], &data[end]);

    int small = start - 1;
    for (index = start; index < end; ++index)
    {
        if (data[index] < data[end])
        {
            ++small;
            if (small != index)
            {
                Swap(&data[index], &data[small]);
            }
        }
    }
    ++small;
    Swap(&data[small], &data[end]);
    return small;
}



bool g_bInputInvalid = false;

bool CheckInvalidArray(int* numbers, int length)
{
    g_bInputInvalid = false;
    if (numbers == nullptr || length <= 0)
        g_bInputInvalid = true;
    return g_bInputInvalid;
}

bool CheckMoreThenHalf(int* numbers, int length, int number)
{
    int times = 0;
    for (int i = 0; i < length; i++)
    {
        if (numbers[i] == number)
            times++;
    }

    bool isMoreThanHalf = true;
    if (times * 2 <= length)
    {
        g_bInputInvalid = true;
        isMoreThanHalf = false;
    }

    return isMoreThanHalf;
}


//==================方法1
int MoreThanHalfNum_Solution1(int* numbers, int length)
{
    if (CheckInvalidArray(numbers, length))
        return 0;

    int middle = length >> 1;
    int start = 0;
    int end = length - 1;

    //让 index 位置的元素归位
    int index = Partition(numbers, length, start, end);
    while (index != middle)
    {
        if (index > middle)
        {
            end = index - 1;
            index = Partition(numbers, length, start, end);
        }
        else
        {
            start = index + 1;
            index = Partition(numbers, length, start, end);
        }
    }

    int result = numbers[middle];
    if (!CheckMoreThenHalf(numbers, length, result))
        result = 0;

    return result;
}


//==============================方法2
int MoreThanHalfNum_Solution2(int* numbers, int length)
{
    if (CheckInvalidArray(numbers, length))
        return 0;

    int result = numbers[0];
    int times = 1;
    for (int i = 1; i < length; i++)
    {
        if (times == 0)
        {
            result = numbers[i];
            times = 1;
        }
        else if (result == numbers[i])
        {
            times++;
        }
        else
        {
            times--;
        }
    }

    //===== 一 定 要 检 查 超过一半 这个隐含条件
    if (!CheckMoreThenHalf(numbers, length, result))
        result = 0;
    
    return result;
}


//====================== 测试代码 ====================
void Test(char* testName, int* numbers, int length, int expectedValue, bool expectedFlag)
{
    if (testName != nullptr)
        printf("%s begins: \r\n", testName);

    int* copy = new int[length];
    for (int i = 0; i < length; i++)
        copy[i] = numbers[i];

    printf("Test for solution1: ");
    int result1 = MoreThanHalfNum_Solution1(numbers, length);
    if (result1 == expectedValue && g_bInputInvalid == expectedFlag)
        printf(" Passed. \r\n");
    else
        printf("  ** FAILED ** \r\n");

    printf("Test for solution2: ");
    int result2 = MoreThanHalfNum_Solution2(copy, length);
    if (result2 == expectedValue && g_bInputInvalid == expectedFlag)
        printf(" Passed. \r\n");
    else
        printf(" ** FAILED ** \r\n");

    printf("----------------------------\r\n");
    delete[] copy;
}

void Test1()
{
    int numbers[] = { 1, 2, 3, 2, 2, 2, 5, 4, 2 };
    Test("Test1", numbers, sizeof(numbers) / sizeof(int), 2, false);
}


// 不存在出现次数超过数组长度一半的数字
void Test2()
{
    int numbers[] = { 1, 2, 3, 2, 4, 2, 5, 2, 3 };
    Test("Test2", numbers, sizeof(numbers) / sizeof(int), 0, true);
}

// 出现次数超过数组长度一半的数字都出现在数组的前半部分
void Test3()
{
    int numbers[] = { 2, 2, 2, 2, 2, 1, 3, 4, 5 };
    Test("Test3", numbers, sizeof(numbers) / sizeof(int), 2, false);
}

// 出现次数超过数组长度一半的数字都出现在数组的后半部分
void Test4()
{
    int numbers[] = { 1, 3, 4, 5, 2, 2, 2, 2, 2 };
    Test("Test4", numbers, sizeof(numbers) / sizeof(int), 2, false);
}

// 输入空指针
void Test5()
{
    int numbers[] = { 1 };
    Test("Test5", numbers, 1, 1, false);
}

// 输入空指针
void Test6()
{
    Test("Test6", nullptr, 0, 0, true);
}



int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();


	cout << endl;
	system("pause");
	return 0;
}



