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
            Node[i].pos*=-1;//注意正负仅仅表示方向，位置是其绝对值    
        }    
    }    
    int turn=0;//考虑到第一只感冒的蚂蚁可能不会掉头的情况，设置标记turn，初始化为0    
    if(Node[0].dir==1)    
    {    
        for(int i=1; i<n; i++)    
        {    
            if((Node[i].pos>Node[0].pos)&&(Node[i].dir==-1))    
            {    
                turn=1;//第一只感冒的蚂蚁遇到迎面而来的蚂蚁，它将掉头，将turn标记为1    
                ans++;    
            }    
        }    
        for(int i=1; i<n; i++)    
        {    
            if((Node[i].pos<Node[0].pos)&&(Node[i].dir==1)&&turn)//只有第一只蚂蚁掉头了，才会与另一方向前进的蚂蚁出现碰头的情形，因此注意加上turn是否为1的判断    
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
