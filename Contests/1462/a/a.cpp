/*
 * Author : AFGXF
 * Date : 2022-07-02 14:00:11
 * */

#include <bits/stdc++.h>
using namespace std;
const int MAXN = 300 + 10;
int n, t;
int a[MAXN];
int main() {
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    for (int i = 1, j = n; i < j; i++, j--) {
      cout << a[i] << ' ' << a[j] << ' ';
    }
    if (n % 2)
      cout << a[n / 2 + 1];
    cout << endl;
  }
  return 0;
}
