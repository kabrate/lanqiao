#include<cstdio>
using namespace std;
int dx[4] = { 0,0,1,-1 };//�������� 
int dy[4] = { 1,-1,0,0 };//�ϱ����� 
int a[5], ans;//������Ʊ��ŵ�����  �Ѿ�ѡ�˵���Ʊ�� 
bool flag[3][4], vis[3][4];//ѡ����5����Ʊ���Ƿ���������Ʊ  �����Ʊ�Ƿ��Ѿ����ʹ�
void dfs2(int x, int y)//����һ��
{
	vis[x][y] = 1;
	for (int i = 0; i<4; i++)//�ĸ������������һ��
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
		flag[a[i] / 4][a[i] % 4] = 0;//����Ʊ���ת��Ϊ����
	}
	dfs2(a[0] / 4, a[0] % 4);
	for (int i = 0; i<5; i++)
	{
		if (!vis[a[i] / 4][a[i] % 4])//�������û�з��ʵĵ�
			return 0;
	}
	return 1;
}
void dfs(int k, int b)//����5����Ʊ
{
	if (k == 5)
	{
		ans += work();//�ж���Ʊ�Ƿ���ͨ
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
