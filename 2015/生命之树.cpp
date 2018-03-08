#include<cstdio>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
map <int, vector<int> > mp;
vector<int> v;
int n, num, num1, num2;
int front, behind,ed;//前一个节点 后一个节点 
int ans;//答案 
int compare(int i, int j)
{
	int t = 0;
	ed = j;
	dfs(i);
	
}
void dfs(int front)
{
	if (behind == ed)
	{
		return;
	}
	for (int t = 0; t < mp[front].size(); t++)//找所有的开始节点
	{
		
		behind = mp[front][t];
	}
}
int main()
{
	scanf_s("%d", &n);
	for (int i = 0; i<n; i++)
	{
		scanf_s("%d", &num);
		v.push_back(num);
	}
	for (int i = 0; i<n - 1; i++)
	{
		scanf_s("%d %d", &num1, &num2);
		mp[num1].push_back(num2);
		mp[num2].push_back(num1);
	}
	for (int i = 0; i<n; i++)
	{
		for (int j = 0; j<n - 1; j++)
		{
			compare(i,j);
		}
	}
	return 0;
}
