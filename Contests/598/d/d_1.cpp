/*
 * Author : AFGXF
 * Date : 2022-06-22 08:19:26
 * */

#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;
const int MAXN = 1000 + 10;
bool g[MAXN][MAXN];
int n, m, k;
int cnt = 0;
int group[MAXN][MAXN];
int ans[MAXN];
bool vis[MAXN][MAXN];
const int gx[] = {0, 1, 0, -1};
const int gy[] = {1, 0, -1, 0};
int bfs(int x, int y) {
  int ans = 0;
  for (int i = 0; i < 4; i++) {
    int tx = x + gx[i], ty = y + gy[i];
    if (!g[tx][ty]) {
      ans++;
    }
  }
  for (int i = 0; i < 4; i++) {
    int tx = x + gx[i], ty = y + gy[i];
    if (g[tx][ty] && !vis[tx][ty]) {
      vis[tx][ty] = 1;
      group[tx][ty] = group[x][y];
      ans += bfs(tx, ty);
    }
  }
  return ans;
}
int main() {
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      char c;
      cin >> c;
      g[i][j] = (c == '.');
    }
  }
  for (int i = 1; i <= k; i++) {
    int x, y;
    cin >> x >> y;
    if (!vis[x][y]) {
      cnt++;
      vis[x][y] = 1;
      group[x][y] = cnt;
      cout << (ans[cnt] = bfs(x, y)) << endl;
    } else {
      cout << ans[group[x][y]] << endl;
    }
  }
  return 0;
}
