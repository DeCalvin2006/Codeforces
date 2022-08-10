#include <iostream>
#include <vector>
using namespace std;
const int MAXN = 1E5 + 10;
int n, m;
int value[MAXN];
int cnt;
vector<int> child[MAXN];

void dfs(int s, int val) {
  if (val > m)
    return;
  if (child[s].empty() && val <= m) {
    cnt++;
    return;
  }
  for (vector<int>::iterator i = child[s].begin(); i != child[s].end(); i++) {
    dfs(*i, (value[*i] ? val + 1 : 0));
  }
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
  dfs(1, value[1]);
  cout << cnt << endl;
  return 0;
}
