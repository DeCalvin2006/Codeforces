/*
 * Author : AFGXF
 * Date : 2022-07-03 09:30:23
 * */

#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2E5 + 10;
long long n;
long long b[MAXN];
long long a[MAXN];
int main() {
  cin >> n;
  a[0] = 0;
  a[n + 1] = 1E18 + 10;
  for (int i = 1; i <= n / 2; i++) {
    cin >> b[i];
    a[i] = a[i - 1];
    a[n - i + 1] = b[i] - a[i];
    if (!(a[n - i + 1] <= a[n - i + 2]) && a[n - i + 1]) {
      a[n - i + 1]--;
      a[i]++;
    }
  }
  cout << a[1];
  for (int i = 2; i <= n; i++) {
    cout << ' ' << a[i];
  }
  cout << endl;
  return 0;
}
