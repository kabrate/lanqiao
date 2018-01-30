#include<algorithm>
#include<vector>
#include<cstdio>
using namespace std;
int main()
{
	int n,num,a,position;//输入的行数 输入的数 查找的数  
	vector<int> array;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&num);
		array.push_back(num);
	}
	scanf("%d",&a);
	vector<int>::iterator result=find(array.begin(),array.end(),a);
	if(result==array.end())
	    printf("-1");
	else 
		{
		    printf("%d",distance(array.begin(),result)+1);
		}
	return 0;
} 
