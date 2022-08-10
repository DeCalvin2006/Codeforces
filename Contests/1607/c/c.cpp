/*
 * Author : AFGXF
 * Date : 2022-07-04 08:30:02
 * */

#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2E5 + 10;
int t, n;
int a[MAXN];
int main() {
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    int sum = 0;
    int maxval = -1E9;
    for (int i = 1; i <= n; i++) {
      maxval = max(maxval, a[i] - a[i - 1]);
    }
    cout << maxval << endl;
  }
  return 0;
}
