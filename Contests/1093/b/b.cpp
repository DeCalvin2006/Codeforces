/*
 * Author : AFGXF
 * Date : 2022-07-03 09:30:23
 * */

#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000 + 10;
int t, n;
char s[MAXN];
bool isp() {
  for (int i = 1, j = n; i < j; i++, j--) {
    if (s[i] != s[j]) {
      return 0;
    }
  }
  return 1;
}
int main() {
  cin >> t;
  while (t--) {
    cin >> (s + 1);
    n = strlen(s + 1);
    if (isp()) {
      bool ok = 0;
      for (int i = 1; i < n; i++) {
        if (s[i] != s[i + 1]) {
          swap(s[i], s[i + 1]);
          cout << (s + 1) << endl;
          ok = 1;
          break;
        }
      }
      if (!ok) {
        cout << "-1" << endl;
      }
    } else {
      cout << (s + 1) << endl;
    }
  }
  return 0;
}
