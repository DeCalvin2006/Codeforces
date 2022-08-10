/*
 * Author : AFGXF
 * Date : 2021-12-04 07:47:52
 * */

#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int MAXN = 1E3 + 10;
int n;
bool p[MAXN];
bool check(int x) {
  while (x) {
    if (x % 10 != 7 && x % 10 != 4) {
      return 0;
    }
    x /= 10;
  }
  return 1;
}
void process() {
  for (int i = 1; i <= MAXN; i++) {
    if (p[i] || check(i)) {
      for (int j = 1; j * i <= MAXN; j++) {
        p[i * j] = 1;
      }
    }
  }
}
int main() {
  cin >> n;
  process();
  cout << (p[n] ? "YES" : "NO") << endl;
  return 0;
}
