#include<cstdio>
#include<string> 
#include<ctime>
#include <ctime>  
int n;
long int day[12],start;
long int transform(int year,int month,int d)
{
	struct tm t;
	time_t date;
	t.tm_year = year-1900;
	t.tm_mon = month;
	t.tm_mday = d;
	t.tm_hour = 0;
	t.tm_min = 0;
	t.tm_sec = 0;
	date = mktime(&t);
	date = date / 86400;
	return date;
}
int main()
{
	long int day1, day2;
	scanf("%d",&n);
	for (int i = 0; i < 12; i++)
	{
		day[i] = transform(n, i, 13);//±£´æ
	}	
	start = transform(n,0,1);
	for (int i = 0; i < 12; i++)
	{
		if((day[i]-start-1)%7==0)
			printf("%d-%d-13\n",n,i+1);
	}
	return 0;
}
