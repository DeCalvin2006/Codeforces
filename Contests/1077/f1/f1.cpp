/*
 * Author : AFGXF
 * Date : 2022-07-05 10:22:58
 * */

#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200 + 10;
int n, k, x;
long long a[MAXN];
long long dp[MAXN][MAXN];
void init() {
  cin >> n >> k >> x;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
}
int main() {
  init();
  if (x + (x + 1) * (k - 1) < n) {
    cout << -1 << endl;
    return 0;
  }
  memset(dp, -0x3f3f3f3f, sizeof dp);
  dp[0][0] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = x; j >= 1; j--) {
      for (int p = 1; p <= k; p++) {
        if (i - p < 0)
          break;
        dp[i][j] = max(dp[i][j], dp[i - p][j - 1] + a[i]);
      }
    }
  }
  long long ans = 0;
  for (int i = n - k + 1; i <= n; i++) {
    ans = max(ans, *max_element(dp[i] + 1, dp[i] + 1 + x));
  }
  cout << ans << endl;
  return 0;
}
