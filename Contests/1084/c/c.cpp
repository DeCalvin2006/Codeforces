#include <bits/stdc++.h>
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
const int N = 1E5 + 10;
const int MOD = 1E9 + 7;
string s;
int cnt = 1;
int ans[N];
int mul[N];
signed main() {
  // TODO: code here
  char c = '\0', last = '\0';
  while ((c = getchar()) != '\n') {
    if (c == 'a') {
      ans[cnt]++;
      last = c;
    }
    if (c == 'b' && last != c && cnt[ans] != 0) {
      cnt++;
      last = c;
    }
  }
  if (ans[cnt] == 0)
    cnt--;
  mul[0] = 1;
  for (int i = 1; i <= cnt; i++) {
    mul[i] = mul[i - 1] * (ans[i] + 1) % MOD;
  }
  cout << mul[cnt] - 1 << endl;
  return 0;
}
