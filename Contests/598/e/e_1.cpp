/*
 * Author : AFGXF
 * Date : 2022-06-22 08:19:26
 * */

#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;
const int MAXN = 260 + 10;
int f[MAXN][MAXN][MAXN];
int t;
int main() {
  cin >> t;
  while (t--) {
    int n, m, k;
    cin >> n >> m >> k;
    memset(f, 0x3f, sizeof f);
    f[n][m][0] = f[n][m][n * m] = 0;
    for (int i = n; i >= 1; i--) {
      for (int j = m; j >= 1; j--) {
        for (int l = 0; l <= k; l++) {
          for (int a = 1; a <= i - 1; a++) {
            f[i - a][j][l + j * a] =
                min(f[i - a][j][l + j * a], f[i][j][l] + j * j);
            f[i - a][j][l] = min(f[i - a][j][l], f[i][j][l] + j * j);
            f[a][j][l + j * a] =
                min(f[a][j][l + j * (i - a)], f[i][j][l] + j * j);
            f[a][j][l] = min(f[a][j][l], f[i][j][l] + j * j);
          }
          for (int b = 1; b <= j - 1; b++) {
            f[i][j - b][l + i * b] =
                min(f[i][j - b][l + i * b], f[i][j][l] + i * i);
            f[i][j - b][l] = min(f[i][j - b][l], f[i][j][l] + i * i);
            f[i][b][l + i * b] =
                min(f[i][b][l + i * (j - b)], f[i][j][l] + i * i);
            f[i][b][l] = min(f[i][b][l], f[i][j][l] + i * i);
          }
        }
      }
    }
    int ans = 0x3f3f3f3f;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        ans = min(ans, f[i][j][k]);
      }
    }
    cout << ans << endl;
  }
  return 0;
}
