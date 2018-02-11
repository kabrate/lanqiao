#include<cstdio>
#include<algorithm>
int main()
{
	for(int i=1;i<100;i++)
	{
		for(int j=2;j<100;j++)
		{
			if((j-i+1)*(j+i)/2==236)
			printf("%d",i);
		}
	}
	
	return 0;
} 
