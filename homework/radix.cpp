#include<cstdio>
using namespace std;
long a;  
int p,c,m=0,s[100];  
void trans()
{
	while (a!=0)//����ת���������������s[m]  
    {  
        c=a%16;  
        a=a/16;  
        m++;s[m]=c;   //��������˳���������s[m]��  
    } 
	for(int k=m;k>=1;k--)//���ת���������  
    {  
        if(s[k]>=10) //��Ϊʮ�����Ƶ���������Ӧ����ĸ  
            //cout<<(char)(s[k]+55);
			printf("%c",(char)(s[k]+55));  
        else         //����ֱ���������  
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
