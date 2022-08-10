/*
 * Author : AFGXF
 * Date : 2022-07-06 08:42:15
 * */

#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5000 + 10;
typedef pair<int, int> pii;
typedef long long ll;
deque<pii> mq[MAXN];
ll n, k, x;
ll dp[MAXN][MAXN];
ll a[MAXN];
inline void mq_push(int j, int v, int nw) {
  while (!mq[j].empty() && mq[j].front().second < nw - k) {
    mq[j].pop_front();
  }
  while (!mq[j].empty() && mq[j].back().first < v) {
    mq[j].pop_back();
  }
  mq[j].push_back(make_pair(v, nw));
}
int main() {
  cin >> n >> k >> x;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  if (x + (k - 1) * (x + 1) < n) {
    cout << -1 << endl;
    return 0;
  }
  memset(dp, -0x3f3f3f3f, sizeof dp);
  dp[0][0] = 0;
  mq_push(x, 0, 0);
  for (int i = 1; i <= n; i++) {
    for (int j = x; j >= 1; j--) {
      if (!mq[j - 1].empty())
        dp[i][j] = max(dp[i][j], mq[j - 1].front().first + a[i]);
      mq_push(j, dp[i][j], i);
    }
  }
  long long ans = 0;
  for (int i = n - k + 1; i <= n; i++) {
    ans = max(ans, *max_element(dp[i] + 1, dp[i] + 1 + x));
  }
  cout << ans << endl;
  return 0;
}
