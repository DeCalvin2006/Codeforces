/*
 * Author : AFGXF
 * Date : 2022-07-02 14:00:11
 * */

#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200 + 10;
int t, n;
char s[MAXN];
bool ok() {
  // 1: 2...020
  // 2: 20...20
  // 3: 202...0
  // 4: 2020...
  // 5: ...2020
  if (s[1] == '2') {       // 1,2,3,4;
    if (s[2] == '0') {     // 2,3,4
      if (s[3] == '2') {   // 3,4
        if (s[4] == '0') { // 4
          return true;
        } else { // 3
          return s[n] == '0';
        }
      } else { // 2
        return s[n] == '0' && s[n - 1] == '2';
      }
    } else { // 1
      return s[n] == '0' && s[n - 1] == '2' && s[n - 2] == '0';
    }

  } else { // 5;
    return s[n] == '0' && s[n - 1] == '2' && s[n - 2] == '0' && s[n - 3] == '2';
  }
}
int main() {

  cin >> t;
  while (t--) {
    cin >> n;
    cin >> (s + 1);
    cout << (ok() ? "YES" : "NO") << endl;
  }
  return 0;
}
