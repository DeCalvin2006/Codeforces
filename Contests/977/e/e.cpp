#include <iostream>
using namespace std;
const int MAXN = 2E5 + 10;
const int MAXM = MAXN << 1;

struct Edge {
  int to;
  int next;
} E[MAXM];

int n, m, es, ans;

int head[MAXN], deg[MAXN];

void addEdge(int u, int v) {
  es++;
  E[es].next = head[u];
  head[u] = es;
  E[es].to = v;
}

bool inStack[MAXN], vis[MAXN];

static bool ok;

void dfs(int s) {
  vis[s] = 1;

  if (deg[s] != 2) {
    ok = 0;
  }

  inStack[s] = 1;

  for (int i = head[s]; i; i = E[i].next) {
    int e = E[i].to;
    if (!vis[e]) {
      dfs(e);
    }
  }

  inStack[s] = 0;
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int x, y;
    cin >> x >> y;
    addEdge(x, y);
    addEdge(y, x);
    deg[x]++;
    deg[y]++;
  }
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      ok = 1;
      dfs(i);
      ans += ok;
    }
  }
  cout << ans << endl;
  return 0;
}
