/*
 * Author : AFGXF
 * Date : 2022-07-13 19:20:15
 * */

#include <bits/stdc++.h>
using namespace std;
const int N = 1.5E5 + 10;
const int M = N << 2;
int n, m;
int head[N], to[M], nxt[M], ecnt = 0;
void adde_aux(int a, int b) {
  ecnt++;
  nxt[ecnt] = head[a];
  head[a] = ecnt;
  to[ecnt] = b;
}
void adde(int a, int b) { adde_aux(a, b), adde_aux(b, a); }
vector<int> p[N];
int g[N];
bool vis[N];
int cnt = 0;
void dfs(int x, int fa) {
  p[cnt].push_back(x);
  g[x] = cnt;
  vis[x] = 1;
  for (int i = head[x]; i; i = nxt[i]) {
    int v = to[i];
    if (!vis[v] && v != fa) {
      dfs(v, x);
    }
  }
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int a, b;
    cin >> a >> b;
    adde(a, b);
  }
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      cnt++;
      dfs(i, 0);
    }
  }
  for (int i = 1; i <= cnt; i++) {
    int cnt = 0;
    for (int j = head[p[i][0]]; j; j = nxt[j]) {
      if (g[to[j]] == i) {
        cnt++;
      }
    }
    if (cnt < p[i].size() - 1) {
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
  return 0;
}
