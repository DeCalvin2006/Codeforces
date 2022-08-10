#include <iostream>
#include <vector>
using namespace std;
const int MAXN = 1E5 + 10;
typedef long long ll;
ll n, m;
bool value[MAXN];
int head[MAXN], edgeCount = 0;
int ind[MAXN];
struct Edges {
  int to;
  int next;
} edges[MAXN * 2];
void addEdge(int u, int v) {
  edgeCount++;
  edges[edgeCount].next = head[u];
  head[u] = edgeCount;
  edges[edgeCount].to = v;
  ind[v]++;
}

int f[MAXN];
bool vis[MAXN];

int ans = 0;

void dfs(int s, int length, int maxLength) {
  vis[s] = 1;
  if (maxLength > m) {
    return;
  }
  if (ind[s] == 1 && s != 1) {
    ans++;
    return;
  }
  for (int i = head[s]; i; i = edges[i].next) {
    int e = edges[i].to;
    if (!vis[e]) {
      int nextLength = (value[e] ? length + 1 : 0);
      dfs(e, nextLength, max(nextLength, maxLength));
    }
  }
}

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    cin >> value[i];
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    addEdge(u, v);
    addEdge(v, u);
  }
  dfs(1, value[1], value[1]);
  cout << ans << endl;
  return 0;
}
