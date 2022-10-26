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

const int N = 2E5 + 10;
int t, n;
int a[N];
int sum1[N];
int sum2[N];
int main() {
  int t = read();
  while (t--) {
    n = read();
    for (int i = 1; i <= n; i++) {
      a[i] = read();
    }
    sum1[1] = a[1];
    for (int i = 2; i <= n; i++) {
      sum1[i] = sum1[i - 2] + a[i];
    }
  }
  return 0;
}
