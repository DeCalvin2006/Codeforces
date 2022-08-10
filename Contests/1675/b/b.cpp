/*
 * Author : AFGXF
 * Date : 2022-07-02 08:30:02
 * */

#include <bits/stdc++.h>
using namespace std;
const int MAXN = 30 + 10;
int t;
int n;
int a[MAXN];
int main() {
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    int ans = 0;
    for (int i = n - 1; i >= 1; i--) {
      while (a[i] > 0 && a[i] >= a[i + 1]) {
        //cout << i << ' ' << a[i] << ' ';
        a[i] >>= 1;
        //cout << a[i] << endl;
        ans++;
      }
    }
    bool ok = 1;
    for (int i = 1; i < n; i++) {
      //cout << a[i] << ' ';
      if (a[i] >= a[i + 1]) {
        ok = 0;
      }
    }
    //cout << a[n] << endl;
    if (ok)
      cout << ans << endl;
    else
      cout << "-1" << endl;
  }
  return 0;
}
