/*
 * Author : AFGXF
 * Date : 2021-09-20 22:37:26
 * */

#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int a, b, c, m;
    cin >> a >> b >> c >> m;
    while (!(a <= b && b <= c)) {
      if (a > b) {
        swap(a, b);
      }
      if (b > c) {
        swap(b, c);
      }
      if (a > c) {
        swap(a, c);
      }
    }
    if (a / 2 + b / 2 + c / 2 < m) {
      cout << "NO" << endl;
    } else if (c - 1 > (a + b) && m == 0) {
      cout << "NO" << endl;
    } else
      cout << "YES" << endl;
  }
  return 0;
}
