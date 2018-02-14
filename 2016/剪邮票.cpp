#include<cstdio>
using namespace std;
int dx[4] = { 0,0,1,-1 };//东西方向 
int dy[4] = { 1,-1,0,0 };//南北方向 
int a[5], ans;//保存邮票序号的数组  已经选了的邮票数 
bool flag[3][4], vis[3][4];//选出的5个邮票中是否存在这个邮票  这个邮票是否已经访问过
void dfs2(int x, int y)//走下一步
{
	vis[x][y] = 1;
	for (int i = 0; i<4; i++)//四个方向访问走下一步
	{
		int xx = x + dx[i];
		int yy = y + dy[i];
		if (xx >= 0 && xx<3 && yy >= 0 && yy<4 && !flag[xx][yy] && !vis[xx][yy])
			dfs2(xx, yy);
	}
}
bool work()
{
	memset(flag, 1, sizeof(flag));
	memset(vis, 0, sizeof(vis));
	for (int i = 0; i<5; i++)
	{
		flag[a[i] / 4][a[i] % 4] = 0;//将邮票序号转化为坐标
	}
	dfs2(a[0] / 4, a[0] % 4);
	for (int i = 0; i<5; i++)
	{
		if (!vis[a[i] / 4][a[i] % 4])//如果存在没有访问的点
			return 0;
	}
	return 1;
}
void dfs(int k, int b)//生成5张邮票
{
	if (k == 5)
	{
		ans += work();//判断邮票是否联通
		return;
	}
	for (int i = b; i <= 7 + k; i++)
	{
		a[k] = i;
		dfs(k + 1, i + 1);
	}
}
int main()
{
	dfs(0, 0);
	printf("%d", ans);
	getchar();
	return 0;
}
