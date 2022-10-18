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
const int N = 5000 + 10;
ll a[N];
ll sum[N];
int l[N], r[N];
int n;
inline ll getsum(int l, int r) { return sum[r - 1] - sum[l - 1]; }
// ostream &print_seg(int l, int r) {
//   clog << "[" << l << "," << r << ")=" << getsum(l, r);
//   return clog;
// }
int main() {
  n = read();
  for (int i = 0; i < n; i++) {
    a[i] = read();
    sum[i] = sum[i - 1] + a[i];
  }
  for (int i = 0; i < n; i++) {
    ll maxsum = LLONG_MIN;
    int left = 1;
    for (int j = 0; j <= i; j++) {
      if (getsum(0, j) - getsum(j, i) > maxsum) {
        maxsum = getsum(0, j) - getsum(j, i);
        left = j;
      }
    }
    l[i] = left;
  }
  for (int i = 0; i < n; i++) {
    ll maxsum = LLONG_MIN;
    int right = n;
    for (int j = i; j <= n; j++) {
      if (getsum(i, j) - getsum(j, n + 1) > maxsum) {
        maxsum = getsum(i, j) - getsum(j, n + 1);
        right = j;
      }
    }
    r[i] = right;
  }
  long long ans = LLONG_MIN, ans1, ans2, ans3;
  for (int i = 0; i < n; i++) {
    int tmp1 = l[i], tmp2 = i, tmp3 = r[i];
    ll val = getsum(0, tmp1) - getsum(tmp1, tmp2) + getsum(tmp2, tmp3) -
             getsum(tmp3, n);
    if (val > ans) {
      ans = val;
      ans1 = tmp1, ans2 = tmp2, ans3 = tmp3;
    }
  }
  // for (int i = 0; i < n; i++) {
  //   clog << l[i] << ' ' << i << ' ' << r[i] << endl;
  //   print_seg(0, l[i]) << ' ';
  //   print_seg(l[i], i) << ' ';
  //   print_seg(i, r[i]) << ' ';
  //   print_seg(r[i], n) << endl;
  // }
  cout << ans1 << ' ' << ans2 << ' ' << ans3 << endl;
  // TODO: code here
  return 0;
}
