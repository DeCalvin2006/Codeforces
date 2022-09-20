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
  int t;
  string s = "Timur";
  sort(s.begin(), s.end());
  t = read();
  while (t--) {
    int n = read();
    string x;
    cin >> x;
    sort(x.begin(), x.end());
    if (x == s)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}
