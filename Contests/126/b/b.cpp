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
vector<int> prefix(const string &s) {
  int n = s.length();
  vector<int> pi(n);
  for (int i = 1; i < n; i++) {
    int j = pi[i - 1];
    while (j && s[i] != s[j])
      j = pi[j - 1];
    if (s[i] == s[j])
      j++;
    pi[i] = j;
  }
  return pi;
}
int main() {
  string s;
  cin >> s;
  int n = s.length();
  auto k1 = prefix(s);
  reverse(s.begin(), s.end());
  // for (int i = 0; i < n; i++) {
  //   clog << i << "\n\t"[i < n - 1];
  // }
  // for (int i = 0; i < n; i++) {
  //   clog << k1[i] << "\n\t"[i < n - 1];
  // }
  auto k2 = prefix(s);
  reverse(k2.begin(), k2.end());
  // for (int i = 0; i < n; i++) {
  //   clog << i << "\n\t"[i < n - 1];
  // }
  // for (int i = 0; i < n; i++) {
  //   clog << k2[i] << "\n\t"[i < n - 1];
  // }
  int ansl = 0, ansr = 0;
  for (int r = 0; r < n; r++) {
    int len = k1[r];
    if (len == 0)
      continue;
    int l = r - len + 1;
    if (k2[r] == 0)
      continue;
    // clog << l << ' ' << r << endl;
    if (k1[r] == k2[l]) {
      if (!ansl || r - l + 1 > ansr - ansl + 1)
        ansl = l, ansr = r;
      // clog << k1[r] << "==" << k2[l] << endl;
    } else {
      // clog << k1[r] << "!=" << k2[l] << endl;
    }
  }
  reverse(s.begin(), s.end());
  if (ansl && ansr) {
    for (int i = ansl; i <= ansr; i++) {
      cout << s[i];
    }
    cout << endl;
  } else
    cout << "Just a legend" << endl;
  return 0;
}
