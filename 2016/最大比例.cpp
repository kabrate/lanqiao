#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std; 
int ans,n;
long int num;
vector<long long> a;
vector<double> b;
int gcd(int x,int y)
{
	return y==0?x:gcd(y,x%y);
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&num);
		a.push_back(num);
	}
	sort(a.begin(),a.end());//���� 
	a.erase(unique(a.begin(),a.end()),a.end());//�����ظ�Ԫ�� 
	for(int i=0;i<n-1;i++)
	{
		b.push_back(a[i+1]/a[i]);
	}
	sort(b.begin(),b.begin());//�Ա�ֵ��������
	double min=b[0];
	printf("%lf",b[0]);
	return 0;
}
