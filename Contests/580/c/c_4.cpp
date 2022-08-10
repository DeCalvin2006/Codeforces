#include <iostream>
#include <vector>
using namespace std;
const int MAXN = 1E5 + 10;
typedef unsigned long long ull;
ull n, m;
bool value[MAXN];
ull f[MAXN];
vector<ull> child[MAXN];

ull dfs(ull s, ull val) {
  if (val > m) {
    cout << s << endl;
    return 0;
  }
  if (child[s].empty()) {
    return 1;
  }
  ull ans = 0;
  for (vector<ull>::iterator i = child[s].begin(); i != child[s].end(); i++) {
    ans += dfs(*i, (value[*i] ? val + 1 : 0));
  }
  return ans;
}

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> value[i];
  }
  for (int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    child[a].push_back(b);
  }
  cout << dfs(1, value[1]) << endl;
  return 0;
}
