#include <bits/stdc++.h>
#include <random>
using namespace std;
int read() {
  int x = 0, f = 1;
  char c = getchar();
  while (c > '9' || c < '0') {
    if (c == '-')
      f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = (x << 1) + (x << 3) + c - '0';
    c = getchar();
  }
  return x * f;
}
int n;
char buf[2000000 + 10];
char otherchar(int x) {
  mt19937 mt((random_device{})());
  uniform_int_distribution<char> u('a', 'z');
  char c = u(mt);
  while (c == buf[x - 1] || c == buf[x + 1]) {
    c = u(mt);
  }
  return c;
}
int main() {
  cin >> (buf + 1);
  n = strlen(buf + 1);
  for (int i = 1; i <= n; i++) {
    if (buf[i] == buf[i - 1]) {
      buf[i] = otherchar(i);
    }
  }
  cout << buf + 1 << endl;
  return 0;
}
