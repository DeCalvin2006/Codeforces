/*
 * Author : AFGXF
 * Date : 2022-06-27 15:40:04
 * */

#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2E5 + 10;
int n, m;
long long a[MAXN], b[MAXN];
long long s[MAXN];
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    s[i] = s[i - 1] + a[i];
  }
  for (int j = 1; j <= m; j++) {
    cin >> b[j];
    int ans = lower_bound(s + 1, s + 1 + n, b[j]) - (s);
    cout << ans << ' ';
    if (ans == 1) {
      cout << b[j] << endl;
    } else {
      cout << b[j] - s[ans - 1] << endl;
      // cout << a[ans - 1] << endl;
    }
  }
  return 0;
}
