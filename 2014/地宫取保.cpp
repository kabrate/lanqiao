#include<cstdio>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
map<int, vector<int> > mp;
int ans;//答案 
int n, m, k;//参数 
int num;//输入的数
int x_ = 1;//现在位于的x坐标 
int y_ = 0;//现在位于的y坐标 
int amount;
vector<int> treasure;
void dfs(int x_, int y_, int amount)
{
	if (amount > k)
		return;
	if (x_ == n&&y_ == m - 1)//达到出口 
	{
		if (amount == k || amount == k - 1 && *max_element(treasure.begin(), treasure.end())<mp[x_][y_])
			ans++;
		return;
	}
		if (x_ <= n - 1)//不用注意是否返回 
		{
			if (*max_element(treasure.begin(), treasure.end())<mp[x_][y_])//可以选择拿也可以选择不拿 
			{			
				treasure.push_back(mp[x_][y_]);
				dfs(x_ + 1, y_, amount + 1);
				treasure.erase(find(treasure.begin(), treasure.end(), mp[x_][y_]));
			}
				dfs(x_ +1, y_, amount);
			
		}
		if (y_ <= m - 2)//不用注意是否返回 
		{
			if (*max_element(treasure.begin(), treasure.end())<mp[x_][y_])//可以选择拿也可以选择不拿 
			{
				treasure.push_back(mp[x_][y_]);
				dfs(x_ , y_+1, amount + 1);
				treasure.erase(find(treasure.begin(), treasure.end(), mp[x_][y_]));
			}
				dfs(x_ , y_+1, amount);
		}
	
}
int main()
{
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j<m; j++)
		{
			scanf("%d", &num);
			mp[i].push_back(num);
		}
	}
	treasure.push_back(-1);
	dfs(1, 0, 0);
	printf("%d", ans% 1000000007);
	return 0;
}
