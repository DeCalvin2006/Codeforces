/*
 * Author : AFGXF
 * Date : 2021-09-12 16:09:59
 * */

#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int MAXN = 500;
int t, n;
char c[MAXN];
int main() {
  cin >> t;
  while (t--) {
    cin >> n;
    cin >> (c + 1);
    for (int l = 1; l < n; l++) {
      if (c[l] != c[l + 1]) {
        cout << l << ' ' << l + 1 << endl;
        goto output;
      }
    }
    cout << "-1 -1\n";
  output:
    continue;
  }
  return 0;
}
