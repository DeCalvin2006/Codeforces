#include <bits/stdc++.h>
#include <type_traits>
#include <utility>
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
map<string, int> mp;
vector<string> p[3];
int ans[3];
int t;
int main() {
  t = read();
  while (t--) {
    int n = read();
    mp.clear();
    for (int i = 0; i < 3; i++) {
      p[i].clear();
      for (int j = 1; j <= n; j++) {
        string t;
        cin >> t;
        p[i].push_back(t);
        if (mp.count(t))
          mp[t]++;
        mp.insert(make_pair(t, 1));
      }
    }
    for (int i = 0; i < 3; i++) {
      ans[i] = 0;
      for (const auto &t : p[i]) {
        clog << t << ' ';
        int k = mp[t];
        if (k == 1)
          ans[i] += 3;
        if (k == 2)
          ans[i] += 1;
      }
      clog << endl;
    }
    for (int i = 0; i < 3; i++) {
      cout << ans[i] << ' ';
    }
    cout << endl;
  }
  return 0;
}
