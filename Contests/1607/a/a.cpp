/*
 * Author : AFGXF
 * Date : 2022-07-04 08:30:02
 * */

#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100;
char s1[MAXN], s2[MAXN];
int table[MAXN];
int t;
int main() {
  cin >> t;
  while (t--) {
    cin >> (s1 + 1) >> (s2 + 1);
    int n = strlen(s2 + 1);
    for (int i = 1; i <= 26; i++) {
      table[s1[i] - 'a'] = i;
    }
    long long ans = 0;
    s2[1] = table[s2[1] - 'a'];
    for (int i = 2; i <= n; i++) {
      s2[i] = table[s2[i] - 'a'];
      ans += abs(s2[i] - s2[i - 1]);
    }
    cout << ans << endl;
  }
  return 0;
}
