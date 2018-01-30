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

    if (i == 7 || i == 1 || j == 7 || j == 1)//走到边界 
    {
        COUNT++;
        return;
    }

    for (int step = 0; step < 4; step++)//表示四个方向 
    {
        if (visit[i + x[step]][j + y[step]] == false)//没有访问过 
        {
            int symmetry_i = abs(8 - i - x[step]);//跟i对称 
            int symmetry_j = abs(8 - j - y[step]);//跟j对称 
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
    dfs(4, 4);//从中心开始遍历 
    cout << "count: " << COUNT / 4 << endl;
    return 0;
}
