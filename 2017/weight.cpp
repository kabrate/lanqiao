#include<cstdio>
double num[35][35];
main()
{
	FILE *fp1;
	fp1 = fopen("data_weight.csv","r");
	rewind(fp1);
	for(int i=1;i<=29;i++)
	{
		for(int j=1;j<=i;j++)
		fscanf(fp1,"%lf",&num[i][j]);
	}
	fclose(fp1);
	for(int i=1;i<=29;i++)
	{
		for(int j=1;j<=i;j++)
		{
			num[i+1][j]+=num[i][j]/2;
			num[i+1][j+1]+=num[i][j]/2;
		}
	}
	double maxn=0;
	double minn=num[30][1];
	for(int i=1;i<=30;i++)
	{
		if(maxn<num[30][i])  maxn=num[30][i];
		if(minn>num[30][i])  minn=num[30][i];
	}
	fclose(fp1);
	printf("%lf\n",maxn);
	printf("%lf\n",minn);
	printf("%lf",maxn*2086458231/minn);
	     
	return 0;
} 
