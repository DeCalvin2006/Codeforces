/*
 * Author : AFGXF
 * Date : 2022-07-04 08:30:02
 * */

#include <bits/stdc++.h>
using namespace std;
long long t, n, x0;
int main() {
  cin >> t;
  while (t--) {
    cin >> x0 >> n;
    if (x0 % 2 == 0) {
      switch (n % 4) {
      case 1: {
        x0-=n;
        break;
      }
      case 2: {
        x0++;
        break;
      }
      case 3: {
        x0 += n + 1;
        break;
      }
      }
    } else {
      switch (n % 4) {
      case 1: {
        x0 += n;
        break;
      }
      case 2: {
        x0--;
        break;
      }
      case 3: {
        x0 -= n + 1;
        break;
      }
      }
    }
    cout << x0 << endl;
  }
  return 0;
}
