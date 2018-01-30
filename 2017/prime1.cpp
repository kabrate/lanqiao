#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int p[100010];
int prim[100010];//素数 
int len=0;
void isp()//判断素数 
{
    memset(p,0,sizeof(p));
    p[0]=1;p[1]=1;p[2]=0;
    for(int i=0;i<10000;i++)
    {
        if(p[i])
            continue;
        for(int j=i;j*i<10000;j++)
        {
            p[i*j]=1;
        }
        prim[len++]=i;
    }

}
int main()
{
    isp();
    for(int i=0;i<len;i++)
    {
         int ss=prim[i];//ss是首项 
         for(int c=1;c<1000;c++)//c是公差 
         {
             int j;
             for(j=1;j<10;j++)
             {
                 if(p[ss+c*j])//如果下一项不是素数 
                    break;
             }
             if(j>=10)
             {
                 cout<<c<<' '<<ss<<endl;
                 return 0;
             }
         }
    }
}
