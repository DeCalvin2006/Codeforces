/*
 * Author : AFGXF
 * Date : 2022-06-27 15:40:04
 * */

#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;
long long n, w;
int main() {
  cin >> n >> w;
  long long mina = 0, maxa = 0;
  long long current = 0, tmp = 0;
  for (int i = 1; i <= n; i++) {
    cin >> tmp;
    current += tmp;
    mina = min(current, mina);
    maxa = max(maxa, current);
  }
  cout << w - maxa + mina + 1 << endl;
  return 0;
}
