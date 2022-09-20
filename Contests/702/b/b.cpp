/*
 * Author : AFGXF
 * Date : 2022-08-10 15:04:23
 * */

#include <bits/stdc++.h>
using namespace std;
#define int unsigned long long
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
const int N = 1E5 + 10;
map<int, int> mp;
int a[N];
int n;
signed main() {
  n = read();
  for (int i = 1; i <= n; i++) {
    a[i] = read();
    mp[a[i]]++;
  }
  sort(a + 1, a + 1 + n);
  // for (auto x : mp) {
  // cout << x.first << ' ' << x.second << endl;
  //}
  int ans = 0;
  int maxp = ceil(log2(a[n] + a[n - 1]));
  for (int i = 1; i <= n; i++) {
    mp[a[i]]--;
    for (int j = maxp; j >= 1 && (1 << j) > a[i]; j--) {
      int pw = 1 << j;
      // cout << pw << endl;
      // if (mp[pw - a[i]]) {
      // cout << a[i] << ' ' << pw - a[i] << endl;
      //}
      ans += mp[pw - a[i]];
    }
  }

  cout << ans << endl;
  return 0;
}
