#include <algorithm>
#include <bits/stdc++.h>
#include <locale>
using namespace std;
#define int long long
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
const int N = 2E5 + 10;
int n;
int t;
struct number {
  int val, p;
} a[N];
signed main() {
  t = read();
  while (t--) {
    n = read();
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
      a[0].val = read();
      if (a[0].val < i) {
        a[++cnt].val = a[0].val;
        a[cnt].p = i;
      }
    }
    n = cnt;
    if (n == 0) {
      cout << 0 << endl;
      continue;
    }
    int ans = 0;
    stable_sort(a + 1, a + 1 + n,
                [](number a, number b) { return a.val < b.val; });
    for (int i = 1; i <= n; i++) {
      // clog << a[i].p << ":" << a[i].val << endl;
      int an = upper_bound(a + 1, a + 1 + n, a[i].p,
                           [](int a, number b) { return a < b.val; }) -
               a;
      ans += n - an + 1;
      // clog << an << endl;
    }
    cout << ans << endl;
  }
  return 0;
}
