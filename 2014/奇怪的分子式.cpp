#include<cstdio>
int a[5];
int ans = 0;
int gcd1(int x, int y)//���Լ��
{
	return y == 0 ? x : gcd1(y, x%y);
}
int check()
{
	int b,c,d,e;
	b = a[0] * 10 + a[2];//������� 
	c = a[1] * 10 + a[3];//��ĸ���
	d=a[0]*a[2];//�������
	e=a[1]*a[3];//��ĸ��� 
	if (a[0] == a[1] && a[2] == a[3]) return 0;
	if(b/gcd1(b,c)!=d/gcd1(d,e)||c/gcd1(b,c)!=e/gcd1(d,e)) return 0;//���ӷ�ĸԼ�ֺ�Ӧ��һ�� 

	return 1;
}
int main()
{
	for (int i = 1; i <= 9; i++)//���� 
	{
		a[0] = i;
		for (int j = 1; j <= 9; j++)//��ĸ 
		{
			a[1] = j;
			for (int k = 1; k <= 9; k++)//���� 
			{
				a[2] = k;
				for (int l = 1; l <= 9; l++)//��ĸ 
				{
					a[3] = l;
					if (check()) ans++;
				}
			}
		}
	}
	printf("%d", ans);
	return 0;
}
