/*
 * Author : AFGXF
 * Date : 2022-08-09 18:05:06
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
vector<double> vec;
int n;
int res[N << 1], ans1, ans2;
int main() {
  n = read();
  for (int i = 1; i <= n; i++) {
    int a = read(), b = read();
    vec.push_back(atan2(b, a));
  }
  sort(vec.begin(), vec.end());
  for (const auto &a : vec) {
    cout << a << ' ';
  }
  cout << endl;
  return 0;
}
