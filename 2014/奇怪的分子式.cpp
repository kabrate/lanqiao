#include<cstdio>
int a[5];
int ans = 0;
int gcd1(int x, int y)//最大公约数
{
	return y == 0 ? x : gcd1(y, x%y);
}
int check()
{
	int b,c,d,e;
	b = a[0] * 10 + a[2];//分子相加 
	c = a[1] * 10 + a[3];//分母相加
	d=a[0]*a[2];//分子相乘
	e=a[1]*a[3];//分母相乘 
	if (a[0] == a[1] && a[2] == a[3]) return 0;
	if(b/gcd1(b,c)!=d/gcd1(d,e)||c/gcd1(b,c)!=e/gcd1(d,e)) return 0;//分子分母约分后应该一样 

	return 1;
}
int main()
{
	for (int i = 1; i <= 9; i++)//分子 
	{
		a[0] = i;
		for (int j = 1; j <= 9; j++)//分母 
		{
			a[1] = j;
			for (int k = 1; k <= 9; k++)//分子 
			{
				a[2] = k;
				for (int l = 1; l <= 9; l++)//分母 
				{
					a[3] = l;
					if (check()) ans++;
				}
			}
		}
	}
	printf("%d", ans);
	return 0;
}
