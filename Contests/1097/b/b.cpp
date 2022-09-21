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
const int N = (1 << 17);
int n;
int deg[N];
int main() {
  n = read();
  for (int i = 1; i <= n; i++) {
    deg[i] = read();
  }
  string ans = "NO";
  for (int i = 0; i < (1 << n); i++) {
    int tmp = i;
    int res = 0;
    for (int i = 1; i <= n; i++) {
      if (tmp & 1) {
        res += deg[i];
      } else {
        res -= deg[i];
      }
      tmp >>= 1;
    }
    if (res % 360 == 0) {
      ans = "YES";
    }
  }
  cout << ans << endl;
  return 0;
}
