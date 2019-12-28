// 编程水平测试3.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <algorithm>
#include<cstdio>
#include<cstdlib>
#include<ctime>
using namespace std;

int main()
{
	int a, b, c, d, e, f;
	for(a=0;a<=1;a++)
		for (b = 0; b <= 1; b++)
			for (c = 0; c <= 1; c++)
				for (d = 0; d <= 1; d++)
					for (e = 0; e <= 1; e++)
						for (f = 0; f <= 1; f++)
						{
							if ((a + b > 1) && ((a + d) != 2) && (a + e + f == 2) && ((b + c == 0) || (b + c == 2)) && (c + d == 1) && ((d + e == 0) || d == 1))
							{
								//cout << a << b << c << d << e << f << endl;
								if (a == 1)
									cout <<'a' ;
								if (b == 1)
									cout << 'b' ;
								if (c == 1)
									cout << 'c' ;
								if (d == 1)
									cout << 'd' ;
								if (e == 1)
									cout << 'e' ;
								if (f == 1)
									cout << 'f' ;
							}
								
						}
}
