#include<string.h>  
#include<stdio.h>  
#include<iostream>  
#include<math.h>  
typedef long long LL;
//�������Ǵ�1��13��˳��ȡ�� 
using namespace std;  
int dp[14][14];  // dp[i][j]: ��ǰ����i���ƣ�������j����ʱ�Ľ�ĸ���
int main()  
{  
    int i,j,k,ans;  
    memset(dp,0,sizeof(dp));  
    ans=0;  
    dp[1][0]=dp[1][1]=dp[1][2]=dp[1][3]=dp[1][4]=1;  //��һ����ȡ���Ŷ�ֻ��һ��ȡ��
    for(i=2;i<=13;i++)  //ȡ�ڼ����� 
    {  
        for(j=0;j<=13;j++)  //���������м����� 
        {  
            for(k=0;k<=4;k++)  //�鼸���� 
            {  
                if(j-k>=0)  //���ƺ����е��ƴ��ڳ�ȡ����Ŀ 
                {  
                    dp[i][j]+=dp[i-1][j-k];  //����һ����ʱ������������ 
                }  
            }  
        }  
    }  
    ans=dp[13][13];  
    printf("%d\n",ans);  
    return 0;  
}  
