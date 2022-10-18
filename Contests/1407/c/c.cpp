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
int ask(int a, int b) {
  cout << "? " << a << " " << b << endl;
  int z;
  cin >> z;
  return z;
}
const int N = 1E4 + 10;
int n;
int ans[N];
int main() {
  cin >> n;
  int mx = 0;
  for (int i = 1; i < n; i++) {
    int a = ask(mx + 1, i + 1);
    int b = ask(i + 1, mx + 1);
    if (a > b) {
      ans[mx] = a;
      mx = i;
    } else {
      ans[i] = b;
    }
  }
  ans[mx] = n;
  cout << "! ";
  for (int i = 0; i < n; i++) {
    cout << ans[i] << ' ';
  }
  cout << endl;
  // TODO: code here
  return 0;
}
