#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> a;
int ans = 0;
int check()
{
	int num1, num2, num3, num4, num5, num6;
	num1 = 8 + a[0] + a[1] + a[2];
	num2 = 8 + a[3] + a[6] + 3;
	num3 = a[5] + a[6] + a[7] + a[8];
	num4 = 1 + a[1] + a[4] + a[8];
	num5 = 1 + a[0] + a[3] + a[5];
	num6 = 3 + a[7] + a[4] + a[2];
	if (num1 != num2) return 0;
	if (num2 != num3) return 0;
	if (num3 != num4) return 0;
	if (num4 != num5) return 0;
	if (num5 != num6) return 0;
	return 1;

}
void dfs(int n)
{
	if (n == 9)
	{
		if (check()) ans++;
		return;
	}
	for (int i = 2; i <= 12; i++)
	{	
		if (i == 3 || i== 8 || find(a.begin(), a.end(), i) != a.end())
		{
			continue;
		}
		a[n] = i;
		dfs(n + 1);
	}
}
int main()
{
	for (int i = 0; i < 9; i++)
	{
		a.push_back(0);
	}
	dfs(0);
	printf("%d", ans);
	return 0;
}
