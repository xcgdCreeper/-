
#include <iostream>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<ctime>
#define N 20                //因为20位大数的运算太过庞大，所以我测试的时候是用2位和3位的数，也就是N=2,N=3,经过测试，结果是正确的
int a[N];
int b[N] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2 };
int c[N];
int d[N];
void copy(int *x,int *y)  //x的值给y
{
	int i;
	for (i = 0; i < N; i++)
	{
		y[i] = x[i];
	}
}
void halfNum(int* x)    //x的一半      用于优化程序，除数只要累加到被除数的一半就行了，让程序的时间复杂度减半
{
	int i;
	for (i = 0; i < N; i++)
	{
		//printf("step %d\n",i+1);
		if (x[i] == 1 && i != (N - 1))
		{
			x[i] = 0;
			x[i + 1] = x[i + 1] + 10;
		}
		else
		{
			if ((x[i] / 2) != ((x[i] + 1) / 2) && i != (N - 1))
			{
				x[i] = x[i] / 2;
				//printf("hello\n");
				x[i + 1] = x[i + 1] + 10;
			}
			else
				x[i] = x[i] / 2;
		}


	}
}
void randNum() //生成随机数
{
	int i = 0;
	srand((unsigned)time(NULL));
	a[0] = rand() % 9 + 1;
	for (i = 1; i < N; i++)
	{
		//srand((unsigned)time(NULL));
		a[i] = rand() % 10;
	}
}

void numPlus() //每次调用，除数+1
{
	int i;
	b[N - 1]++;
	for (i = N - 1; i >= 1; i--)
	{
		if ((b[i]) > 9)
		{
			b[i] = b[i] % 10;
			//if (i == 0)
			//break;
			b[i - 1]++;
			//printf("hello");
		}
	}
}

void numRed(int* x, int* y) //x-y
{
	int i;
	for (i = N - 1; i >= 0; i--)
	{
		x[i] = x[i] - y[i];
		if (i != 0)
		{
			if (x[i] < 0)
			{
				x[i] = 10 + x[i];
				x[i - 1] = x[i - 1] - 1;
			}
		}
	}
}

bool judge(int* x, int* y)// 判断x，y大小 返回0:x<=y   返回1:x>y    
{
	int i;
	int mark = 0;
	for (i = 0; i < N; i++)
	{
		if (x[i] > y[i])
			return 1;
		if (x[i] < y[i])
			return 0;

	}
	return 0;
}

void printNum(int* a) //输出数字
{
	int i;
	for (i = 0; i < N; i++)
		printf("%d", a[i]);
	printf("\n");
}


int main()
{
	int i;
	int mark = 0;
	randNum();
	copy(a,c);
	copy(c, d);
	printf("a=");
	printNum(a);
	halfNum(d);
	while (judge(d, b))
	{
		while (judge(c, b))
		{
			numRed(c, b);
		}
		for (i = 0; i < N; i++)
		{
			if (c[i] == b[i])
				mark++;
		}
		if (mark == N)
			break;
		else
			mark = 0;

		copy(a,c);
		numPlus();
	}
	if (mark == N)
		printf("不是素数!");
	else
		printf("素数!");
	return 0;
}