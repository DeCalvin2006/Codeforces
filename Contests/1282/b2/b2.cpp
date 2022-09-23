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
int a[N];
int sum[N];
int t, n, p, k;
void init() {
  n = read(), p = read(), k = read();
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + 1 + n);
  for (int i = 1; i <= n; i++) {
    // clog << a[i] << " \n"[i == n];
    sum[i] = sum[i - 1] + a[i];
  }
}
int main() {
  int t = read();
  while (t--) {
    init();
    int ans = 0;
    for (int i = 0; i <= k; i++) {
      // clog << "Checking [" << 1 << "<<" << i << "]" << endl;
      if (sum[i] > p) {
        break;
      }
      int nans = i;
      int tmpp = p - sum[i];
      for (int j = i + 1; j <= n; j += k) {
        int endp = j + k - 1;
        if (endp > n) {
          break;
        }
        // clog << "Checking [" << j << "<<" << endp << "]" << endl;
        if (a[endp] <= tmpp) {
          nans += k;
          tmpp -= a[endp];
        } else
          break;
      }
      // clog << "Answer=" << nans << endl;
      ans = max(nans, ans);
    }
    cout << ans << endl;
  }
  // TODO: code here
  return 0;
}
