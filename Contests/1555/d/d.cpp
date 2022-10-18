#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll read() {
  ll x = 0, f = 1;
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
const int N = 2e5 + 10;
int n, m;
char buf[N];
int a[N];
const char *cstr[] = {
    "abc", "bca", "cab",

    "acb", "cba", "bac",
};
int pr[6][N];
int main() {
  n = read(), m = read();
  cin >> (buf + 1);
  for (int i = 0; i < 6; i++) {
    for (int j = 1; j <= n; j++) {
      // cout << cstr[i][j % 3];
      if (buf[j] != cstr[i][j % 3]) {
        pr[i][j] = pr[i][j - 1] + 1;
      } else
        pr[i][j] = pr[i][j - 1];
    }
  }
  for (int i = 1; i <= m; i++) {
    int l = read(), r = read();
    int ans = INT_MAX;
    for (int i = 0; i < 6; i++) {
      ans = min(ans, pr[i][r] - pr[i][l - 1]);
    }
    cout << ans << endl;
  }
  return 0;
}
