#include <bits/stdc++.h> 
using namespace std;
int ans;
int a[10];
bool chk(int i,int j)//检查元素是否相邻 
{
	return abs(a[i]-a[j])!=1;
}
bool chk()//检查特殊位置的元素 
{
	return chk(0,1)&&chk(1,2)&&chk(3,4)&&chk(5,6)&&chk(4,5)&&chk(7,8)
	&&chk(8,9)&&chk(0,4)&&chk(1,5)&&chk(2,6)&&chk(4,8)&&chk(5,9)
	&&chk(3,7)&&chk(0,3)&&chk(1,4)&&chk(2,5)&&chk(4,7)&&chk(5,8)
	&&chk(6,9)&&chk(0,5)&&chk(1,6)&&chk(3,8)&&chk(4,9);	
}
int main()
{
	for(int i=0;i<10;i++)
	{
		a[i]=i;
	}	
		while(next_permutation(a,a+10))//全排列公式 
		{
			ans+=chk();
		}
		printf("%d",ans);
	
	return 0;
}
