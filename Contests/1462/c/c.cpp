/*
 * Author : AFGXF
 * Date : 2022-07-02 14:00:11
 * */

#include <bits/stdc++.h>
using namespace std;
int t;
int n;
int ans[100], top;
int main() {
  cin >> t;
  while (t--) {
    cin >> n;
    top = 0;
    int tmpn = n;
    for (int i = 9; tmpn && i >= 0; i--) {
      if (tmpn >= i) {
        tmpn -= i;
        ans[++top] = i;
      }
    }
    if (tmpn > 0) {
      cout << -1 << endl;
      continue;
    }
    sort(ans + 1, ans + 1 + top);
    for (int i = 1; i <= top; i++) {
      cout << ans[i];
    }
    cout << endl;
  }
  return 0;
}
