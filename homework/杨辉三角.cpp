#include<cstdio>
#include<string.h>
#include<vector>
#include<algorithm>
#include<cstdlib>
using namespace std;
int num[100][100];
void Pascal(int n)
{
	for(int i=0;i<n;i++)//最左边一列为1 最右边一列为1 
	{
		num[i][0]=1;
		num[i][i-1]=1;
	}
	for(int t=2;t<n;t++)//第三行开始为两肩之和 
	{
		for(int j=1;j<t;j++)
		{
			num[t][j]=num[t-1][j-1]+num[t-1][j];
		}
	}
	
	for(int t=1;t<n;t++)//显示前N行的数据 
	{
		for(int j=0;j<t;j++)
		{
			printf("%d ",num[t][j]);
		}
		
		printf("\n");
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	memset(num,0,sizeof(num));
	Pascal(n+1);
	return 0;
}

