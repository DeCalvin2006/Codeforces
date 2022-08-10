/*
 * Author : AFGXF
 * Date : 2022-06-22 08:19:26
 * */

#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    long long n;
    cin >> n;
    long long sum = n * (n + 1) / 2;
    int digits = 0;
    while (n) {
      digits++;
      n >>= 1;
    }
    sum -= ((1 << digits) - 1) * 2;
    cout << sum << endl;
  }
  return 0;
}
