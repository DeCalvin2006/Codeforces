#include <iostream>
using namespace std;
int main() {
  char c[100];
  int n;
  int k = 0;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> c;
    if (c[0] == '+' || c[2] == '+')
      k++;
    if (c[0] == '-' || c[2] == '-')
      k--;
  }
  cout << k << endl;
  return 0;
}
