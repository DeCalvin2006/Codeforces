#include <algorithm>
#include <bits/stdc++.h>
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
int n;
int a[N];
int maxsum[2];
int main() {
  n = read();
  int sum = 0;
  for (int i = 1; i <= n; i++) {
    a[i] = read();
    if (a[i] > 0) {
      sum += a[i];
    }
  }
  if (sum % 2 == 1) {
    cout << sum << endl;
  } else {
    int minpos = 1E9 + 7, maxneg = -1E9 - 7;
    for (int i = 1; i <= n; i++) {
      if ((a[i] % 2 + 2) % 2 == 1) {
        if (a[i] > 0) {
          minpos = min(minpos, a[i]);
        } else if (a[i] < 0) {
          maxneg = max(maxneg, a[i]);
        }
      }
    }
    cout << sum - min(minpos, -maxneg);
  }

  return 0;
}
