/*
 * Author : AFGXF
 * Date : 2021-09-25 15:14:50
 * */

#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int main() {
  int t;
  cin >> t;
  int a, b, c;
  while (t--) {
    cin >> a >> b >> c;
    int m;
    cin >> m;
    if (m <= a - 1 + b - 1 + c - 1 && c - 1 - (a + b) <= m)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
