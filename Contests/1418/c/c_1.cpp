#include <cstring>
#include <iostream>
using namespace std;
const int MAXN = 2E4 + 10;

enum { FRIEND = 1, ME = 0 };

int n;

int a[MAXN];

int f[MAXN][2];

int main() {
  int t;
  cin >> t;
  while (t--) {
    memset(f, 0x3f3f3f3f, sizeof(f));
    cin >> n;

    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }

    f[0][ME] = 0;
    f[1][FRIEND] = a[1];
    for (int i = 2; i <= n; i++) {
      f[i][FRIEND] = min(f[i - 1][ME] + a[i], f[i - 2][ME] + a[i - 1] + a[i]);
      f[i][ME] = min(f[i - 1][FRIEND], f[i - 2][FRIEND]);
    }
    cout << min(f[n][FRIEND], f[n][ME]) << endl;
  }
  return 0;
}
