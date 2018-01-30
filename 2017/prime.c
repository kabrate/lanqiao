#include<stdio.h>
int prime[500];
int t=0;
int judge_prime(int num)//ÅĞ¶ÏËØÊı 
{
	int i,flag ;
	for (i=2;i<=num-1;i++)
	{
		if (num%i==0)
		{
		flag=0;
		break;
	    }
	}
	if (i==num) flag=1;
	return flag;
}
void prime_find() 
{
	int i;
	for (i=2;i<1000;i++)
	{
		if(judge_prime(i)==1)
		{
			prime[t]=i;
			t++;
		}
	}
}
int main()
{
	int input,flag;
    prime_find();
	int i,j;
    for(i=0;i<500;i++)
    {
    	printf("%d\n",prime[i]);
    }
	return 0;
} 
