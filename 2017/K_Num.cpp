#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int N,K;//N���г���  K ������������k�ı��� 
int a;//�����е�Ԫ�� 
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
    for(int j=1;j<=N;j++)//��������Ԫ�صĸ��� 
    {
    	for(int i=0;i<N-j+1;i++)//���м��������������� 
    	{
    		if(sum%K==0&&sum!=0)
			{
				num++;
			}
    		sum=0;
    		for(int t=0;t<=j-1;t++)//�����еĺ� 
    		{
    			sum+=A[i+t];				
    		}
    	}
	}
	printf("%d",num);
	return 0;
}
