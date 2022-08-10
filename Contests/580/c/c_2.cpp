#include <iostream>
#include <vector>
using namespace std;
const int MAXN = 1E5 + 10;
typedef long long ll;
ll n, m;
bool value[MAXN];
vector<ll> child[MAXN];
bool vis[MAXN];
ll dfs(ll s, ll val, ll ma) {
  vis[s] = 1;
  if (ma > m) {
    return 0;
  }
  if (child[s].empty()) {
    return 1;
  }
  ll ans = 0;
  for (vector<ll>::iterator i = child[s].begin(); i != child[s].end(); i++) {
    if (!vis[*i]) {
      ll nval;
      if (value[*i]) {
        nval = val + 1;
      } else {
        nval = 0;
      }
      ans += dfs(*i, nval, max(nval, ma));
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
    child[a].push_back(b);
  }
  cout << dfs(1, value[1], value[1]) << endl;
  return 0;
}
