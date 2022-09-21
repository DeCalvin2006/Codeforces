#include <bits/stdc++.h>
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
int state[100 + 10];
int dp[100 + 10][3][3];
int dfs(int x, int sports, int contest) {
  if (x == 0)
    return 0;
  if (dp[x][sports][contest] != -1) {
    return dp[x][sports][contest];
  } else {
    int ans = 0x3f3f3f3f;
    switch (state[x]) {
    case 0: {
      ans = dfs(x - 1, 0, 0) + 1;
      break;
    }
    case 1: {
      if (contest < 1) {
        ans = min(dfs(x - 1, 0, 0) + 1, dfs(x - 1, 0, 1));
      } else {
        ans = dfs(x - 1, 0, 0) + 1;
      }
      break;
    }
    case 2: {
      if (sports < 1)
        ans = min(dfs(x - 1, 0, 0) + 1, dfs(x - 1, 1, 0));
      else {
        ans = dfs(x - 1, 0, 0) + 1;
      }
      break;
    }
    case 3: {
      if (sports < 1)
        ans = min(ans, dfs(x - 1, 1, 0));
      if (contest < 1) {
        ans = min(ans, dfs(x - 1, 0, 1));
      }
      ans = min(ans, dfs(x - 1, 0, 0) + 1);
      break;
    }
    }
    return dp[x][sports][contest] = ans;
  }
}
int main() {
  // TODO: code here
  n = read();
  for (int i = 1; i <= n; i++) {
    state[i] = read();
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < 3; j++) {
      for (int k = 0; k < 3; k++) {
        dp[i][j][k] = -1;
      }
    }
  }
  cout << dfs(n, 0, 0) << endl;
  return 0;
}
