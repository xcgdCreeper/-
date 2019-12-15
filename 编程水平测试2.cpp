// 编程水平测试2.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <cstdio>
#include<cstring>
#include<cstdlib>

using namespace std;

struct people
{
	string name;
	double score[3];
	double sum;
};

struct team
{
	people student[5];
	double avg[3];
};

team input()
{
	team a;
	int i, j;
	
	for (i = 0; i < 5; i++)
	{
		//printf("%d:", i + 1);
		cin >> a.student[i].name;
		for (j = 0; j < 3; j++)
		{
			cin >> a.student[i].score[j];
		}
	}
	cout << endl;
	return a;
}

team sumScore(team a)
{
	int i, j;
	double sum=0;
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 3; j++)
		{
			sum = sum + a.student[i].score[j];
		}
		a.student[i].sum = sum;
		sum = 0;
	}
	return a;
}

team avgScore(team a)
{
	int i,j;
	double avg=0;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 5; j++)
		{
			avg = avg + a.student[j].score[i];
		}
		a.avg[i] = avg / 5;
		avg = 0;
	}
	return a;
}
team order(team a)
{
	people tool;
	int i, j;
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4 - i;j++)
		{
			if (a.student[j].sum < a.student[j + 1].sum)
			{
				tool = a.student[j];
				a.student[j] = a.student[j + 1];
				a.student[j + 1] = tool;
			}
		}
	}
	return a;
}

void output(team a)
{
	int i, j;
	printf("\t 姓名\t语文\t数学\t外语\t总分\n");
	cout << endl;
	for (i = 0; i < 5; i++)
	{
		//printf("%s", a.student[i].name);
		cout <<"\t "<< a.student[i].name << "\t";
		for (j = 0; j < 3; j++)
		{
			//printf("%lf\t", a.student[i].score[j]);
			cout << a.student[i].score[j]<<"\t";
		}
		cout << a.student[i].sum;
		cout << endl;
	}
	printf("\t平均成绩 ");
	for (i = 0; i < 3; i++)
	{
		cout<< a.avg[i];
		if (i != 2)
			cout << "\t";
	}
	cout << endl<<endl;
}

int main()
{
	printf("input姓名,语文成绩,数学成绩,外语成绩\n");
	team group[3];
	int i;
	for (i = 0; i < 3; i++)
	{
		group[i] = input();
		group[i] = sumScore(group[i]);
		group[i] = avgScore(group[i]);
		group[i] = order(group[i]);
	}
	for (i = 0; i < 3; i++)
	{
		printf("group%d:", i + 1);
		output(group[i]);
	}
}