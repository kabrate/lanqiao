#include<stdio.h>
int ans = 0;//�ⷨ���� 
int num[10];//Ƕ���10������ 
bool visit[10];//����num�������Ƿ��Ѿ����� 
void Solve()//��˳��ƥ�� 
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
