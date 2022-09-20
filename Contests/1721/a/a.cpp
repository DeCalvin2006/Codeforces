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
int main() {
  int t;
  t = read();
  while (t--) {
    string s, s1, s2;
    cin >> s1 >> s2;
    s = s1 + s2;
    map<char, int> mp;
    for (auto c : s)
      mp[c]++;
    int cnt[5] = {0, 0, 0, 0, 0};
    for (auto k : mp) {
      // cout << k.second << endl;
      cnt[k.second]++;
    }
    if (cnt[4]) {
      cout << 0 << endl;
    } else if (cnt[3] || cnt[2] == 2) {
      cout << 1 << endl;
    } else if (cnt[2] == 1) {
      cout << 2 << endl;
    } else if (cnt[1] == 4) {
      cout << 3 << endl;
    }
  }
  return 0;
}
