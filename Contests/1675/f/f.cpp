#include <bits/stdc++.h>
#include <cstring>
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
int head[N], to[N << 1], nxt[N << 1], w[N << 1], ecnt = 0;
void adde_(int a, int b) {
  ecnt++;
  nxt[ecnt] = head[a];
  head[a] = ecnt;
  to[ecnt] = b;
  w[ecnt] = 1;
}
void adde(int a, int b) { adde_(a, b), adde_(b, a); }
int t;
int n, k, x, y;
int a[N];
int dis[N];
bool dfs1(int x, int fa) {
  bool c = x == y;
  for (int i = head[x]; i; i = nxt[i]) {
    int v = to[i];
    if (v != fa) {
      dis[v] = dis[x] + w[i];
      bool tmp = dfs1(v, x);
      if (tmp) {
        c = 1;
        w[i] = 0;
      }
    }
  }
  return c;
}
int ans = 0;
bool has[N];
bool dfs2(int x, int fa) {
  bool in_has = has[x];
  for (int i = head[x]; i; i = nxt[i]) {
    int v = to[i];
    if (v != fa) {
      bool tmp = dfs2(v, x);
      if (tmp) {
        in_has = tmp;
        // clog << x << "=>" << v << endl;
        ans += 2 * w[i];
        w[i] = 0;
      }
    }
  }
  return in_has;
}
int main() {
  t = read();
  while (t--) {
    ans = 0;
    ecnt = 0;
    memset(head, 0, sizeof head);
    memset(has, 0, sizeof has);
    memset(nxt, 0, sizeof nxt);
    n = read(), k = read(), x = read(), y = read();
    for (int i = 1; i <= k; i++) {
      a[i] = read();
      has[a[i]] = 1;
    }
    for (int i = 1; i < n; i++) {
      int a = read(), b = read();
      adde(a, b);
    }
    memset(dis, 0, sizeof dis);
    dfs1(x, 0);
    ans += dis[y];
    dfs2(x, 0);
    cout << ans << endl;
    // clog << endl;
  }
  // TODO: code here
  return 0;
}
