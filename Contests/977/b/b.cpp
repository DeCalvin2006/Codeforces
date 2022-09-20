/*
 * Author : AFGXF
 * Date : 2022-08-10 14:40:25
 * */

#include <bits/stdc++.h>
using namespace std;
int read() {
  int x = 0, f = 1;
  char c = getchar();
  while (c > '9' || c < '0') {
    if (c == '-')
      f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = (x << 1) + (x << 3) + c - '0';
    c = getchar();
  }
  return x * f;
}
const int N = 100 + 10;
map<string, int> mp;
char c[N];
int n;
int main() {
  n = read();
  cin >> (c + 1);
  for (int i = 1; i < n; i++) {
    // cout << string(c + 1, i - 1, 2) << endl;
    mp[string(c + 1, i - 1, 2)]++;
  }
  auto ans = make_pair(string(""), 0);
  for (const auto &x : mp) {
    if (ans.second < x.second) {
      ans.first = x.first;
      ans.second = x.second;
    }
  }
  cout << ans.first << endl;
  return 0;
}
