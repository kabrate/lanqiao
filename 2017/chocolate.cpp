#include<string>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	vector<int>H,W;//第i快是Hi和Wi块方格组成的 使用vector不用考虑数组越界问题 
	int N,K;//N块巧克力  K个小朋友
	int a,b; 
	int k[100];
	scanf("%d%d",&N,&K);
	for(int i=0;i<N;i++)
	{
		scanf("%d%d",&a,&b);
		H.push_back(a);
		W.push_back(b);
	}
	a=*max_element(H.begin(),H.end());//巧克力最大的长度 
	b=*max_element(W.begin(),W.end());//巧克力最大的宽度 
	int max=a>b?a:b;
	int mid=max,sum,min=0;
	while(max-1>min)
	{
		sum=0;
		for (int j=0;j<N;j++)
			sum+=(H[j]/mid)*(W[j]/mid);//巧妙利用了int型的特点 
		if (sum>=K)//分得正好或者太小了 
		    min=mid;
		else //分的太大了 
			max =mid;
		mid =(max+min)/2;	
	}
	printf("%d",mid);
	return 0;
}
 
