#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath> 
#include<cstdio>
using namespace std;
int ans;
vector<int> a(9);
int main() {
	for (int i = 0; i <= 8; i++) 
	{
		a[i] = i + 1;
		//a.push_back(i+1);
	}
	do {
		double A = a[0];
		double B = a[1];
		double C = a[2];
		double DEF = a[3] * 100 + a[4] * 10 + a[5];
		double GHI = a[6] * 100 + a[7] * 10 + a[8];
		if (fabs(A + B / C + DEF / GHI - 10) < 1e-12) ans++;
	} while (next_permutation(a.begin(), a.end()));
	cout << ans << endl;
	getchar();
	return 0;
}
