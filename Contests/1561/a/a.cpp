/*
 * Author : AFGXF
 * Date : 2021-08-24 22:47:00
 * */
#include <algorithm>
#include <iostream>
using namespace std;
const int MAXN = 1E4 + 10;
int n;
int a[MAXN];
void f(int i) {
  if (i < n && a[i] > a[i + 1])
    swap(a[i], a[i + 1]);
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    int maxOffset = 0;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      maxOffset = max(maxOffset, abs(a[i] - i));
    }
    if (is_sorted(a + 1, a + 1 + n)) {
      cout << 0 << endl;
      continue;
    }
    if (is_sorted(a + 1, a + 1 + n, std::greater<int>())) {
      cout << n << endl;
      continue;
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1 << !(i % 2); j < n; j += 2) {
        f(j);
      }
      if (is_sorted(a + 1, a + 1 + n)) {
        cout << i << endl;
        break;
      }
    }
  }
  return 0;
}
