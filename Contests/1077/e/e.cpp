/*
 * Author : AFGXF
 * Date : 2022-07-05 09:22:27
 * */

#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2E5 + 10;
int n;
int a[MAXN];
int num[MAXN], cnt;
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + 1 + n);
  for (int i = 1; i <= n; i++) {
    int j = i;
    while (a[i] == a[i + 1])
      i++;
    cnt++;
    num[cnt] = i - j + 1;
  }
  sort(num + 1, num + 1 + cnt);
  int maxans = 0;
  for (int i = 1; i <= num[cnt]; i++) {
    int cur = i;
    int pos = cnt;
    int ans = cur;
    while (cur % 2 == 0 && pos > 0) {
      cur >>= 1;
      pos--;
      if (cur > num[pos])
        break;
      ans += cur;
    }
    maxans = max(maxans, ans);
  }
  cout << maxans << endl;
  return 0;
}
