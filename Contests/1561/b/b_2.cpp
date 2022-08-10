/*
 * Author : AFGXF
 * Date : 2021-08-24 23:59:46
 * */
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
const int MAXN = 2E5 + 10;
bool has[MAXN];
int t;
int a, b;
int main() {
  cin >> t;
  while (t--) {
    cin >> a >> b;
    if (a == 0 || b == 0) {
      cout << 2 << endl;
      cout << (a + b) / 2;
      if (a + b % 2 == 1)
        cout << " " << (a + b) / 2 + 1;
      cout << endl;
    } else if (abs(a - b) == 1) {
      cout << a + b + 1 << endl;
      for (int i = 0; i <= a + b; i++) {
        cout << i << ' ';
      }
      cout << endl;
    } else {
      string c = "";
      for (int i = 0; i < a; i++) {
        c.push_back('a');
      }
      for (int i = a; i < a + b; i++) {
        c.push_back('a');
      }
      vector<int> ans;
      while (next_permutation(c.begin(), c.end())) {
        int ans1 = 0, ans2 = 0;
        for (int i = 0; i < c.length(); i++) {
          ans1 += c[i] != (i % 2 ? 'a' : 'b');
          ans2 += c[i] != ((i + 1) % 2 ? 'a' : 'b');
        }
        if (!has[ans1]) {
          has[ans1] = 1;
          ans.push_back(ans1);
        }
        if (!has[ans2]) {
          has[ans2] = 1;
          ans.push_back(ans2);
        }
        sort(ans.begin(), ans.end());
        cout << ans.size() << endl;
        for (int i = 0; i < ans.size(); i++) {
          cout << ans[i] << ' ';
        }
        cout << endl;
      }
    }
  }
  return 0;
}
