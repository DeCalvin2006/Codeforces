/*
 * Author : AFGXF
 * Date : 2022-07-07 08:52:05
 * */

#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2E5 + 10;
char s[MAXN];
int t;
int main() {
  cin >> t;
  while (t--) {
    cin >> (s + 1);
    int n = strlen(s + 1);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      int j = i;
      if (s[j] == 'L') {
        while (s[i] == s[i + 1]) {
          i++;
        }
        ans = max(ans, i - j + 1);
      }
    }
    cout << ans+1 << endl;
  }
  return 0;
}
