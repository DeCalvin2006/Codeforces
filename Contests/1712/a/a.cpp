/*
 * Author : AFGXF
 * Date : 2022-08-14 08:01:45
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
int n;
int main() {
  int t;
  t = read();
  while (t--) {
    n = read();
    int k = read();
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      int a = read();
      if (i <= k && a > k) {
        ans++;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
