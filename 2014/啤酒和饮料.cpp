#include<cstdio>
int main()
{
	int i,j;
	for(i=0;i<=50;i++)
	{
		for(j=0;j<=50;j++)
		if(23*i+19*j==823&&i<j)
		printf("%d",i);
	}
	return 0;
}
