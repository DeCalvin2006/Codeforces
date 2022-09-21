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
const int N = 15;
int fact[N];
int n;
int popcount(int x) {
  int cnt = 0;
  while (x) {
    x -= (x & (-x));
    cnt++;
  }
  return cnt;
}

signed main() {
  n = read();
  fact[0] = 1;
  for (int i = 1; i < N; i++) {
    fact[i] = fact[i - 1] * i;
  }
  while (n--) {
    int k = read();
    int ans = __builtin_popcountll(k);
    // clog << "Bitwise: " << ans << endl;
    for (int i = 0; i < (1 << N); i++) {
      int sum = 0, cnt = 1;
      int tmpi = i;
      while (tmpi) {
        if (tmpi & 1) {
          sum += fact[cnt];
        }
        tmpi >>= 1;
        cnt++;
      }
      if (k >= sum) {
        ans = min(ans, (unsigned long long)__builtin_popcountll(i) +
                           __builtin_popcountll(k - sum));
      }
    }
    cout << ans << endl;
  }
  // TODO: code here
  return 0;
}
