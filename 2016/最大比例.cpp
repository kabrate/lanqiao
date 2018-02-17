#include<cstdio>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
int n;
long long num;
vector<double> bonus;//����
vector<double> b;//��ֵ
vector<long long> up;//����
vector<long long> down;//��ĸ
vector<int> up_gcd;//�������ϵ��
vector<int> down_gcd;//��ĸ���ϵ��
int gcd1(int x, int y)//���Լ��
{
	return y == 0 ? x : gcd1(y, x%y);
}
double gcd2(double m,double n)//��ϵ�������Լ��
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
	sort(bonus.begin(), bonus.end());//���� 
	bonus.erase(unique(bonus.begin(), bonus.end()), bonus.end());//�����ظ�Ԫ�� 
	for (int i = 0; i<bonus.size()-1; i++)//�����ֵ
	{
			
			b.push_back(double(bonus[i+1]/ bonus[i]));
			up.push_back(bonus[i+1]/gcd1(bonus[i],bonus[i+1]));//����
			down.push_back(bonus[i] / gcd1(bonus[i], bonus[i+1]));//��ĸ
		
	}
	sort(b.begin(), b.end());//�Ա�ֵ��������
	b.erase(unique(b.begin(), b.end()), b.end());
	for (int i = 0; i<up.size(); i++)//�ֱ�����ӷ�ĸ��ֵϵ�������Ĺ�Լ��
	{
		for (int j = i + 1; j < up.size(); j++)
		{				
				up_gcd.push_back(gcd2(up[i],up[j]));//����
				down_gcd.push_back(gcd2(down[i], down[j]));//��ĸ	
		}
	}
	sort(up_gcd.begin(), up_gcd.end());
	sort(down_gcd.begin(), down_gcd.end());
	printf("%d/%d",up_gcd[0],down_gcd[0]);
	getchar();
	return 0;
}
