#include<cstdio>
using namespace std;
int a[8+5];
int visited[10+5]={0};
void dfs(int cur)
{
	if(cur==8)
	{
		int x,y,z;
		x=a[0]*1000+a[1]*100+a[2]*10+a[3];
		y=a[4]*1000+a[5]*100+a[6]*10+a[1];
		z=a[4]*10000+a[5]*1000+a[2]*100+a[1]*10+a[7];
		if(x+y==z)
		printf("%d%d%d%d",a[4],a[5],a[6],a[1]);
		return; 
	}
	for(int i=0;i<=9;i++)//0~9数字填入
	{
	    if(cur==0&&i==0)		
			continue;
		if(cur==4&&i!=1)
			continue;
		if(!visited[i])//如果这个数字没有被使用
		{
			visited[i]=1;
			a[cur]=i;//cur第几个位置的数字
			dfs(cur+1);
			visited[i]=0; 
		} 
			
	}
} 
int main()
{
	dfs(0);
	return 0; 
}
