#include <stdio.h>
#define N 6
#define M 5
#define BUF 1024
int t=1;

void f(int a[], int k, int m, char b[]) 
{
    int i, j;

    if(k == N) //人数够了 
	{
        b[M] = 0;
        if(m == 0) printf("%s  %d\n", b,t++);
        return;
    }

    for(i = 0; i <= a[k]; i++) 
	{
        for(j = 0; j < i; j++) 
		b[M - m + j] = k + 'A';
        f(a,k+1,m-i,b); //填空位置
    }
}
int main() {
    int a[N] = {4, 2, 2, 1, 1, 3};//A B C D E F
    char b[BUF];//保存结果的数组 
    f(a, 0, M, b);//参数分别为每个国家的情况  要选第几个国家的人  还需安排的人数  保存结果 
    return 0;
}
