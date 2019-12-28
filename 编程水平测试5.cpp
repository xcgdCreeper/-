// 编程水平测试5.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//其实就是矩阵高斯消元法

#include <iostream>
using namespace std; 
string country[6] = { "USA","UK","France","German","Italy","Russia" };
char people[6] = {'A','B','C','D','E','F'};
int member[6][6] = {0,1,0,0,1,0,
                    0,1,0,0,1,1,
                    0,1,0,0,0,0,
                    1,1,1,1,1,1,
                    0,1,1,0,1,0,
                    1,1,1,0,1,1};

/*
int member[6][6] = { 0,0,0,1,0,1,
                    1,1,1,1,1,1,
                    0,0,0,1,1,1,
                    0,0,0,1,0,0,
                    1,1,0,1,1,1,
                    0,1,0,1,0,1 };
 */


bool compare(int a, int b)//比较矩阵的大小 a>=b返回1   a<b返回0
{
    for (int i = 0; i < 6; i++)
    {
        if (member[a][i] > member[b][i])
            return 1;
        if (member[a][i] < member[b][i])
            return 0;
    }
    return 1;
}

void print()
{
    for (int i = 0; i < 6; i++)
    {
        printf("%c  ", people[i]);
        for (int j = 0; j < 6; j++)
        {

            printf("%d ", member[i][j]);
        }
        printf("\n");
    }
}

bool order()//矩阵排序，为消元做准备
{
    int mark=0;
    int change[6];
    char tem;
    for(int i = 0; i < 5;i++)
        for (int j = 0; j < 5-i; j++)
        {
            if (!compare(j, j + 1))
            {
                mark = 1;
                for (int k = 0; k < 6; k++)
                {
                    change[k] = member[j][k];
                    member[j][k] = member[j + 1][k];
                    member[j + 1][k] = change[k];
                    
                }
                tem = people[j];
                people[j] = people[j + 1];
                people[j + 1] = tem;
            }
        }
    return mark;
}

void red()
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            member[i][j] = member[i][j] - member[i + 1][j];
        }
    }
}

int main()
{
    int i, j;
    while (order())
    {
        //print();
        cout << endl;
        red();
    }
    for ( i = 0; i < 6; i++)
    {
        for ( j = 0; j < 6; j++)
        {
            if (member[i][j] == 1)
                break;
        }
        cout << people[i] << " is from " << country[i] << endl;
    }
        
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
