// 编程水平测试6.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<Windows.h>
#include<stdlib.h>
#include<time.h>

using namespace std;
string directions[4] = { "南","东","北","西" };
string statue[3] = { "绿","红","黄" };

void display()
{
	srand((unsigned int)time(NULL));
	int a;
	int b;
	int i;
	int j;
	int x=0; //x正通车方向车流量
	int y=0; //y相反车道车流量
	while(1)
	{
		i = 30;
		j = 33;
		a = 1;
		b = 0;
		
		while (i != 0 && j != 0)
		{
			x = rand() % 20;
			y = rand() % 20;
			cout << "正通车方向车流量：" << x << endl << "相反车道车流量:" << y << endl;
			cout << "        " << directions[2] << endl;
			cout << "        " << statue[b] << endl;
			cout << "        " << i << endl;
			cout << "        ||" << endl;
			cout << "        ||" << endl;
			cout << directions[3] << statue[a] << j << "========" << j << statue[a] << directions[1] << endl;
			cout << "        ||" << endl;
			cout << "        ||" << endl;
			cout << "        " << i << endl;
			cout << "        " << statue[b] << endl;
			cout << "        " << directions[0] << endl;
			Sleep(1000);
			system("cls");
			i--;
			j--;
			if (i == 0 && j != 0)
			{
				i = 3;
				b = 2;
			}
		}
		if (x <= (y / 3))
			break;
		
	}
	while(1)
	{
		j = 30;
		i = 33;
		a = 0;
		b = 1;
		while (i != 0 && j != 0)
		{
			x = rand() % 20;
			y = rand() % 20;
			cout << "正通车方向车流量：" << x << endl << "相反车道车流量:" << y << endl;
			cout << "        " << directions[2] << endl;
			cout << "        " << statue[b] << endl;
			cout << "        " << i << endl;
			cout << "        ||" << endl;
			cout << "        ||" << endl;
			cout << directions[3] << statue[a] << j << "========" << j << statue[a] << directions[1] << endl;
			cout << "        ||" << endl;
			cout << "        ||" << endl;
			cout << "        " << i << endl;
			cout << "        " << statue[b] << endl;
			cout << "        " << directions[0] << endl;
			Sleep(1000);
			system("cls");
			i--;
			j--;
			if (j == 0 && i != 0)
			{
				j = 3;
				a = 2;
				
			}
		}
		if (x <= (y / 3))
			break;
	}
}


int main()
{
	while (1)
	{
		display();
	}
	
}