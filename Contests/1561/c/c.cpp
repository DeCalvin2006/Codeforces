/*
 * Author : AFGXF
 * Date : 2021-08-26 22:31:37
 * */
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int MAXN = 1E5 + 50;
struct val {
  int maxval;
  int k;
} vals[MAXN];
bool operator<(const val &a, const val &b) {
  return a.maxval == b.maxval ? a.k > b.k : a.maxval < b.maxval;
}
int t;
int main() {
  // :: code here
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int maxl = 0, sum = 0;
    for (int i = 1; i <= n; i++) {
      cin >> vals[i].k;
      vals[i].maxval = 0;
      for (int j = 1; j <= vals[i].k; j++) {
        int a;
        cin >> a;
        vals[i].maxval = max(vals[i].maxval, a - (j - 1));
      }
    }
    sort(vals + 1, vals + 1 + n);
    for (int i = 1; i <= n; i++) {
      maxl = max(maxl, vals[i].maxval-sum);
      sum += vals[i].k;
    }
    cout << maxl + 1 << endl;
  }
  return 0;
}
