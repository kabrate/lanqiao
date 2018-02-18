#include<ctime>
#include<cstdio>
int i,j,k;
long int transform(int year,int month,int d)
{
	tm t;
	time_t date;
	t.tm_year = year -1900;
	t.tm_mon=month; 
	t.tm_mday=d;
	t.tm_hour=8;
	t.tm_min=0;
	t.tm_sec=0;
	date=mktime(&t);//将时间转化为距离1970年1月1日的秒数 
	return date;

}
int main()
{
	long int day;
	time_t time;
	scanf("%d-%d-%d",&i,&j,&k);
	day=transform(i,j-1,k);
	day+=1000*86400;
	time=day;
	printf("%s",ctime(&time));
	return 0;
}
 
