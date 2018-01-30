#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int N,K;//N数列长度  K 子序列区间是k的倍数 
int a;//数组中的元素 
int sum=0,num=0;
int main()
{
	scanf("%d%d",&N,&K);
	vector<int>A;
	for(int i=0;i<N;i++)
    {
    	scanf("%d",&a);
    	A.push_back(a);
    }
    for(int j=1;j<=N;j++)//子序列中元素的个数 
    {
    	for(int i=0;i<N-j+1;i++)//含有几个这样的子序列 
    	{
    		if(sum%K==0&&sum!=0)
			{
				num++;
			}
    		sum=0;
    		for(int t=0;t<=j-1;t++)//子序列的和 
    		{
    			sum+=A[i+t];				
    		}
    	}
	}
	printf("%d",num);
	return 0;
}
