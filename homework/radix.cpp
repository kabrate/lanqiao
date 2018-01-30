#include<cstdio>
using namespace std;
long a;  
int p,c,m=0,s[100];  
void trans()
{
	while (a!=0)//数制转换，结果存入数组s[m]  
    {  
        c=a%16;  
        a=a/16;  
        m++;s[m]=c;   //将余数按顺序存入数组s[m]中  
    } 
	for(int k=m;k>=1;k--)//输出转换后的序列  
    {  
        if(s[k]>=10) //若为十六进制等则输出相对应的字母  
            //cout<<(char)(s[k]+55);
			printf("%c",(char)(s[k]+55));  
        else         //否则直接输出数字  
            //cout<<s[k];  
            printf("%d",s[k]);
    }  
}
int main()
{
    scanf("%d",&a);
    //cin>>a;
    if(a==0)
    printf("0");
    else trans(); 
    return 0;  
} 
