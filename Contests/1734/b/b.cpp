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
int t;
int main() {
  t = read();
  while (t--) {
    int n = read();
    for (int i = 1; i <= n; i++) {
      if (i == 1)
        cout << 1 << endl;
      else if (i == 2)
        cout << 1 << ' ' << 1 << endl;
      else {
        cout << 1 << ' ';
        for (int j = 2; j <= i - 1; j++) {
          cout << 0 << ' ';
        }
        cout << 1 << endl;
      }
    }
  }
  return 0;
}
