/*
 * Author : AFGXF
 * Date : 2022-07-02 08:30:02
 * */

#include <bits/stdc++.h>
using namespace std;
int t;
int a, b, c, x, y;
int main() {
  cin >> t;
  while (t--) {
    cin >> a >> b >> c >> x >> y;
    x -= a, y -= b;
    if (x > 0) {
      c -= x;
    }
    if (y > 0) {
      c -= y;
    }
    if (c>=0) {
      cout << "YES" << endl;
    } else
      cout << "NO" << endl;
  }
  return 0;
}
