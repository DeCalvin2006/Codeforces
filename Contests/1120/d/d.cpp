#include <bits/stdc++.h>
#define int long long
using namespace std;
int read() {
  int x = 0, f = 1;
  char c = getchar();
  while (c > '9' || c < '0') {
    if (c == '-')
      f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = (x << 1) + (x << 3) + c - '0';
    c = getchar();
  }
  return x * f;
}
const int N = 2E5 + 10;
int n;
int w[N];
// graph
int head[N], to[N << 1], nxt[N << 1], ecnt;
void adde(int a, int b) {
  ecnt++;
  nxt[ecnt] = head[a];
  head[a] = ecnt;
  to[ecnt] = b;
}
// DSU
int f[N];
int findf(int x) { return f[x] == 0 ? x : f[x] = findf(f[x]); }
// Kruskal;
int leaves[N], //这个节点子树中的叶子节点个数
    id;        // 叶子节点个数
bool selected[N];
struct edge {
  int from, to, w, v;
} es[N << 1];
int necnt;
void inse(int a, int b, int w, int v) {
  necnt++;
  es[necnt] = {a, b, w, v};
}
void kruskal() {
  sort(es + 1, es + 1 + necnt,
       [](const edge &a, const edge &b) { return a.w < b.w; });
  int l = 1;
  int k = 0;
  int mst = 0;
  while (l <= n) {
    int r;
    // 统计重复的边
    for (r = l; r <= n; r++) {
      if (es[r].w != es[r + 1].w)
        break;
    }
    // 因为要求并集，所以都要选上
    for (int i = l; i <= r; i++) {
      if (findf(es[i].from) != findf(es[i].to)) {
        selected[es[i].v] = 1;
        k++;
      }
    }
    // 统计一次边的权值
    for (int i = l; i <= r; i++) {
      int fu = findf(es[i].from);
      int fv = findf(es[i].to);
      if (fu == fv)
        continue;
      mst += es[i].w;
      f[fu] = fv;
    }
    l = r + 1;
  }
  // 输出
  cout << mst << ' ' << k << endl;
  for (int i = 1; i <= n; i++) {
    if (selected[i])
      cout << i << ' ';
  }
  cout << endl;
}
void dfs1(int x, int fa) {
  bool vis = 0; // 有儿子，不是叶子节点
  for (int i = head[x]; i; i = nxt[i]) {
    int v = to[i];
    if (v != fa) {
      dfs1(v, x);
      vis = 1;
      leaves[x] += leaves[v];
    }
  }
  if (!vis) { // 是叶子节点
    id++;
    leaves[x] = 1;
  }
}
void dfs2(int x, int fa, int l) {
  // clog << l << "==>" << l + leaves[x] << ", w=" << w[x] << ", node " << x
  // << endl;

  // 统计子树
  inse(l, l + leaves[x], w[x], x);
  for (int i = head[x]; i; i = nxt[i]) {
    int v = to[i];
    if (v != fa) {
      dfs2(v, x, l);
      l += leaves[v];
    }
  }
}
signed main() {
  n = read();
  for (int i = 1; i <= n; i++) {
    cin >> w[i];
  }
  for (int i = 1; i < n; i++) {
    int a = read(), b = read();
    adde(a, b);
    adde(b, a);
  }
  dfs1(1, 0);
  dfs2(1, 0, 1);
  kruskal();
  return 0;
}
