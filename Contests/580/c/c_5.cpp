#include <iostream>
#include <vector>
using namespace std;
const int MAXN = 1E1 + 10;
int n, m;
bool value[MAXN];
int f[MAXN];
vector<int> child[MAXN];

int dfs(int s, int val) {
  if (val > m)
    return 0;
  if (child[s].empty() && val <= m) {
    return 1;
  }
  int ans = 0;
  for (vector<int>::iterator i = child[s].begin(); i != child[s].end(); i++) {
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
