#include <iostream>
using namespace std;
typedef long long LL;
//�������Ǵ�1��13��˳��ȡ�� 
LL dp[14][14]; // dp[i][j]: ��ǰ����i���ƣ��ܹ���j����ʱ�Ľ�ĸ���

int main() {
    dp[1][0] = dp[1][1] = dp[1][2] = dp[1][3] = dp[1][4] = 1;//��һ����ȡ���Ŷ�ֻ��һ��ȡ��

    for (int i = 2; i <= 13; i++) 
	{
        for (int k = 0; k <= 13; k++) 
		{
            if (k - 4 >= 0) dp[i][k] += dp[i-1][k-4];//���ƺ����е��ƴ��ڳ�ȡ����Ŀ 
            if (k - 3 >= 0) dp[i][k] += dp[i-1][k-3];
            if (k - 2 >= 0) dp[i][k] += dp[i-1][k-2];
            if (k - 1 >= 0) dp[i][k] += dp[i-1][k-1];
            dp[i][k] += dp[i-1][k];
        }
    }

    cout << dp[13][13] << endl;
    return 0;
}
