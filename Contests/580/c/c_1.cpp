#include <iostream>
#include <vector>
using namespace std;
const int MAXN = 1E5 + 10;
typedef long long ll;
ll n, m;
bool value[MAXN];
vector<ll> edge[MAXN];
bool vis[MAXN];
ll dfs(ll s, ll val, ll ma) {
  vis[s] = 1;
  if (edge[s].empty() && ma <= m) {
    return 1;
  }
  ll ans = 0;
  for (int i = 0; i < edge[s].size(); i++) {
    if (!vis[edge[s][i]]) {
      ll nval;
      if (value[edge[s][i]]) {
        nval = val + 1;
      } else {
        nval = 0;
      }
      ans += dfs(edge[s][i], nval, max(nval, ma));
    }
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
    edge[a].push_back(b);
    edge[b].push_back(a);
  }
  cout << dfs(1, value[1], value[1]) << endl;
  return 0;
}
