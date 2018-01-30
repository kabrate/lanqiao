#include<stdio.h>
#include<string.h> 
#include<stdlib.h>
char ch1,ch2,ch3,ch4,ch5,ch6;
int num1,num2,num3;
int judge(int year,int month,int day)
{
	 if (year<1960 ||year >2059)return 0;
	 if(month>12) return 0;
	 if(day>31) return 0;
	 if(month==4||month==6||month==9||month==11)
	 {
	 	 if(day==31) return 0;
	 }
	 if(month=2&&year%4!=0)//非闰年二月份 
	 {
	 	if(day>28)
	 	return 0;
	 }
	 return 1;
}
//要用atoi注意保证字符数组有足够的容量 
int main()
{
	scanf("%c%c/%c%c/%c%c",&ch1,&ch2,&ch3,&ch4,&ch5,&ch6);
	num1=(ch1-'0')*10+ch2-'0';
	num2=(ch3-'0')*10+ch4-'0';
    num3=(ch5-'0')*10+ch6-'0';
    if (judge(num1+1900,num2,num3))    //年月日 
	printf("%d-%d-%d\n",num1+1900,num2,num3);
	if (judge(num1+2000,num2,num3))    
	printf("%d-%d-%d\n",num1+2000,num2,num3);
	if (judge(num3+1900,num1,num2))    //月日年 
	printf("%d-%d-%d\n",num3+1900,num1,num2);
	if (judge(num3+2000,num1,num2))    
	printf("%d-%d-%d\n",num3+2000,num1,num2);
	if (judge(num3+1900,num2,num1))    //日月年 
	printf("%d-%d-%d\n",num3+1900,num2,num1);
	if (judge(num3+2000,num2,num1))    
	printf("%d-%d-%d\n",num3+2000,num2,num1);
	return 0;
}
