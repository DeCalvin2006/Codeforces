#include <bits/stdc++.h>
#define int unsigned long long
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
int n, k;
signed main() {
  n = read(), k = read();
  char maxc = 0;
  for (auto s : to_string(k)) {
    maxc = max(s, maxc);
  }
  if (maxc == '1' && n > to_string(k).length()) {
    cout << -1 << endl;
    return 0;
  }
  map<int, int> dist;
  queue<int> q;
  q.push(k);
  dist[k] = 0;
  while (!q.empty()) {
    auto k = q.front();
    q.pop();
    string s = to_string(k);
    if (s.length() == n) {
      cout << dist[k] << endl;
      return 0;
    }
    for (auto c : s) {
      int i = c - '0';
      int nxt = k * i;
      if (!dist.count(nxt)) {
        dist.insert(make_pair(nxt, dist[k] + 1));
        q.push(nxt);
      }
    }
  }
  // TODO: code here
  return 0;
}
