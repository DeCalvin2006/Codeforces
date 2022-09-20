/*
 * Author : AFGXF
 * Date : 2022-08-14 08:20:23
 * */

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
int n;
int a[N];
int t;
bool deleted[N];
int main() {
  t = read();
  while (t--) {
    memset(deleted, 0, sizeof deleted);
    n = read();
    for (int i = 1; i <= n; i++) {
      a[i] = read();
    }
    int cnt = n;
    for (; cnt >= 1; cnt--) {
      if (a[cnt] < a[cnt - 1]) {
        break;
      }
    }
    // clog << "Test " << t << endl;
    if (cnt == 0) {
      cout << 0 << endl;
    } else {
      int ans = 0;
      // clog << cnt << endl;
      for (int i = 1; i < cnt; i++) {
        // clog << i << ":" << a[i] << endl;
        if (!deleted[a[i]]) {
          ans++;
          deleted[a[i]] = 1;
          // clog << "Deleted " << a[i] << endl;
        }
      }
      // clog << "First Deletion Complete" << endl;
      for (int i = cnt; i <= n; i++) {
        if (deleted[a[i]]) {
          // clog << i << endl;
          for (int j = cnt; j < i; j++) {
            if (!deleted[a[j]]) {
              ans++;
              deleted[a[j]] = 1;
              // clog << "Deleted " << a[j] << endl;
            }
          }
        }
      }
      cout << ans << endl;
    }
  }
  return 0;
}
