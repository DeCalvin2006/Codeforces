/*
 * Author : AFGXF
 * Date : 2021-09-29 22:02:30
 * */

#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    string s;
    cin >> s;
    int a = 0, b = 0, c = 0;
    for (const auto &x : s) {
      switch (x) {
      case 'A': {
        a++;
        break;
      }
      case 'B': {
        b++;
        break;
      }
      case 'C': {
        c++;
        break;
      }
      default:
        break;
      }
    }
    if (a + c == b)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
