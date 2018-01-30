#include<cstdio>
#include<algorithm>
#include<vector>
int sum;
void judge()
{
	for(int i=1;i<=9;i++)
	{
		for(int j=0;j<=9;j++)
		{
			for(int k=0;k<=9;k++)
			{
				sum=i*100+j*10+k;
				if(sum==i*i*i+j*j*j+k*k*k)
				printf("%d\n",sum);
			}
		}
	}
}
int main()
{
	judge();
	return 0;
} 
