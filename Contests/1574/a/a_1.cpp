/*
 * Author : AFGXF
 * Date : 2021-09-20 23:03:45
 * */

#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
char c[1000];
int main() {
  int n, t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1; i <= 2 * n; i++) {
      c[i] = (i % 2 ? '(' : ')');
    }
    for (int i = 1; i <= 2 * n; i++) {
      cout << c[i];
    }
    for (int i = 2; i < 2 * n; i += 2) {
      swap(c[i], c[i + 1]);
      for (int i = 1; i <= 2 * n; i++) {
        cout << c[i];
        cout << endl;
      }
    }
  }
  return 0;
}
