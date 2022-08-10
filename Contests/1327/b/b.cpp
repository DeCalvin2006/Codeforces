/*
 * Author : AFGXF
 * Date : 2021-12-04 08:44:00
 * */

#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int MAXN = 1E5 + 10;
bool visb[MAXN], visg[MAXN];
int t, n;
int main() {
  cin >> t;
  while (t--) {
    cin >> n;
    int g = 0, b = 0;
    memset(visb, 0, sizeof(visb));
    memset(visg, 0, sizeof(visg));
    for (int i = 1; i <= n; i++) {
      int k;
      cin >> k;
      for (int j = 1, tmp; j <= k; j++) {
        cin >> tmp;
        if (visg[i] || visb[tmp]) {
          continue;
        } else {
          visb[tmp] = 1;
          visg[i] = 1;
          // cout << i << " married to " << tmp << endl;
        }
      }
      if (g == 0 && visg[i] == 0) {
        g = i;
      }
    }
    for (int i = 1; i <= n; i++) {
      if (!visb[i]) {
        b = i;
        break;
      }
    }
    if (g != 0 && b != 0) {
      cout << "IMPROVE" << endl;
      cout << g << ' ' << b << endl;
    } else {
      cout << "OPTIMAL" << endl;
    }
  }
  return 0;
}
