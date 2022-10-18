#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
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
const int T = 100 + 10;
const int N = 10 + 10;
int q, n;
string t, str[N];
bool color[T];
vector<pii> ans;
int search(int beg, int end) {
  int matchpos = beg, matchend = 0, matchi = 0;

  for (int i = beg; i <= end; i++) {

    for (int j = 1; j <= n; j++) {

      if (i + str[j].length() <= end || i + str[j].length() > t.length())
        continue;

      if (t.substr(i, str[j].length()) == str[j]) {
        if (str[j].length() + i > matchend) {
          matchend = str[j].length() + i;
          matchpos = i;
          matchi = j;
        }
      }
    }
  }
  if (!matchi) {
    return 0;
  }
  // clog << str[matchi] << " Match!" << endl;
  // clog << "Next starts in:" << matchpos + 1 << "," << matchend << endl;
  ans.emplace_back(matchi, matchpos);
  if (matchend >= t.length()) {
    return 1;
  } else {
    return search(matchpos + 1, matchend);
  }
}
int main() {
  q = read();
  while (q--) {
    cin >> t;
    cin >> n;
    ans.clear();
    // clog << q << ":=====" << endl;
    for (auto i = 1; i <= n; i++) {
      cin >> str[i];
    }
    if (search(0, 0)) {
      cout << ans.size() << endl;
      // sort(ans.begin(), ans.end(),
      //      [](const pii &a, const pii &b) { return a.second < b.second; });
      for (auto k : ans) {
        cout << k.first << ' ' << k.second + 1 << endl;
      }
    } else {
      cout << -1 << endl;
    }
  }
  // TODO: code here
  return 0;
}
