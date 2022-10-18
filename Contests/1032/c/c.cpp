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
int a[N];
int n;
int ans[N], cnt = 0;
bool dp[N][6];
bool dfs(int x, int f) {
  if (dp[x][f] == 0)
    return 0;
  if (x > n) {
    return 1;
  }
  if (a[x] > a[x - 1]) {
    for (int i = f + 1; i <= 5; i++) {
      if (dfs(x + 1, i)) {
        ans[x] = i;
        return 1;
      }
    }
  } else if (a[x] < a[x - 1]) {
    for (int i = 1; i < f; i++) {
      if (dfs(x + 1, i)) {
        ans[x] = i;
        return 1;
      }
    }
  } else {
    for (int i = 1; i <= 5; i++) {
      if (i == f)
        continue;
      if (dfs(x + 1, i)) {
        ans[x] = i;
        return 1;
      }
    }
  }
  return dp[x][f] = 0;
}
int main() {
  n = read();
  for (int i = 1; i <= n; i++) {
    a[i] = read();
  }
  memset(dp, 1, sizeof dp);
  bool ok = dfs(1, 0);
  if (ok) {
    for (int i = 1; i <= n; i++) {
      cout << ans[i] << ' ';
    }
    cout << endl;
  } else
    cout << "-1" << endl;
  return 0;
}
