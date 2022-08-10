#include <iostream>
using namespace std;
const int MAXN = 3E4 + 10;
int n, t;
int a[MAXN];
bool vis[MAXN];

void dfs(int i) {
  vis[i] = 1;
  if (i + a[i] <= n && !vis[i + a[i]]) {
    dfs(i + a[i]);
  }
}

int main() {
  cin >> n >> t;
  for (int i = 1; i < n; i++)
    cin >> a[i];
  dfs(1);
  cout << (vis[t] ? "YES" : "NO") << endl;
  return 0;
}
