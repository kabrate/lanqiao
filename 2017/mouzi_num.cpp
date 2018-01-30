#include<stdio.h>
#include<cstring>
#include<vector>
using namespace std;
int n,a[110],com;//n种蒸笼 i种蒸笼能放Ai个包子 公约数 
int dp[10004];//包子能否凑出 
const int V=10000;
int gcd(int x,int y)
{
	return y==0?x:gcd(y,x%y);
}
//扩展欧几里得：一定存在(x,y)使得ax+by=gcd(a,b); 公约数为1 都可以凑出来 
void extgcd(int a,int b,int &d,int &x,int &y)
{
	if(!b)//b==0
	{
		d=a;x=1;y=0;return;
		
	}
	extgcd(b,a%b,d,y,x);
	y-=(a/b)*x;	
} 
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	//求n个数的最大公约数 
	com=gcd(a[1],a[2]);
	for(int i=3;i<=n;i++)
	{
		com=min(com,gcd(a[i],com));
	}
	if(com!=1)
	{
		printf("INF");
		return 0;
	}
	
	dp[0]=1;//0个包子一定能凑出来的
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j+a[i]<=V;j++)
		{
			if(dp[j])dp[j+a[i]]=1;
		}
		
	} 
	int cnt=0;
	for(int i=V;i>=0;i--)
	{
		if(!dp[i])cnt++;
	}
	printf("%d",cnt);
	return 0;
	
	
}

