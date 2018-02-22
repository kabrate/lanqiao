#include<string.h>  
#include<stdio.h>  
#include<iostream>  
#include<math.h>  
using namespace std;  
int dp[14][14];  
int main()  
{  
    int i,j,k,ans;  
    memset(dp,0,sizeof(dp));  
    ans=0;  
    dp[1][0]=dp[1][1]=dp[1][2]=dp[1][3]=dp[1][4]=1;  
    for(i=2;i<=13;i++)  
    {  
        for(j=0;j<=13;j++)  
        {  
            for(k=0;k<=4;k++)  
            {  
                if(j-k>=0)  
                {  
                    dp[i][j]+=dp[i-1][j-k];  
                }  
            }  
        }  
    }  
    ans=dp[13][13];  
    printf("%d\n",ans);  
    return 0;  
}  
