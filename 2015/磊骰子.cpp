#include <iostream>
using namespace std;

// ...��ͻ��¼: Compact[i][j]=false�������Ϊi���������Ϊj������ڳ�ͻ 
bool Compact[7][7];					

// ...Parner[i]=j���� ����Ϊi���� �Ķ��������Ϊj	
const int Parner[7]={ 0,4,5,6,1,2,3 }; 
const long long MOD = 1000000007;

int main(int argc, char** argv) 
{
	long long  N; // ���Ӹ߶�
	int M; // ��ͻ����
	int s1,s2; 
	cin >> N >> M;
	for( int i = 0; i < 7; ++i)
		for( int j = 0; j < 7;++j)
			Compact[i][j]=true;
			
	for( int i = 0; i < M; ++i ) {
		cin >> s1 >> s2;
		// ...����Ϊs1���������Ϊs2������ڳ�ͻ 
		Compact[s1][s2] = Compact[s2][s1] = false;	
	}
	long long dp[2][7]; // ��������
	long long C = 4;
	int e = 0;			// ������־
	for( int i = 1; i < 7; ++i ) 
		dp[e][i] = 1;
	
	// dp[i][j]����߶�Ϊi��,�������Ϊj�ĵ����ӷ�����
	// ���������ÿ�����ӿ�������ת������, �Ѹ��������������ȥ�Ϳ����� 
	int j,k;
	for( long long i = 2; i <= N; ++i ){
		e = 1-e;	// ...�������� 
		C = (C*4)%MOD;
		for( j = 1; j < 7; ++j ){
			dp[e][j] = 0;
			for( k = 1; k < 7; ++k)
				if( Compact[ Parner[j] ][k] )
					dp[e][j] += dp[1-e][k];
			//dp[e][j]%=MOD;
		}
		
	}
	int sum=0;
	for( int i = 1; i < 7; ++i)
		sum = (sum+dp[e][i]);//%MOD;
	sum = (sum*C)%MOD;
	cout << sum;
	return 0;
}
