/*
 * Author : AFGXF
 * Date : 2022-07-14 16:41:57
 * */

#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0, f = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-')
      f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = (x << 1) + (x << 3) + c - '0';
    c = getchar();
  }
  return f * x;
}
const long long N = 2E5 + 10;
const long long INF = 1E17 + 7;
// Graph (Forward List)
long long head[N], to[N], nxt[N], val[N], ecnt = 0;
void adde(long long a, int b, int c) {
  ecnt++;
  nxt[ecnt] = head[a];
  head[a] = ecnt;
  to[ecnt] = b;
  val[ecnt] = c;
}
// DSU
long long f[N];
long long findf(int x) { return f[x] == x ? x : f[x] = findf(f[x]); }
// Data
long long prtl[N];
long long n, m, p;
long long dis[N];
bool vis[N];
// Dijkstra
struct elem {
  long long x, dis;
};
priority_queue<elem> pq;
long long fa[N]; // Closest Portal
bool operator<(const elem &a, const elem &b) { return a.dis < b.dis; }
void dij() {
  for (long long i = 1; i <= n; i++) {
    dis[i] = INF;
    vis[i] = 0;
    fa[i] = i;
    f[i] = i;
  }
  for (long long i = 1; i <= p; i++) {
    dis[prtl[i]] = 0;
    pq.push(elem{i, 0});
  }
  while (!pq.empty()) {
    auto t = pq.top();
    pq.pop();
    while (!pq.empty() && vis[t.x]) {
      t = pq.top();
      pq.pop();
    }
    long long u = t.x;
    vis[u] = 1;
    for (long long i = head[u]; i; i = nxt[i]) {
      long long v = to[i];
      if (dis[v] > dis[u] + val[i]) {
        dis[v] = dis[u] + val[i];
        fa[v] = fa[u];
        pq.push(elem{v, dis[v]});
      }
    }
  }
}
// graph for Kruskal
struct edge {
  long long from, to, val;
} es[N];
signed main() {
  n = read(), m = read();
  for (long long i = 1; i <= m; i++) {
    long long a = read(), b = read(), c = read();
    adde(a, b, c);
    adde(b, a, c);
    es[i] = edge{a, b, c};
  }
  p = 1;
  prtl[1] = 1;
  dij();
  long long ans = 1E18 + 7;
  p = read();
  for (long long i = 1; i <= p; i++) {
    prtl[i] = read();
    ans = min(ans, dis[prtl[i]]);
  }
  dij();
  for (long long i = 1; i <= m; i++) {
    es[i].val += dis[es[i].from] + dis[es[i].to];
    es[i].from = fa[es[i].from];
    es[i].to = fa[es[i].to];
    // cout << es[i].from << ' ' << es[i].to << ' ' << es[i].val << endl;
  }
  // cout << endl;
  sort(es + 1, es + 1 + m, [](edge a, edge b) { return a.val < b.val; });
  for (long long i = 1; i <= m; i++) {
    long long a = findf(es[i].from), b = findf(es[i].to);
    if (a != b) {
      // cout << es[i].from << ' ' << es[i].to << ' ' << es[i].val << endl;
      f[a] = b;
      ans += es[i].val;
    }
  }
  cout << ans << endl;
  return 0;
}
