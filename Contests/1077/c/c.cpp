/*
 * Author : AFGXF
 * Date : 2022-06-30 14:00:02
 * */

#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2E5 + 10;
int n;
long long a[MAXN];
int exist[1000000 + 10];
long long q[MAXN];
int main() {
  cin >> n;
  long long sum = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    sum += a[i];
    exist[a[i]]++;
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    sum -= a[i];
    exist[a[i]]--;
    if (sum % 2 == 0 && sum / 2 <= (int)1E6 && exist[sum / 2]) {
      ans++;
      q[ans] = i;
    }
    sum += a[i];
    exist[a[i]]++;
  }
  cout << ans << endl;
  if (ans) {
    cout << q[1];
    for (int i = 2; i <= ans; i++) {
      cout << ' ' << q[i];
    }
  }
  return 0;
}
