/*
 * Author : AFGXF
 * Date : 2021-09-25 15:14:45
 * */

#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int t, a, n;
int s[500];
int main() {
  // TODO: code here
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int k = 1; k <= n; k++) {
      // s[i] pair(s) of enchanced braces
      for (int i = 1; i <= k; i++) {
        cout << '(';
      }
      for (int i = 1; i <= k; i++) {
        cout << ')';
      }
      for (int i = k + 1; i <= n; i++) {
        cout << '(' << ')';
      }
      cout << endl;
    }
  }
  return 0;
}
