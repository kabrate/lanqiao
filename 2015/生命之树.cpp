#include "stdafx.h"
#include<cstdio>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
map <int, vector<int> > mp;
vector<int> v;
int n, num, num1, num2;
int front, behind,ed;//ǰһ���ڵ� ��һ���ڵ� 
int ans;//�� 
vector<int> visit;
void dfs(int front)
{
	if (front == ed)
	{
		return;
	}
	for (int t = 0; t < mp[front].size(); t++)//��ǰһ���ڵ�������δ���ʵĽڵ�
	{
		visit[front] = 1;
		behind = mp[front][t];
		if (visit[behind] == 1)//�����һ���ڵ��Ѿ�����ֱ������
		{
			continue;
		}	
		dfs(behind);
		visit[behind] = 0;
	}
}
int compare(int i, int j)
{
	ed = j;
	dfs(i);
	return i;
}
int main()
{
	scanf_s("%d", &n);
	for (int i = 0; i<n; i++)
	{
		scanf_s("%d", &num);
		v.push_back(num);
		visit.push_back(0);
	}
	for (int i = 0; i<n - 1; i++)
	{
		scanf_s("%d %d", &num1, &num2);
		mp[num1].push_back(num2);
		mp[num2].push_back(num1);
	}
	for (int i = 0; i<n; i++)
	{
		for (int j = 1; j<n ; j++)
		{
			compare(i,j);
		}
	}
	return 0;
}




