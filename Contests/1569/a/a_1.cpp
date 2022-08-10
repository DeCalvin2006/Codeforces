/*
 * Author : AFGXF
 * Date : 2021-09-12 16:09:59
 * */

#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int MAXN = 500;
int suma[MAXN], sumb[MAXN];
int t, n;
char c[MAXN];
int main() {
  cin >> t;
  while (t--) {
    cin >> n;
    cin >> (c + 1);
    cout << c + 1 << endl;
    for (int i = 1; i <= n; i++) {
      suma[i] = suma[i - 1] + (c[i] == 'a');
      sumb[i] = sumb[i - 1] + (c[i] == 'b');
    }
    int l, r;
    l = 1, r = n;
    for (int len = 1; len <= n; len++) {
      for (l = 1; l + len - 1 <= n; l++) {
        r = l + len - 1;
        if (suma[r] - suma[l - 1] == sumb[r] - sumb[l - 1]) {
          goto output;
        }
      }
    }
    l = r = -1;
  output:
    cout << l << ' ' << r << endl;
  }
  return 0;
}
