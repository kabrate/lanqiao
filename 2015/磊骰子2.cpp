#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
using namespace std;
map<int, vector<int> > mp;
int n, m;//骰子数目 有冲突的面的数量 
int num1, num2;
//map<int, int> mp2;
map<int, vector<int> > mp2;
//map<long long, int (*)[6]> d;
long long d[5][6];
long long sum;
int oppsite(int i)
{
	switch (i)
	{
	case 1: return 4; break;
	case 2: return 5; break;
	case 3: return 6; break;
	case 4: return 1; break;
	case 5: return 2; break;
	case 6: return 3; break;
	}
}
int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i<m; i++)//相互冲突的面 
	{
		scanf("%d %d", &num1, &num2);
		mp2[num1].push_back(num2);
		mp2[num2].push_back(num1);
	}
	for(int i=0;i<6;i++)
	{
		d[1][i]=1;
	}
	
	//d[1][1] = d[1][2] = d[1][3] = d[1][4] = d[1][5] = d[1][6] = 1;
	for (int i = 2; i <= n; i++)//第几个骰子 
	{
		for (int j = 1; j <= 6; j++)//骰子向上的面 
		{
			for (int t = 1; t <= 6; t++)//下面的骰子向上的面 
			{
				if (find(mp2[oppsite(j)].begin(),mp2[oppsite(j)].end(),t)==mp2[oppsite(j)].end())//不冲突 
				{
					d[i][j-1] += d[(i - 1)][t-1];//上面骰子的情况等于下面不跟它冲突的骰子情况数量相加
					d[i-1][t-1]=0;
				}
			}
		}
	}
	sum = d[n][0] + d[n][1] + d[n][2] + d[n][3] + d[n][4] + d[n][5];
	sum = sum*pow(4, n);
	sum = sum % 1000000007;
	printf("%ld", sum);
	return 0;
}
