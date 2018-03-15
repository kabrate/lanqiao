#include<cstdio>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
map<int, vector<int> > mp;
int ans;//�� 
int n, m, k;//���� 
int num;//�������
int x_ = 1;//����λ�ڵ�x���� 
int y_ = 0;//����λ�ڵ�y���� 
int amount;
vector<int> treasure;
void dfs(int x_, int y_, int amount)
{
	if (amount > k)
		return;
	if (x_ == n&&y_ == m - 1)//�ﵽ���� 
	{
		if (amount == k || amount == k - 1 && *max_element(treasure.begin(), treasure.end())<mp[x_][y_])
			ans++;
		return;
	}
		if (x_ <= n - 1)//����ע���Ƿ񷵻� 
		{
			if (*max_element(treasure.begin(), treasure.end())<mp[x_][y_])//����ѡ����Ҳ����ѡ���� 
			{			
				treasure.push_back(mp[x_][y_]);
				dfs(x_ + 1, y_, amount + 1);
				treasure.erase(find(treasure.begin(), treasure.end(), mp[x_][y_]));
			}
				dfs(x_ +1, y_, amount);
			
		}
		if (y_ <= m - 2)//����ע���Ƿ񷵻� 
		{
			if (*max_element(treasure.begin(), treasure.end())<mp[x_][y_])//����ѡ����Ҳ����ѡ���� 
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
