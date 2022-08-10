/*
 * Author : AFGXF
 * Date : 2021-12-24 22:37:44
 * */

#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int MAXN = 100 + 10;
int n, t;
int a[MAXN];
int main() {
  cin >> t;

  while (t--) {
    cin >> n;
    int sum = 0;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      sum += a[i];
    }
    if (sum % n == 0)
      cout << 0 << endl;
    else
      cout << 1 << endl;
  }
  return 0;
}
