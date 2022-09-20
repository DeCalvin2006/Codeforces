#include <bits/stdc++.h>
using namespace std;
int read() {
  int x = 0, f = 1;
  char c = getchar();
  while (c > '9' || c < '0') {
    if (c == '-')
      f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = (x << 1) + (x << 3) + c - '0';
    c = getchar();
  }
  return x * f;
}
const int N = 1E5 + 10;
int t = read();
int color[N];
int dp[2][N];
int main() {
  // freopen(".in", "r", stdin);
  // freopen(".out", "w", stdout);
  while (t--) {
    int n = read();
    for (int i = 1; i <= n; i++) {
      color[i] = read();
      dp[1][i] = dp[0][i] = 0;
    }
    for (int i = 1; i <= n; i++) {
      dp[i % 2][color[i]] =
          max(dp[i % 2][color[i]], dp[(i % 2) ^ 1][color[i]] + 1);
    }
    for (int i = 1; i <= n; i++) {
      cout << max(dp[1][i], dp[0][i]) << " \n"[i == n];
    }
  }
  // fclose(stdin);
  // fclose(stdout);
  return 0;
}
