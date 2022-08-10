#include <iostream>
using namespace std;
long pool[1000];
int main() {
  int n, k;
  cin >> n >> k;
  int a;
  for (int i = 1; i <= n; i++) {
    cin >> a;
    pool[a]++;
  }
  int rnk = 0;
  for (int i = 120; i > 0; i--) {
    rnk += pool[i];
    if (rnk >= k)
      break;
  }
  cout << rnk << endl;
  return 0;
}
