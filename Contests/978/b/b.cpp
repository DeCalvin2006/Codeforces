/*
 * Author : AFGXF
 * Date : 2022-06-27 15:40:04
 * */

#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;
const int MAXN = 1000;
char s[MAXN];
int n;
int main() {
  cin >> n;
  int last = 0;
  int ans = 0;
  cin.get();
  for (int i = 1; i <= n; i++) {
    char c;
    cin.get(c);
    if (c == 'x') {
      if (last == 2) {
        ans++;
      } else {
        last++;
      }
    } else {
      last = 0;
    }
  }
  cout << ans << endl;
  return 0;
}
