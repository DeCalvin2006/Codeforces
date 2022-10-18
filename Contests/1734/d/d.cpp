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
const int N = 2E5 + 10;
int sum[N];
int v[N];
int t, n, k;
int main() {
  t = read();
  while (t--) {
    n = read(), k = read();
    for (int i = 1; i <= n; i++) {
      v[i] = read();
      sum[i] = sum[i - 1] + v[i];
    }
    int maxr = k, sumr = 0;
    bool okr = 1;
    for (int i = k; i <= n; i++) {
      sumr += v[i];
      maxr = max(maxr, sumr);
      if (sumr < 0) {
        okr = 0;
      }
    }
    int maxl = k, suml = 0;
    for (int i = k; i >= 1; i--) {
      suml += v[i];
      maxl = max(maxl, suml);
    }
    if (suml > 0) {
      cout << "YES" << endl;
      continue;
    }
    int ok1 = true, ok2 = true;
    for (int i = k + 1; i <= n; i++) {
      maxl += v[i];
      if (maxl < 0) {
        ok1 = false;
        break;
      }
    }
    for (int i = k - 1; i >= 1; i--) {
      maxr += v[i];
      if (maxr < 0) {
        ok2 = false;
        break;
      }
    }
    cout << ok1 << ok2 << endl;
    if (ok1 || ok2)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
