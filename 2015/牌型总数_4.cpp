#include <iostream>
using namespace std;
typedef long long LL;
//假设牌是从1到13按顺序取的 
LL dp[14][14]; // dp[i][j]: 当前到第i号牌，总共有j张牌时的解的个数

int main() {
    dp[1][0] = dp[1][1] = dp[1][2] = dp[1][3] = dp[1][4] = 1;//第一张牌取几张都只有一种取法

    for (int i = 2; i <= 13; i++) 
	{
        for (int k = 0; k <= 13; k++) 
		{
            if (k - 4 >= 0) dp[i][k] += dp[i-1][k-4];//抽牌后手中的牌大于抽取的数目 
            if (k - 3 >= 0) dp[i][k] += dp[i-1][k-3];
            if (k - 2 >= 0) dp[i][k] += dp[i-1][k-2];
            if (k - 1 >= 0) dp[i][k] += dp[i-1][k-1];
            dp[i][k] += dp[i-1][k];
        }
    }

    cout << dp[13][13] << endl;
    return 0;
}
