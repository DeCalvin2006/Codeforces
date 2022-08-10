/*
 * Author : AFGXF
 * Date : 2022-07-07 10:48:37
 * */

#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2E5 + 10;
int a[MAXN];
int b[MAXN];
int ab[MAXN];
int n;
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
  }
  for (int i = 1; i <= n; i++) {
    ab[i] = a[i] - b[i];
  }
  sort(ab + 1, ab + 1 + n);
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    // cout << b[i] - a[i] << endl;
    int t = lower_bound(ab + 1, ab + 1 + i, b[i] - a[i]) - (ab + 1);
    // for (int i = 1; i <= t; i++) {
    // cout << ab[t] << ' ';
    //}
    // cout << endl;
    cout << t << endl;
    ans += t;
  }
  cout << ans << endl;
  return 0;
}
