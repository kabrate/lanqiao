#include<stdio.h>    
#include<string.h>    
struct Node    
{    
    int pos,dir;    
} Node[55];    
int main()    
{    
    int n,ans=1;    
    scanf("%d",&n);    
    memset(Node,0,sizeof(Node));    
    for(int i=0; i<n; i++)    
    {    
        scanf("%d",&Node[i].pos);    
        if(Node[i].pos>0)    
        {    
            Node[i].dir=1;    
        }    
        else    
        {    
            Node[i].dir=-1;    
            Node[i].pos*=-1;//ע������������ʾ����λ���������ֵ    
        }    
    }    
    int turn=0;//���ǵ���һֻ��ð�����Ͽ��ܲ����ͷ����������ñ��turn����ʼ��Ϊ0    
    if(Node[0].dir==1)    
    {    
        for(int i=1; i<n; i++)    
        {    
            if((Node[i].pos>Node[0].pos)&&(Node[i].dir==-1))    
            {    
                turn=1;//��һֻ��ð����������ӭ����������ϣ�������ͷ����turn���Ϊ1    
                ans++;    
            }    
        }    
        for(int i=1; i<n; i++)    
        {    
            if((Node[i].pos<Node[0].pos)&&(Node[i].dir==1)&&turn)//ֻ�е�һֻ���ϵ�ͷ�ˣ��Ż�����һ����ǰ�������ϳ�����ͷ�����Σ����ע�����turn�Ƿ�Ϊ1���ж�    
                ans++;    
        }    
    }    
    else    
    {    
        for(int i=1; i<n; i++)    
        {    
            if((Node[i].pos<Node[0].pos)&&(Node[i].dir==1))    
            {    
                turn=1;    
                ans++;    
            }    
        }    
        for(int i=1; i<n; i++)    
        {    
            if((Node[i].pos>Node[0].pos)&&(Node[i].dir==-1)&&turn)    
                ans++;    
        }    
    }    
    printf("%d\n",ans);    
    return 0;    
}    
