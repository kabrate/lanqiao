#include <cstdio>
#include <vector>
using namespace std;
int n,num,t,ans=0;

vector<int> array;
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&num);
		array.push_back(num);
	}
	for(int i=0;i<n-1;i++)//第几次排 
	{
		for(int j=0;j<n-1;j++)//从第几个开始排 
		{
			if(array[j]>array[j+1])
			{
				t=array[j];
				array[j]=array[j+1];
				array[j+1]=t;
				ans++;
			}
		}
	} 
	for(int i=0;i<n;i++)
	{
		printf("%d\n",array[i]);
		
	}
	printf("%d",ans);
	return 0;
}
