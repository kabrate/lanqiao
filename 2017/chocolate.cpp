#include<string>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	vector<int>H,W;//��i����Hi��Wi�鷽����ɵ� ʹ��vector���ÿ�������Խ������ 
	int N,K;//N���ɿ���  K��С����
	int a,b; 
	int k[100];
	scanf("%d%d",&N,&K);
	for(int i=0;i<N;i++)
	{
		scanf("%d%d",&a,&b);
		H.push_back(a);
		W.push_back(b);
	}
	a=*max_element(H.begin(),H.end());//�ɿ������ĳ��� 
	b=*max_element(W.begin(),W.end());//�ɿ������Ŀ�� 
	int max=a>b?a:b;
	int mid=max,sum,min=0;
	while(max-1>min)
	{
		sum=0;
		for (int j=0;j<N;j++)
			sum+=(H[j]/mid)*(W[j]/mid);//����������int�͵��ص� 
		if (sum>=K)//�ֵ����û���̫С�� 
		    min=mid;
		else //�ֵ�̫���� 
			max =mid;
		mid =(max+min)/2;	
	}
	printf("%d",mid);
	return 0;
}
 
