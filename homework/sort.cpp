#include<algorithm>
#include<vector>
#include<cstdio>
using namespace std;
int n,num;//输入的行数 输入的数 
vector<int> array; //保存元素的数组 
void sort()
{
	sort(array.begin(),array.end());
    //for (vector<int>::iterator it = a.begin(); it != a.end(); it++){
        //cout << *it << endl;
    //}
    for(int i=0;i<n;i++)
    {
    	printf("%d ",array[i]);
    }
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&num);
		array.push_back(num);
	}
	sort();
	return 0;
} 
