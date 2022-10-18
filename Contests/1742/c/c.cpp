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
const int N = 100;
char c[N][N];
int main() {
  int t = read();
  while (t--) {
    for (int i = 1; i <= 8; i++) {
      cin >> (c[i] + 1);
    }
    bool ok = 0;
    for (int i = 8; i >= 1; i--) {
      char x = c[i][1];
      if (x == '.')
        continue;
      bool same = 1;
      for (int j = 2; j <= 8; j++) {
        if (c[i][j] != x) {
          same = 0;
          break;
        }
      }
      if (same && !ok) {
        ok = 1;
        cout << x << endl;
        break;
      }
    }
    for (int i = 8; i >= 1; i--) {
      char x = c[1][i];
      if (x == '.')
        continue;
      bool same = 1;
      for (int j = 2; j <= 8; j++) {
        if (c[j][i] != x) {
          same = 0;
          break;
        }
      }
      if (same && !ok) {
        ok = 1;
        cout << x << endl;
        break;
      }
    }
  }
  return 0;
}
