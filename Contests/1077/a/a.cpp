/*
 * Author : AFGXF
 * Date : 2022-06-30 14:00:02
 * */

#include <bits/stdc++.h>
using namespace std;
int t, a, b, k;
int main() {
  cin >> t;
  while (t--) {
    cin >> a >> b >> k;
    long long d = a - b;
    if (k % 2) {
      cout <<1LL* d * (k / 2) + a << endl;
    } else
      cout << 1LL*d * (k / 2) << endl;
  }
  // TODO: code here
  return 0;
}
