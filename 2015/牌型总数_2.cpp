#include<iostream>  
using namespace std;  
  
int sum=0;  
  
void dfs(int n,int cartNum){  
    if(n>13){  
        return;  
    }  
    if(cartNum>=13)  
    {  
        if(cartNum==13)  
        sum++;  
        return;  
    } else{  
        dfs(n+1,cartNum);  
        dfs(n+1,cartNum+1);  
        dfs(n+1,cartNum+2);  
        dfs(n+1,cartNum+3);  
        dfs(n+1,cartNum+4);  
    }  
}   
  
int main(){  
    dfs(0,0);  
    cout<<sum<<endl;  
}  
