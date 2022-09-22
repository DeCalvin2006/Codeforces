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
const int N = 5E3 + 10;
int n;
int a[N];
int sum[N];
// dp[i][j] = [1,i) splited to j parts
int dp[N][5];
inline int getsum(int l, int r) { return sum[r - 1] - sum[l - 1]; }
int main() {
  n = read();
  for (int i = 1; i <= n; i++) {
    a[i] = read();
    sum[i] = sum[i - 1] + a[i];
  }
  for (int i = 1; i <= n + 1; i++) {
    dp[i][1] = getsum(1, i);
  }
  for (int i = 1; i <= n; i++) {
    dp[i][2] = max(dp[i - 1][2], dp[i][1] - a[i]);
  }
  cout << dp[n][4];
  return 0;
}
