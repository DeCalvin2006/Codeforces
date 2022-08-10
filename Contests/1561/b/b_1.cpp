/*
 * Author : AFGXF
 * Date : 2021-08-24 23:59:46
 * */
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
const int MAXN = 2E5 + 10;
bool has[MAXN];
int t;
int a, b;
int ans[MAXN], k;
int main() {
  cin >> t;
  while (t--) {
    cin >> a >> b;
    k = 0;
    {
      int p = (a + b) / 2;
      int q = (a + b) - p;
      for (int x = 0; x <= p; x++) {
        int y = a - (p - x);
        if (0 <= y && y <= q) {
          k++;
          ans[k] = x + y;
        }
      }
      for (int y = 0; y <= q; y++) {
        int x = b - (q - y);
        if (0 <= x && x <= p) {
          k++;
          ans[k] = x + y;
        }
      }
    }
    {
      int q = (a + b) / 2;
      int p = (a + b) - q;
      for (int x = 0; x <= p; x++) {
        int y = a - (p - x);
        if (0 <= y && y <= q) {
          k++;
          ans[k] = x + y;
        }
      }
      for (int y = 0; y <= q; y++) {
        int x = b - (q - y);
        if (0 <= x && x <= p) {
          k++;
          ans[k] = x + y;
        }
      }
    }
    std::sort(ans + 1, ans + 1 + k);
    k = std::unique(ans + 1, ans + 1 + k) - (ans + 1);
    cout << k << endl;
    for (int i = 1; i <= k; i++) {
      cout << ans[i] << ' ';
    }
    cout << endl;
  }
  return 0;
}
