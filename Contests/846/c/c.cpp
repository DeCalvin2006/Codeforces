#include <bits/stdc++.h>
#define int long long
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
const int N = 5E3 + 10;
int n;
int a[N];
int sum[N];
int ans[3], maxsum = LLONG_MIN;
inline int getsum(int l, int r) {
  if (r == 0) {
    return 0;
  }
  if (l == 0) {
    return sum[r - 1];
  }
  return sum[r - 1] - sum[l - 1];
}
signed main() {
  n = read();
  for (int i = 0; i < n; i++) {
    a[i] = read();
  }
  sum[0] = a[0];
  for (int i = 1; i < n; i++) {
    sum[i] = sum[i - 1] + a[i];
  }
  for (int end1 = 0; end1 <= n; end1++) {
    int sumx = getsum(0, end1);
    int sum2 = LLONG_MAX;
    int end2 = end1;
    for (int tmpend2 = end1; tmpend2 <= n; tmpend2++) {
      if (getsum(end1, tmpend2) < sum2) {
        sum2 = getsum(end1, tmpend2);
        end2 = tmpend2;
      }
    }
    sumx -= sum2;
    int sum3 = LLONG_MIN;
    int end3 = end2;
    for (int tmpend3 = end2; tmpend3 <= n; tmpend3++) {
      if (getsum(end2, tmpend3) > sum3) {
        sum3 = getsum(end2, tmpend3);
        end3 = tmpend3;
      }
    }
    sumx += sum3;
    sumx -= getsum(end3, n);
    if (sumx > maxsum) {
      ans[0] = end1, ans[1] = end2, ans[2] = end3;
      clog << "[" << 0 << "," << ans[0] << ")" << endl;
      clog << "[" << ans[0] << "," << ans[1] << ")" << endl;
      clog << "[" << ans[1] << "," << ans[2] << ")" << endl;
      clog << "[" << ans[2] << "," << n + 1 << ")" << endl;
      clog << sumx << endl;
      maxsum = sumx;
    }
    clog << endl;
  }
  for (auto k : (ans)) {
    cout << k << ' ';
  }
  return 0;
}
