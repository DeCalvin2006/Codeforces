/*
 * Author : AFGXF
 * Date : 2021-09-04 18:15:42
 * */

#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int c, d;
int n;
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> c >> d;
    int a = 0, b = 0;
    if (c > d)
      swap(c, d);
    if (c == d) {
      cout << (c == 0 ? 0 : 1) << endl;
    } else if ((d - c) % 2 == 0) {
      cout << 2 << endl;
    } else {
      cout << -1 << endl;
    }
  }
  return 0;
}
