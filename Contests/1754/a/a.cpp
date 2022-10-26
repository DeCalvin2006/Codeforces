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
int main() {
  int t = read();
  while (t--) {
    int n = read();
    int qcnt = 0;
    string s;
    cin >> s;
    for (char c : s) {
      qcnt += c == 'Q';
      qcnt -= c == 'A';
      qcnt = max(0, qcnt);
    }
    if (qcnt > 0)
      cout << "No" << endl;
    else
      cout << "Yes" << endl;
  }
  return 0;
}
