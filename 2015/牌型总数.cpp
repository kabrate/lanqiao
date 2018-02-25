#include<string.h>  
#include<stdio.h>  
#include<iostream>  
#include<math.h>  
typedef long long LL;
//假设牌是从1到13按顺序取的 
using namespace std;  
int dp[14][14];  // dp[i][j]: 当前到第i号牌，手中有j张牌时的解的个数
int main()  
{  
    int i,j,k,ans;  
    memset(dp,0,sizeof(dp));  
    ans=0;  
    dp[1][0]=dp[1][1]=dp[1][2]=dp[1][3]=dp[1][4]=1;  //第一张牌取几张都只有一种取法
    for(i=2;i<=13;i++)  //取第几号牌 
    {  
        for(j=0;j<=13;j++)  //现在手中有几张牌 
        {  
            for(k=0;k<=4;k++)  //抽几张牌 
            {  
                if(j-k>=0)  //抽牌后手中的牌大于抽取的数目 
                {  
                    dp[i][j]+=dp[i-1][j-k];  //抽上一次牌时候的情况加起来 
                }  
            }  
        }  
    }  
    ans=dp[13][13];  
    printf("%d\n",ans);  
    return 0;  
}  
