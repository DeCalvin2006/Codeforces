/*
 * Author : AFGXF
 * Date : 2022-06-30 14:00:02
 * */

#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2E6 + 10;
struct num {
  int i, cnt;
} s[MAXN];
int n, k;
int maxs = 0, cnt = 0;
bool cmp(const num &a, const num &b) {
  return a.cnt == b.cnt ? a.i < b.i : a.cnt > b.cnt;
}
bool ok(int f) {
  int cnt = 0;
  for (int i = 1; i <= maxs; i++) {
    cnt += s[i].cnt / f;
  }
  return cnt >= k;
}
int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    int tmp;
    cin >> tmp;
    if (!s[tmp].cnt) {
      cnt++;
    }
    s[tmp].i = tmp;
    s[tmp].cnt++;
    maxs = max(maxs, tmp);
  }
  sort(s + 1, s + 1 + maxs, cmp);
  int l = 0;
  int r = n;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (ok(mid)) {
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }
  int cnt = 0;
  for (int i = 1; i <= k; i++) {
    while (s[i].cnt >= r&&cnt!=k) {
      s[i].cnt -= r;
      cnt++;
      cout << s[i].i << ' ';
    }
  }
  cout << endl;
  return 0;
}
