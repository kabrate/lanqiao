 #include<iostream>  
 #include<algorithm>  
 #include<cstdio>  
 #include<vector>  
using namespace std;  
typedef long long LL;  
const int MAXN=100000+10;  
const int INF=-1000000-10;  
LL dp[MAXN][2];  
vector<int>tree[MAXN];  
LL w[MAXN];  
  
void dfs(int p,int fa){  
    dp[p][0]=max(dp[p][0],w[p]);  
    dp[p][1]=max(dp[p][1],w[p]);  
    for(int i=0;i<tree[p].size();i++){  
        int son=tree[p][i];  
        if(son^fa){  
            dfs(son,p);  
            dp[p][0]=max(dp[p][0],dp[son][0]);  
            if(dp[son][1]>0)dp[p][1]+=dp[son][1];  
        }  
    }  
    dp[p][0]=max(dp[p][0],dp[p][1]);  
}  
  
int main(){  
    int n,a,b;  
    cin>>n;  
    for(int i=1;i<=n;i++)cin>>w[i];  
    for(int i=1;i<=n;i++){dp[i][0]=INF;dp[i][1]=INF;}  
    for(int i=1;i<n;i++){  
        cin>>a>>b;  
        tree[a].push_back(b);  
        tree[b].push_back(a);  
    }  
    dfs(1,-1);  
    cout<<dp[1][0]<<"\n";  
    return 0;  
} 
