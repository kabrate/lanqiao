#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> v;
int ans=0;
int check()
{
	int sum=2;
	int a,b;
	for(int i=0;i<15;i++)
	{
		if(v[i]==1) sum=sum*2;
		else if(v[i]==2) sum=sum-1;
	}
	a=count(v.begin(),v.end(),1);//������¥�Ĵ���
	b=count(v.begin(),v.end(),2);//�ȾƵĴ��� 
	if(sum==0&&a==5&&b==10&&v[14]==2) return 1;
	else return 0;
}
void dfs(int n)//�����ڼ����ص� 
{
	if(n==15)
	{
		if(check()) ans++;
		return;
		
	}
	for(int i=1;i<=2;i++)//������ߺȾ� 
	{
		v[n]=i;
		dfs(n+1);
	} 
}
int main()
{
	for(int i=0;i<15;i++)
	{
		v.push_back(0);
	}
	dfs(0);
	printf("%d",ans);
	return 0;
}
