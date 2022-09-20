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
int main() {
  string a, b;
  int t = read();
  while (t--) {
    int n = read();
    cin >> a >> b;
    for (auto &x : a) {
      if (x == 'B')
        x = 'G';
    }
    for (auto &x : b) {
      if (x == 'B')
        x = 'G';
    }
    if (a == b)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
