/*
 * Author : AFGXF
 * Date : 2022-08-14 08:12:56
 * */

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
int t, n;
int a[N];
int main() {
  t = read();
  while (t--) {
    n = read();
    for (int i = 1; i <= n; i++) {
      a[i] = i;
    }
    for (int i = n; i > 1; i--) {
      if (a[i] == a[i - 1] + 1) {
        swap(a[i], a[i - 1]);
      }
    }
    for (int i = 1; i <= n; i++) {
      cout << a[i] << ' ';
    }
    cout << endl;
  }
  return 0;
}
