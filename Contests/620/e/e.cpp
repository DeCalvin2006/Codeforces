#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll read() {
  ll x = 0, f = 1;
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
const ll N = 4E5 + 10;
ll n, m;
ll head[N], to[N << 1], nxt[N << 1], ecnt;
void adde(ll a, ll b) {
  ecnt++;
  nxt[ecnt] = head[a];
  head[a] = ecnt;
  to[ecnt] = b;
}
ll c[N];
ll dfn[N], id[N], siz[N], dcnt;
void dfs(ll x, ll fa) {
  dcnt++;
  siz[x] = 1;
  dfn[x] = dcnt;
  id[dcnt] = x;
  for (ll i = head[x]; i; i = nxt[i]) {
    ll v = to[i];
    if (v != fa)
      dfs(v, x), siz[x] += siz[v];
  }
}
ll t[N << 2], tag[N << 2];
inline ll lc(ll x) { return x << 1; }
inline ll rc(ll x) { return x << 1 | 1; }
inline ll mp(ll l, ll r) { return (l + r) >> 1; }
inline void pushUp(ll x) { t[x] = t[lc(x)] | t[rc(x)]; }
inline void pushDown(ll x) {
  if (tag[x]) {
    t[lc(x)] = tag[lc(x)] = tag[x];
    t[rc(x)] = tag[rc(x)] = tag[x];
    tag[x] = 0;
  }
}

void build(ll l, ll r, ll x) {
  if (l == r) {
    t[x] = 1ll << (c[id[l]] - 1);
  } else {
    ll mid = mp(l, r);
    build(l, mid, lc(x));
    build(mid + 1, r, rc(x));
    pushUp(x);
  }
}

void update(ll L, ll R, ll val, ll l = 1, ll r = n, ll x = 1) {
  if (L <= l && r <= R) {
    t[x] = val;
    tag[x] = val;
  } else {
    pushDown(x);
    ll mid = mp(l, r);
    if (L <= mid)
      update(L, R, val, l, mid, lc(x));
    if (R > mid)
      update(L, R, val, mid + 1, r, rc(x));
    pushUp(x);
  }
}

ll query(ll L, ll R, ll l = 1, ll r = n, ll x = 1) {
  if (L <= l && r <= R) {
    return t[x];
  }
  pushDown(x);
  ll mid = mp(l, r);
  ll ans = 0;
  if (L <= mid)
    ans |= query(L, R, l, mid, lc(x));
  if (R > mid)
    ans |= query(L, R, mid + 1, r, rc(x));
  return ans;
}

int main() {
  n = read(), m = read();
  for (ll i = 1; i <= n; i++) {
    c[i] = read();
  }
  for (ll i = 1; i < n; i++) {
    ll u = read(), v = read();
    adde(u, v), adde(v, u);
  }
  dfs(1, 0);
  build(1, n, 1);
  for (ll i = 1; i <= m; i++) {
    ll type = read();
    if (type == 1) {
      ll a = read(), targ = read();
      update(dfn[a], dfn[a] + siz[a] - 1, 1ll << (targ - 1));
    } else {
      ll a = read();
      cout << __builtin_popcountll(query(dfn[a], dfn[a] + siz[a] - 1)) << endl;
    }
  }
  return 0;
}
