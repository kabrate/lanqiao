#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
using namespace std;
map<int, vector<int> > mp;
int n, m;//������Ŀ �г�ͻ��������� 
int num1, num2;
map<int, int> mp2;
//map<int, vector<int >> d;
long long d[5][6] ;
long long sum;
int oppsite(int i)
{
	switch (i)
	{
	case 1: return 4; break;
	case 2: return 3; break;
	case 3: return 6; break;
	case 4: return 1; break;
	case 5: return 2; break;
	case 6: return 3; break;
	}
}
int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i<m; i++)//�໥��ͻ���� 
	{
		scanf("%d %d", &num1, &num2);
		mp2[num1] = num2;
		mp2[num2] = num1;
	}
	d[1][1] = d[1][2] = d[1][3] = d[1][4] = d[1][5] = d[1][6] = 1;
	for (int i = 2; i <= n; i++)//�ڼ������� 
	{
		for (int j = 1; j <= 6; j++)//�������ϵ��� 
		{
			for (int t = 1; t <= 6; t++)//������������ϵ��� 
			{
				if (mp2[oppsite(j)] != t)//����ͻ 
				{
					d[i%3][j] += d[(i - 1)%3][t];
				}
			}
		}
	}
	sum = d[n % 3][1] + d[n % 3][2] + d[n % 3][3] + d[n % 3][4] + d[n % 3][5] + d[n % 3][6];
	sum = sum*pow(4,n);
	sum = sum % 1000000007;
	printf("%ld",sum);
	return 0;
}
