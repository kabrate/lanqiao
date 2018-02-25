#include<cstdio>
#include<cmath>
#include <stdlib.h>
int m, n, w;
int location[2][2];
int main()
{
	scanf_s("%d %d %d", &w, &m, &n);
	if (m%w != 0)
	{
		location[0][0] = m / w + 1;//第几行
	}
	
	else
	{
		location[0][0] = m / w ;
	}
	if (n%w != 0)
	{
		location[1][0] = n / w + 1;
	}
	
	else
	{
		location[1][0] = n / w ;
	}
	if (location[0][0] % 2 == 0)//偶数行 
	{
		location[0][1] = w+1 - (m%w);//
	}
	else//奇数行
	{
		location[0][1] = m%w;
	}
	if (location[1][0] % 2 == 0)//偶数行
	{
		location[1][1] = w+1 - (n%w);
	}
	else
	{
		location[1][1] = n%w;
	}
	printf("%d", abs(location[0][0] - location[1][0]) + abs(location[0][1] - location[1][1]));
	return 0;
}
