#include<cstdio>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
int n;
long long num;
vector<double> bonus;//奖金
vector<double> b;//比值
vector<long long> up;//分子
vector<long long> down;//分母
vector<int> up_gcd;//分子最大系数
vector<int> down_gcd;//分母最大系数
int gcd1(int x, int y)//最大公约数
{
	return y == 0 ? x : gcd1(y, x%y);
}
double gcd2(double m,double n)//求系数的最大公约数
{
	if (m==n) return m;
	else if(m>n) return gcd2(n, m/ n);
	else return gcd2(m, n/m);
}
int main()
{
	scanf("%d", &n);
	for (int i = 0; i<n; i++)
	{
		scanf("%lld", &num);
		bonus.push_back(num);
	}
	sort(bonus.begin(), bonus.end());//排序 
	bonus.erase(unique(bonus.begin(), bonus.end()), bonus.end());//消除重复元素 
	for (int i = 0; i<bonus.size()-1; i++)//保存比值
	{
			
			b.push_back(double(bonus[i+1]/ bonus[i]));
			up.push_back(bonus[i+1]/gcd1(bonus[i],bonus[i+1]));//分子
			down.push_back(bonus[i] / gcd1(bonus[i], bonus[i+1]));//分母
		
	}
	sort(b.begin(), b.end());//对比值进行排序
	b.erase(unique(b.begin(), b.end()), b.end());
	for (int i = 0; i<up.size(); i++)//分别求分子分母比值系数的最大的公约数
	{
		for (int j = i + 1; j < up.size(); j++)
		{				
				up_gcd.push_back(gcd2(up[i],up[j]));//分子
				down_gcd.push_back(gcd2(down[i], down[j]));//分母	
		}
	}
	sort(up_gcd.begin(), up_gcd.end());
	sort(down_gcd.begin(), down_gcd.end());
	printf("%d/%d",up_gcd[0],down_gcd[0]);
	getchar();
	return 0;
}
