#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> a;
int num;
bool check()
{
	if (a[4] != 1||a[0]==0) return 0;
	num = (a[0] * 1000 + a[1] * 100 + a[2] * 10 + a[3] + a[4] * 1000 + a[5] * 100 + a[6] * 10 + a[1]) ;
	if (num != a[4] * 10000 + a[5] * 1000 + a[2] * 100 + a[1]*10+a[8]) return 0;
	else return 1;
}
int main()
{
	for (int i = 0; i <= 9; i++)
	{
		a.push_back(i);
	}
	while (next_permutation(a.begin(), a.end()))
	{
		if (check())
			printf("%d%d%d%d\n", a[4], a[5], a[2], a[1]);
	}
	return 0;
}
