#include<cstdio>
#define n 100
int check(int x, int y, int z)
{
	if (18 * x != 15 * y || 15 * y != 20 * z || 20 * z != 18 * x) return 0; 
	if ((x + y * 5 + z * 10) % 100!=0) return 0;
	return 1;
	     
}
int main()
{
	for (int i = 1; i<n; i++)//y
	{
		for (int j = 1; j<n; j++)//x
		{
			for (int t = 1; t<n; t++)//z
			{
				if (check(j, i, t))
				{
					printf("%d %d %d %d\n", j, i, t, (j + 5 * i + 10 * t) / 10);
					break;
				}
			}
		}

	}
	return 0;
}
