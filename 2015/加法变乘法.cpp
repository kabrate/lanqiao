#include<cstdio>
int main()
{
	for(int i=1;i<=49;i++)
	{
		for(int j=1+i;j<=49;j++)
		if(1223-i-j+i*i+j*j==2015&&i!=j)
		printf("%d %d\n",i,j);
	}
	return 0;
} 
