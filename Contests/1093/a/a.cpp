/*
 * Author : AFGXF
 * Date : 2022-07-03 09:30:23
 * */

#include <bits/stdc++.h>
using namespace std;
int t, n;
int main() {
  cin >> t;
  while (t--) {
    cin >> n;
    int ans = 0;
    while (n > 0) {
      n -= 6;
      ans++;
    }
    if (n > 0) {
      ans++;
    }
    cout << ans << endl;
  }
  return 0;
}
