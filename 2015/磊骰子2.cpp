#include<cstdio>
#include<vector>
#include<map>
#include<algorithm>

map <int,vecotr<int>> mp;
int n,m;//骰子数目 有冲突的面的数量 
int num1,num2;
map <int,int> mp2;
int oppsite(int i)
{
	switch i
	{
		case 1: return 4;break;
		case 2: return 3;break;
		case 3: return 6;break;
		case 4: return 1;break;
		case 5: return 2;break;
		case 6: return 3;break;
	}
}
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++)
	{
		scanf("%d %d",num1,num2);
		mp2[num1]=num2;
		mp2[num2]=num1;
	}
	d[1][1]=d[1][2]=d[1][3]=d[1][4]=d[1][5]=d[1][6]=1;
	return 0;
}
