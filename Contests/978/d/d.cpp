/*
 * Author : AFGXF
 * Date : 2022-07-07 20:41:51
 * */

#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1E5 + 10;
int a[MAXN];
int b[MAXN];
int n;
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
  }
  int cnt = 0;
  for (int d1 = -1; d1 <= 1; d1++) {
    a[1] = b[1] + d1;
    for (int d2 = -1; d2 <= 1; d2++) {
      a[2] = b[2] + d2;
      cnt = abs(d1) + abs(d2);
      for (int i = 1; i <= n; i++) {
        a[i] = a[1] + (i - 1) * (a[2] - a[1]);
        if (abs(a[i] - b[i]) > 1) {
          cout << "-1" << endl;
          return 0;
        }
      }
    }
  }
  return 0;
}
