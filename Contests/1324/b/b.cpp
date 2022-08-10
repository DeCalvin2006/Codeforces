/*
 * Author : AFGXF
 * Date : 2022-07-07 08:11:03
 * */

#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5E4 + 10;
int t, n;
int posmin[MAXN];
int posmax[MAXN];
int a[MAXN];
#define LOG(x) cout << "Line " << __LINE__ << ": " << #x << " = " << x << endl;
int main() {
  cin >> t;
  while (t--) {
    cin >> n;
    int tmp;
    memset(posmin, 0, sizeof posmin);
    memset(posmax, 0, sizeof posmax);
    bool ok = 0;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
      if (posmin[a[i]] == 0) {
        posmin[a[i]] = i;
      }
    }
    for (int i = n; i >= 1; i--) {
      if (posmax[a[i]] == 0) {
        posmax[a[i]] = i;
      }
    }
    for (int i = 1; i <= n; i++) {
      if (posmax[a[i]] - posmin[a[i]] > 1) {
        ok = 1;
      }
    }
    cout << (ok ? "YES" : "NO") << endl;
  }
  return 0;
}
