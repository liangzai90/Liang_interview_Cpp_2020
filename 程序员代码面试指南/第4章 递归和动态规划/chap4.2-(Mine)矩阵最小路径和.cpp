/***************************
������Ա��������ָ��--IT�����㷨�����ݽṹ��Ŀ���Ž⡷ �����  ��

�������С·����

����Ŀ��
����һ������m�������Ͻǿ�ʼÿ��ֻ�����һ��������ߣ���󵽴����½�λ�ã�·�������е������ۼ���������·���ͣ���������·������С��·���͡�

��������
���������m���£�
1  3  5  9
8  1  3  4
5  0  6  1
8  8  4  0
·��1��3��1,0,6,1,0������·����·������С�ģ����Է���12.


�ؼ�˼·��
������һ��M*N������ dp[M][N], dp[i][j]��ֵ��ʾ�����Ͻǣ�0,0��λ���ߵ���i,j��λ�õ���С·���͡�
��0�к͵�0�бȽ����⣬�ǲ����ۼӵĽ��
1 4 9 18
9,
14
22

�����к��У�dp[i][j] = Min(dp[i-1][j], dp[i][j-1]) + m[i][j];
���ԣ����ǿ��Դ������½ǣ����Ƶ����Ͻǡ�
���µ���˼�������ϵ��½����


**************************************/

#include <iostream>
#include <stack>
#include <exception>
using namespace std;

int minOfTwoNum(int A, int B)
{
	return A > B ? B : A;
}

int MaxOfTwoNum(int A, int B)
{
	return A > B ? A : B;
}




//����һ��M*N�Ķ�λ����ռ�
int MinPathRoad(int* arrPath, const int rows,const  int cols)
{
	if (arrPath == nullptr || rows < 0 || cols < 0)
	{
		throw new std::exception("Invalid para");
	}
	if (rows == 0 || cols == 0)
	{
		return 0;
	}
	int result = 0;
	int** copyPath =new int*[rows];
	for (int i = 0; i < rows; i++)
	{
		copyPath[i] = new int[cols];
	}


	///�����п��Ż��ռ䡣����һά�������ģ���Ҫ�ö�ά����
	//for (int i = 0; i < rows; i++)
	//{
	//	for (int j = 0; j < cols; j++)
	//	{
	//		if (i == 0 && j == 0)
	//		{
	//			copyPath[i][j] = *(arrPath + i*cols + j);
	//		}
	//		if (i == 0 && j>0)
	//		{
	//			copyPath[i][j] = *(arrPath + i*cols + j) + *(arrPath + i*cols + j - 1);
	//		}
	//		if (j == 0 && i > 0)
	//		{
	//			copyPath[i][j] = *(arrPath + i*cols + j) + *(arrPath + (i - 1)*cols + j);
	//		}
	//	}
	//}

	copyPath[0][0] = *(arrPath);

	for (int j = 1; j < cols; j++)
	{
		copyPath[0][j] = *(arrPath + j) + copyPath[0][j-1]; ///�������׳���
	}

	for (int i = 1; i < rows; i++)
	{
		copyPath[i][0] = *(arrPath + i*cols) + copyPath[i - 1][0]; ///�������׳���
	}

	////ʱ�临�Ӷ���O(M*N)
	for (int i = 1; i < rows; i++)
	{
		for (int j = 1; j < cols; j++)
		{
			int tempValue = minOfTwoNum(copyPath[i - 1][j], copyPath[i][j - 1]);
			copyPath[i][j] = minOfTwoNum(copyPath[i - 1][j], copyPath[i][j - 1]) + *(arrPath + i*cols + j);
		}
	}

	result = copyPath[rows - 1][cols - 1];


	for (int i = 0; i < rows; i++)
	{
		delete[] copyPath[i];
	}
	delete[] copyPath;


	return result;
}


//����һ��һά����ռ�
int MinPathRoad2(int* arrPath, const int rows, const  int cols)
{
	if (arrPath == nullptr || rows < 0 || cols < 0)
	{
		throw new std::exception("Invalid para");
	}
	if (rows == 0 || cols == 0)
	{
		return 0;
	}
	int result = 0;
	//��һ��һά�������洢��ʱ����
	int* copyPath = new int[cols];

	for (int j = 0; j < cols; j++)
	{
		if (j == 0)
		{
			copyPath[j] = *(arrPath  + j);
		}
		if (j>0)
		{
			copyPath[j] = *(arrPath + 0 * cols + j) + copyPath[j-1];
		}
	}

	for (int i = 1; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (j == 0)
			{
				copyPath[j] = copyPath[j] + *(arrPath + i*cols + j);
			}
			else
			{
				//int tempValue = minOfTwoNum(copyPath[j], copyPath[j - 1]);
				copyPath[j] = minOfTwoNum(copyPath[j], copyPath[j - 1]) + *(arrPath + i*cols + j);
			}

		}
	}

	result = copyPath[cols - 1];


	delete[] copyPath;

	return result;
}




//����һ��һά����ռ䣬��ȡrows,cols��С���Ǹ�
int MinPathRoad3(int* arrPath, const int rows, const  int cols)
{	
	//=============���Ӳ�����̫���ȴ�if,else���֡�Ȼ����ȥ���ϵ�һ��
	if (arrPath == nullptr || rows < 0 || cols < 0)
	{
		throw new std::exception("Invalid para");
	}
	if (rows == 0 || cols == 0)
	{
		return 0;
	}

	////����һ�У�cols��Ԫ�أ�����ɨ��
	if (rows >= cols)
	{
		int result = 0;
		//��һ��һά�������洢��ʱ����
		int* copyPath = new int[cols];

		for (int j = 0; j < cols; j++)
		{
			if (j == 0)
			{
				copyPath[j] = *(arrPath + j);
			}
			if (j>0)
			{
				copyPath[j] = *(arrPath + 0 * cols + j) + copyPath[j - 1];
			}
		}

		for (int i = 1; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				if (j == 0)
				{
					copyPath[j] = copyPath[j] + *(arrPath + i*cols + j);
				}
				else
				{
					//int tempValue = minOfTwoNum(copyPath[j], copyPath[j - 1]);
					copyPath[j] = minOfTwoNum(copyPath[j], copyPath[j - 1]) + *(arrPath + i*cols + j);
				}

			}
		}

		result = copyPath[cols - 1];

		delete[] copyPath; //��Ҫɾ̫����

		return result;
	}
	else
	{
		////����һ�У�rows��Ԫ�أ�����ɨ��
		int result = 0;
		//��һ��һά�������洢��ʱ����
		int* copyPath = new int[rows];

		for (int i = 0; i < rows; i++)
		{
			if (i == 0)
			{
				copyPath[i] = *(arrPath + i);
			}
			if (i>0)
			{
				copyPath[i] = *(arrPath + i * cols ) + copyPath[i - 1];
			}
		}

		for (int j = 1; j < cols; j++)
		{
			for (int i = 0; i < rows; i++)
			{
				if (i == 0)
				{
					copyPath[i] = copyPath[i] + *(arrPath + i*cols + j);
				}
				else
				{
					copyPath[i] = minOfTwoNum(copyPath[i], copyPath[i - 1]) + *(arrPath + i*cols + j);
				}

			}
		}

		result = copyPath[rows - 1];
		delete[] copyPath; //��Ҫɾ̫����
		return result;
	}
}



//����һ��һά����ռ䣬��ȡrows,cols��С���Ǹ�����ʹ��if,else����������rows,cols�ж�
int MinPathRoad4(int* arrPath, const int rows, const  int cols)
{
	if (arrPath == nullptr || rows < 0 || cols < 0)
	{
		throw new std::exception("Invalid para");
	}
	if (rows == 0 || cols == 0)
	{
		return 0;
	}

	bool bRowMore = (rows>cols);//rows�Ƿ����
	int result = 0;

	//��һ��һά�������洢��ʱ����
	int less = minOfTwoNum(rows, cols);
	int more = MaxOfTwoNum(rows, cols);
	int* copyPath = new int[less];

	copyPath[0] = *(arrPath);
	for (int i = 1; i < less; i++)
	{
		//bRowMore  ? arr[j][0] : arr[0][j]   
		copyPath[i] = copyPath[i - 1] + (bRowMore ? *(arrPath + i) : *(arrPath + i * cols));
	}//


	for (int i = 1; i < more; i++)
	{
		for (int j = 0; j < less; j++)
		{
			if (j == 0)
			{
				copyPath[0] = copyPath[0] + (bRowMore ? *(arrPath + i*cols+j) : *(arrPath + i));
			}
			else
			{
				int tempValue = minOfTwoNum(copyPath[j], copyPath[j - 1]);
				copyPath[j] = minOfTwoNum(copyPath[j], copyPath[j - 1]) + (bRowMore ? *(arrPath + i*cols + j) : *(arrPath + i*rows + j));
			}
		}
	}
	result = copyPath[less - 1];

	delete[] copyPath;
	return result;

}


//====================��������=================
// 1 3 5 9 
// 8 1 3 4  
// 5 0 6 1
// 8 8 4 0
void test1()
{
	cout << "Test1================expected:12" << endl;
	int arrPath[4][4] = { { 1, 3, 5, 9 }, { 8, 1, 3, 4 }, { 5, 0, 6, 1 }, { 8, 8, 4, 0 } };
	cout << MinPathRoad((int *)arrPath, 4, 4) << endl;
	cout << MinPathRoad2((int *)arrPath, 4, 4) << endl;
	cout << MinPathRoad3((int *)arrPath, 4, 4) << endl;
	cout << MinPathRoad4((int *)arrPath, 4, 4) << endl;
}


//
// 1 1 1
// 3 4 2
// 7 8 3
// 6 6 0
void test2()
{
	cout << "Test2================expected:8" << endl;
	int arrPath[4][3] = {{ 1,1,1 }, { 3,4,2 }, { 7,8,3 }, {6,6,0 } };
	cout << MinPathRoad((int *)arrPath, 4, 3) << endl;
	cout << MinPathRoad2((int *)arrPath, 4, 3) << endl;
	cout << MinPathRoad3((int *)arrPath, 4, 3) << endl;
	cout << MinPathRoad4((int *)arrPath, 4, 3) << endl;
}

//
// 1 1 2
// 1 4 2
// 2 8 3
// 3 1 0
void test3()
{
	cout << "Test3================expected:8" << endl;
	int arrPath[4][3] = { { 1, 1, 2 }, { 1, 4, 2 }, {2, 8, 3 }, { 3, 1, 0 } };
	cout << MinPathRoad((int *)arrPath, 4, 3) << endl;
	cout << MinPathRoad2((int *)arrPath, 4, 3) << endl;
	cout << MinPathRoad3((int *)arrPath, 4, 3) << endl;
	cout << MinPathRoad4((int *)arrPath, 4, 3) << endl;
}


//
// 1  2   3   4
// 5  0   7   8
// 9  0  11  12
// 0  14  0  0
void test4()
{
	cout << "Test4================expected:14" << endl;
	int arrPath[4][4] = { { 1, 2, 3,4 }, { 5,0,7,8}, { 9,0,11,12 }, {0,14, 0,0 } };
	cout << MinPathRoad((int *)arrPath, 4, 4) << endl;
	cout << MinPathRoad2((int *)arrPath, 4, 4) << endl;
	cout << MinPathRoad3((int *)arrPath, 4, 4) << endl;
	cout << MinPathRoad4((int *)arrPath, 4, 4) << endl;
}

//
// 1 1 1 1
// 1 1 1 1
// 1 1 1 1
// 1 1 1 1
void test5()
{
	cout << "Test5================expected:7" << endl;
	int arrPath[4][4] = { { 1, 1, 1, 1 }, { 1, 1, 1, 1 }, { 1, 1, 1, 1 }, { 1, 1, 1, 1 } };
	cout << MinPathRoad((int *)arrPath, 4, 4) << endl;
	cout << MinPathRoad2((int *)arrPath, 4, 4) << endl;
	cout << MinPathRoad3((int *)arrPath, 4, 4) << endl;
	cout << MinPathRoad4((int *)arrPath, 4, 4) << endl;
}


//
// 0 0 0 0
// 0 1 1 0
// 0 0 0 1
// 0 1 0 0
void test6()
{
	cout << "Test6================expected:0" << endl;
	int arrPath[4][4] = { { 0, 0, 0, 0 }, { 0, 0, 0, 0 }, { 0, 0, 0, 0 }, { 0, 0, 0, 0 } };
	cout << MinPathRoad((int *)arrPath, 4, 4) << endl;
	cout << MinPathRoad2((int *)arrPath, 4, 4) << endl;
	cout << MinPathRoad3((int *)arrPath, 4, 4) << endl;
	cout << MinPathRoad4((int *)arrPath, 4, 4) << endl;
}



int main()
{
	test1();
	test2();
	test3();
	test4();
	test5();
	test6();


	system("pause");
	return 0;
}





