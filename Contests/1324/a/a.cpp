/*
 * Author : AFGXF
 * Date : 2022-07-07 08:01:02
 * */

#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1E5 + 10;
int t, n;
int a[MAXN];
int main() {
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      a[i] %= 2;
    }
    int s = 0;
    for (int i = 1; i <= n; i++) {
      s += a[i];
    }

    if (s % n == 0)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }

  return 0;
}
