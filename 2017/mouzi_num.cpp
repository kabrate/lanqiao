#include<stdio.h>
#include<cstring>
#include<vector>
using namespace std;
int n,a[110],com;//n������ i�������ܷ�Ai������ ��Լ�� 
int dp[10004];//�����ܷ�ճ� 
const int V=10000;
int gcd(int x,int y)
{
	return y==0?x:gcd(y,x%y);
}
//��չŷ����ã�һ������(x,y)ʹ��ax+by=gcd(a,b); ��Լ��Ϊ1 �����Դճ��� 
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
	//��n���������Լ�� 
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
	
	dp[0]=1;//0������һ���ܴճ�����
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

