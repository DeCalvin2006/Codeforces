/*
 * Author : AFGXF
 * Date : 2022-07-06 15:10:22
 * */

#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1E5 + 10;
int a[MAXN];
int dp[MAXN];
int n;
int main() {
  cin >> n;
  int maxa = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    dp[i] = a[i] > a[i - 1] ? dp[i - 1] + 1 : 1;
    maxa = max(maxa, dp[i]);
  }
  cout << maxa << endl;
  return 0;
}
