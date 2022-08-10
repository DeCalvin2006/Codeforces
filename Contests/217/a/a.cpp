/*
 * Author : AFGXF
 * Date : 2021-12-04 10:35:44
 * */

#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int MAXN = 2000 + 10;
int head[MAXN], nxt[MAXN], to[MAXN];
bool vis[MAXN];
int cnt;
void adde(int u, int v) {
  cnt++;
  to[cnt] = v;
  nxt[cnt] = head[u];
  head[u] = cnt;
}
int n;
int row[MAXN], col[MAXN], nodes[MAXN], ncnt = 0;
void dfs(int x) {
  vis[x] = 1;
  for (int i = head[x]; i; i = nxt[i]) {
    if (!vis[to[i]]) {
      dfs(to[i]);
    }
  }
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int u, v;
    cin >> u >> v;
    if (row[u] == 0) {
      ncnt++;
      row[u] = ncnt;
      nodes[ncnt] = u;
    }
    if (col[v] == 0) {
      ncnt++;
      col[v] = ncnt;
      nodes[ncnt] = v;
    }
    adde(row[u], col[v]);
    adde(col[v], row[u]);
  }
  int ans = 0;
  for (int i = 1; i <= ncnt; i++) {
    if (!vis[i]) {
      dfs(i);
      ans++;
    }
  }
  cout << ans - 1 << endl;
  return 0;
}
