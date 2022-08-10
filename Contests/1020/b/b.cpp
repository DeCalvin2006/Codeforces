#include <cstring>
#include <iostream>
using namespace std;
const int MAXN = 1000 + 50;
int n;
int p[MAXN];
bool inStack[MAXN];
void dfs(int s) {
  if (inStack[s] == 1) {
    cout << s << ' ';
    return;
  }
  inStack[s] = 1;
  dfs(p[s]);
  inStack[s] = 0;
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> p[i];
  }
  for (int i = 1; i <= n; i++) {
    dfs(i);
  }
  cout << endl;
  return 0;
}
