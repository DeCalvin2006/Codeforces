#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll read() {
  ll x = 0, f = 1;
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
int n;
int main() {
  n = read();
  while (n--) {
    int a = read(), b = read(), c = read();
    while (!(a <= b && b <= c)) {
      if (a > b)
        swap(a, b);
      if (b > c)
        swap(b, c);
      if (a > c)
        swap(a, c);
    }
    if (a + b == c)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  // TODO: code here
  return 0;
}
