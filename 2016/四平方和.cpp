#include <iostream>
#include <vector>
#include <map>
using namespace std;
struct Node 
{
	int x, y;
	Node() {}
	Node(int x, int y) 
	{
		this->x = x;
		this->y = y;
	}
};
map<int, vector<Node> > mp;
int n;
void work() 
{
	for (int i = 0; i * i <= n; i++) 
	{
		for (int j = i; i * i + j * j <= n; j++) 
		{
			vector<Node>::iterator it, st = mp[n - i * i - j * j].begin(), ed = mp[n - i * i - j * j].end();// i*i+j*j+x*x+y*y==n
			for (it = st; it != ed; it++) 
			{
				if (j <= it->x) 
				{
					cout << i << " " << j << " " << it->x << " " << it->y << endl;
					return;
				}
			}
		}
	}
}
int main() 
{
	cin >> n;
	for (int i = 0; i * i <= n; i++) //先确定前两个数
	{
		for (int j = i; i * i + j * j <= n; j++) 
		{
			mp[i * i + j * j].push_back(Node(i, j));
		}
	}
	work();
	return 0;
}
