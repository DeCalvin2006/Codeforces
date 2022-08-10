/*
 * Author : AFGXF
 * Date : 2021-10-04 18:25:07
 * */

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int MAXN = 114514;
int a[MAXN];
int t;
int main() {
  cin >> t;
  while (t--) {
    int n, H;
    cin >> n >> H;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    sort(a + 1, a + 1 + n, greater<int>());
    int t = a[1] + a[2];
    int ans = (H / t) << 1;
    int remain = H - (ans >> 1) * t;
    if (remain > a[1])
      ans += 2;
    else if (remain > 0)
      ans += 1;

    cout << ans << endl;
  }
  return 0;
}
