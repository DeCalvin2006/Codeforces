/*
 * Author : AFGXF
 * Date : 2022-06-22 08:19:26
 * */

#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;
const int MAXN = 1E4 + 10;
char s[MAXN];
char aux[MAXN];
int nxtp[MAXN]; // next position;
int n;
void shift(int l, int r, int k) {
  for (int i = l; i <= r; i++) {
    aux[(i - l + k) % (r - l + 1) + l] = s[i];
  }
  for (int i = l; i <= r; i++) {
    s[i] = aux[i];
  }
}
int main() {
  cin >> (s + 1);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int l, r, k;
    cin >> l >> r >> k;
    k %= (r - l + 1);
    shift(l, r, k);
  }
  cout << (s + 1) << endl;
  return 0;
}
