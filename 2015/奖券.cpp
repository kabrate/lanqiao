#include<cstdio>
#include<map>
#include<vector>
#include<string> 
using namespace std;
string st;
int ans = 0;
map<int, string> mp;
int main()
{
	for (int i = 10000; i <= 99999; i++)
	{
		st = to_string(i);
		mp[i]=st;
	}
	for (int i = 10000; i<=99999; i++)
	{
		if (mp[i].find("4", 0)== string::npos )
			ans++;;		
	}
	printf("%d",ans);
}
