#include<algorithm>
#include<vector>
#include<cstdio>
using namespace std;
int n,num;//��������� ������� 
vector<int> array; //����Ԫ�ص����� 
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
