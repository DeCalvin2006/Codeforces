/*
 * Author : AFGXF
 * Date : 2021-12-11 18:05:16
 * */

#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int MAX = 1E5;
const int MAXN = 1E4 + 1;
int t, n;
int primes[MAXN], top = 0;
bool p[MAX];
void print() {
  for (int i = 1; i <= n; i++) {
    cout << primes[i] << ' ';
  }
  cout << endl;
}
void linear() {
  for (long long i = 2; top < MAXN; i++) {
    if (!p[i]) {
      top++;
      primes[top] = i;
    }
    for (int j = 1; j <= top; j++) {
      if (primes[j] * i >= MAX) {
        break;
      }
      p[primes[j] * i] = 1;
      if (i % primes[j] == 0) {
        break;
      }
    }
  }
}
int main() {
  linear();
  cin >> t;
  while (t--) {
    cin >> n;
    if (n == 1) {
      cout << 1 << endl;
    } else {
      print();
    }
  }
  return 0;
}
