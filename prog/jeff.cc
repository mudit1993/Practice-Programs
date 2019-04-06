#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
using namespace std;

int grid[501][501];
bool vis[501][501];
int m, n;
long long ans = -1;
int cx[] = {-1, 0, 1};
int cy[] = {0, 1, 0};

void dfs(long long sum, int x, int y) {
    if (y == n - 1 && sum > ans) {
        ans = sum;
    }

    for (int i = 0; i < 3; ++i) {
        bool flag = false;
        int nx = x + cx[i];
        if (nx == -1) {
            nx = m - 1;
            flag = true;
        }
        if (nx == m) {
            nx = 0;
            flag = true;
        }
        int ny = y + cy[i];
        if (ny == n) continue;
        if (vis[nx][ny] || grid[nx][ny] == -1) continue;
        vis[nx][ny] = true;
        if (flag)
            dfs(0, nx, ny);
        else
            dfs(sum + grid[nx][ny], nx, ny);
        vis[nx][ny] = false;
    }
}

int main() {
    scanf("%d%d", &m, &n);
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            scanf("%d", &grid[i][j]);
    memset(vis, false, sizeof(vis));

    for (int i = 0; i < m; ++i) {
        if (grid[i][0] == -1)
            continue;
        vis[i][0] = true;
        dfs(grid[i][0], i, 0);
        vis[i][0] = false;
    }
    printf("%lld\n", ans);
    return 0;
}
