#include <iostream>
#include <cmath>

using namespace std;
int n[8][8] = {0};
bool visit[8][8];
int COUNT = 0;
int x[4] = {1, 0, -1, 0};
int y[4] = {0, 1, 0, -1};

void dfs(int i, int j)
{

    if (i == 7 || i == 1 || j == 7 || j == 1)//�ߵ��߽� 
    {
        COUNT++;
        return;
    }

    for (int step = 0; step < 4; step++)//��ʾ�ĸ����� 
    {
        if (visit[i + x[step]][j + y[step]] == false)//û�з��ʹ� 
        {
            int symmetry_i = abs(8 - i - x[step]);//��i�Գ� 
            int symmetry_j = abs(8 - j - y[step]);//��j�Գ� 
            visit[i + x[step]][j + y[step]] = true;
            visit[symmetry_i][symmetry_j] = true;
            dfs(i + x[step], j + y[step]);
            visit[i + x[step]][j + y[step]] = false;
            visit[symmetry_i][symmetry_j] = false;
        }
    }
}

int main()
{
    visit[4][4] = true;
    dfs(4, 4);//�����Ŀ�ʼ���� 
    cout << "count: " << COUNT / 4 << endl;
    return 0;
}
