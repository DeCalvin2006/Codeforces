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
const int N = 1E6 + 10;
int cnt[N];
bool tgt[N], deleted[N];
int t, n;
char buf[N];
int main() {
  t = read();
  while (t--) {
    n = read();
    cin >> (buf + 1);
    memset(deleted, 0, sizeof deleted);
    for (int i = 1; i <= n; i++) {
      tgt[i] = buf[i] == '0';
      // delete=1,reserve=0;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      int j = 1;
      while (i * j <= n && (tgt[i * j] && deleted[i * j])) // Pass the prefix 0
        j++;
      for (; j * i <= n; j++) {
        if (!tgt[i * j]) // Reserve
          break;
        else
          /* clog << i << ' ' << j << ' ' << i * j << endl,  */
          deleted[i * j] = 1, ans += i;
      }
    }
    // clog << buf + 1 << endl;
    cout << ans << endl;
  }
  return 0;
}
