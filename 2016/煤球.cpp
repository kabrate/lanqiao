#include<cstdio>
#include<algorithm>
int num;
double sum=0;
double add(int n)
{
	double S=n*(n+1)/2;
	return S;
	
}
int main()
{
	//scanf("%d",&num);
	for(int i=1;i<=100;i++)
	{
		sum=sum+add(i);
	}
	printf("%lf",sum);
	return 0;
} 
