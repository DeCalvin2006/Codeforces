#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll read() {
  ll x = 0, f = 1;
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
const int N = 1000 + 10;
int n;
bool used[N];
int seq[N];
bool check(int val) {
  cin.sync_with_stdio(0);
  cout.sync_with_stdio(0);
  for (int x = 1; x <= n; x++) {
    int last = x;
    bool bad = 0;
    seq[1] = x;
    memset(used, 0, sizeof used);
    used[x] = 1;
    for (int i = 2; i <= n; i++) {
      bool ok = 0;
      for (int j = 1; j <= n; j++) {
        if (used[j])
          continue;
        if (abs(j - last) < val)
          continue;
        last = j;
        used[j] = 1;
        seq[i] = j;
        ok = 1;
        break;
      }
      if (!ok) {
        bad = 1;
        break;
      }
    }
    if (!bad) {
      // cout << val << ": ";
      // for (int i = 1; i <= n; i++) {
      //   cout << ' ' << seq[i];
      // }
      // cout << endl;
      return 1;
    }
  }
  return 0;
}
int main() {
  int t = read();
  while (t--) {
    n = read();
    if (n % 2 == 0) {
      for (int i = 1; i <= n / 2; i++) {
        cout << n / 2 + i << ' ' << i << ' ';
      }
      cout << endl;
    } else {
      n -= 1;
      for (int i = 1; i <= n / 2; i++) {
        cout << n / 2 + i << ' ' << i << ' ';
      }
      cout << n + 1 << endl;
    }
  }
  return 0;
}
