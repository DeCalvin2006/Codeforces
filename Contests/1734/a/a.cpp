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
const int N = 301;
int t, n;
int a[N];
int main() {
  t = read();
  while (t--) {
    n = read();
    for (int i = 1; i <= n; i++) {
      a[i] = read();
    }
    sort(a + 1, a + 1 + n);
    int ans = 1E9 + 7;
    for (int i = 1; i <= n - 2; i++) {
      int c1 = a[i], c2 = a[i + 1], c3 = a[i + 2];
      int tans = min({c2 - c1 + c3 - c1, c2 - c1 + c3 - c2, c3 - c1 + c3 - c2});
      ans = min(ans, tans);
    }
    cout << ans << endl;
  }
  // TODO: code here
  return 0;
}
