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
const int N = 100 + 10;
int a[N];
int main() {
  int t = read();
  int n;
  while (t--) {
    n = read();
    for (int i = 1; i <= n; i++)
      a[i] = read();
    sort(a + 1, a + 1 + n);
    if (is_sorted(a + 1, a + 1 + n, [](int a, int b) { return a <= b; }))
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  // TODO: code here
  return 0;
}
