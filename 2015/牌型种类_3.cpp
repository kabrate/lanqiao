#include <iostream>  
using namespace std;  
int ans=0,sum=0;  //sum现在的牌数 cur牌的点数 
void dfs(int cur)  
{  
    if(sum>13)  
        return ;  
    if(cur==13)  
    {  
        if(sum==13)  
        {  
            ans++;  
            return;  
        }  
    }  
    else  
    {  
        for(int i=0; i<5; i++)//13张牌，每种有4张 
        {  
            sum+=i;  
            dfs(cur+1);  
            sum-=i;  
        }  
    }  
}  
int main()  
{  
    dfs(0);  
    cout<<ans;  
    return 0;  
}  
