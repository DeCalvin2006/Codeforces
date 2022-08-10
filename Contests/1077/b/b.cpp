/*
 * Author : AFGXF
 * Date : 2022-06-30 14:00:02
 * */

#include <bits/stdc++.h>
using namespace std;
int n;
bool a[100 + 10];
bool isdst[100 + 10];
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 2; i < n; i++) {
    isdst[i] = a[i - 1] && a[i + 1] && !a[i];
  }
  int ans = 0;
  for (int i = 2; i < n; i++) {
    if (isdst[i]) {
      a[i + 1] = 0;
      isdst[i + 2] = 0;
      ans++;
    }
  }
  cout << ans << endl;

  return 0;
}
