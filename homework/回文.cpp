#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int n;
void judge()
{
	for(int i=1;i<=9;i++)
	{
		for(int j=0;j<=9;j++)
		{
			for(int k=0;k<=9;k++)
			{
				if(i*2+j*2+k==n)
				{
					printf("%ld\n",i*10001+j*1010+k*100);
					
				}

			}
		}
	}
	for(int i=1;i<=9;i++)
	{
		for(int j=0;j<=9;j++)
		{
			for(int k=0;k<=9;k++)
			{
				if(i*2+j*2+k*2==n)
				{
					printf("%ld\n",i*100001+j*10010+k*1100);
				}	

			}
		}
	}
}
int main()
{
	scanf("%d",&n);
	judge();
	return 0;
} 
