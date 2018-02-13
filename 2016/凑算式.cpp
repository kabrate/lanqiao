#include<stdio.h>
int ans = 0;//解法次数 
int num[10];//嵌入的10个数字 
bool visit[10];//保存num数组中是否已经访问 
void Solve()//能顺利匹配 
{
	double sum = num[0] + (double)num[1] / num[2] + (double)(num[3]*100+num[4]*10+num[5])/(num[6]*100+num[7]*10+num[8]);
	if(sum == 10)
	{
		ans ++;
	}
}

void dfs(int index)
{
	if(index == 9)
	{
		Solve();
		return ;
	}
	for(int i = 1 ; i < 10 ; i ++)
	{
		if(!visit[i])
		{
			visit[i] = true;
			num[index] = i;
			dfs(index+1);
			visit[i] = false;
		}
	}
}

int main()
{
	dfs(0);
	printf("%d\n",ans);
	return 0;
}
