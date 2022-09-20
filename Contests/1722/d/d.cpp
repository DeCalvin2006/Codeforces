#include <bits/stdc++.h>
#include <cstdio>
#include <functional>
#include <queue>
#include <vector>
#define int long long
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
const int N = 2E5 + 10;
char s[N];
int n, t;
signed main() {
  t = read();
  while (t--) {
    n = read();
    priority_queue<int> pq;
    cin >> (s + 1);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      // clog << "===" << i << endl;
      switch (s[i]) {
      case 'L': {
        pq.push((n - i) - (i - 1));
        // clog << (n - i) - (i - 1) << endl;
        ans += i - 1;
        break;
      }
      case 'R': {
        pq.push((i - 1) - (n - i));
        // clog << (i - 1) - (n - i) << endl;
        ans += n - i;
        break;
      }
      }
    }
    for (int i = 1; i <= n; i++) {
      if (!pq.empty()) {
        int t = pq.top();
        // clog << t << endl;
        if (t > 0) {
          pq.pop();
          ans += t;
        }
      }
      cout << ans << ' ';
    }
    // clog << endl;
    cout << endl;
  }
  return 0;
}
