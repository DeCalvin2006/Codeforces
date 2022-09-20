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
int main() {
  int t = read();
  while (t--) {
    int n = read(), m = read(), sx = read(), sy = read(), d = read();
    if ((sx + d >= n && sx - d <= 1) || (sy + d >= m && sy - d <= 1)) {
      cout << -1 << endl;
    } else
      cout << n + m - 2 << endl;
  }
  return 0;
}
