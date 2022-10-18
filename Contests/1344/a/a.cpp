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
const int N = 2E5 + 10;
int t, n;
int buck[N];
int k[N];
int main() {
  // TODO: code here
  t = read();
  while (t--) {
    n = read();
    for (int i = 0; i < n; i++) {
      k[i] = 0;
      k[i] = (read() % n + n) % n;
      buck[i] = 0;
    }
    for (int i = 0; i < n; i++) {
      buck[(i + k[i]) % n]++;
    }
    bool ok = 1;
    for (int i = 0; i < n; i++) {
      if (buck[i] > 1)
        ok = 0;
    }
    if (ok)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
