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
const int N = 5200 + 10;
int n;
bool k[N][N];
int s[N][N];
int calcsum(int x1, int y1, int x2, int y2) {
  return s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 - 1] + s[x1 - 1][y1 - 1];
}
int main() {
  n = read();
  // TODO: code here
  for (int i = 1; i <= n; i++) {
    string tmp;
    cin >> tmp;
    for (int j = 0; j < n / 4; j++) {
      int now = tmp[j];
      if ('0' <= now && now <= '9') {
        now -= '0';
      } else {
        now = 10 + now - 'A';
      }
      for (int p = 3; p >= 0; p--) {
        k[i][j * 4 + 3 - p + 1] = now & (1 << p);
      }
    }
  }
  // for (int i = 1; i <= n; i++)
  //   for (int j = 1; j <= n; j++)
  //     clog << k[i][j] << " \n"[j == n];
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + k[i][j];
    }
  }
  // for (int i = 1; i <= n; i++)
  //   for (int j = 1; j <= n; j++)
  //     clog << s[i][j] << " \n"[j == n];
  for (int x = n; x >= 1; x--) {
    if (n % x != 0)
      continue;
    for (int i = 1; i <= n - x + 1; i += x) {
      for (int j = 1; j <= n - x + 1; j += x) {
        // cout << i << ' ' << j << ' ' << i + x - 1 << ' ' << j + x - 1 <<
        // endl;
        if (calcsum(i, j, i + x - 1, j + x - 1) != 0 &&
            calcsum(i, j, i + x - 1, j + x - 1) != x * x) {
          goto notok;
        }
      }
    }
    cout << x << endl;
    break;
  notok:
    continue;
  }
  return 0;
}
