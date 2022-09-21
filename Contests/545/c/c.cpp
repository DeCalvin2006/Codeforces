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
const int N = 1E5 + 10;
int n;
int x[N], h[N];
int dp[N][3];
enum { LEFT = 0, MID = 1, RIGHT = 2 };
int main() {
  n = read();
  for (int i = 1; i <= n; i++) {
    x[i] = read(), h[i] = read();
  }
  dp[1][MID] = 0;
  dp[1][LEFT] = 1;
  if (n > 1 && x[1] + h[1] >= x[2]) {
    dp[1][RIGHT] = 0;
  } else {
    dp[1][RIGHT] = 1;
  }
  for (int i = 2; i <= n; i++) {
    // MID
    dp[i][MID] = max(dp[i - 1][MID], dp[i - 1][LEFT]);
    if (x[i - 1] + h[i - 1] < x[i]) {
      dp[i][MID] = max(dp[i][MID], dp[i - 1][RIGHT]);
    }
    // LEFT
    // Case 1: x[i]-h[i] <= x[i-1]: Ileggal
    if (x[i] - h[i] <= x[i - 1]) {
      dp[i][LEFT] = 0;
    } else {
      // Case 2: x[i]-h[i] > x[i-1];
      dp[i][LEFT] = max(dp[i - 1][LEFT], dp[i - 1][MID]) + 1;
      if (x[i - 1] + h[i - 1] < x[i] - h[i]) {
        // Case 3: x[i]-h[i] > x[i-1]+h[i-1]
        dp[i][LEFT] = max(dp[i][LEFT], dp[i - 1][RIGHT] + 1);
      }
    }
    // RIGHT
    // Case 1: x[i]+h[i]>=x[i+1]: Illegal
    if (i != n && x[i] + h[i] >= x[i + 1]) {
      dp[i][RIGHT] = 0;
    } else {
      // Case 2: x[i]+h[i]<x[i+1]
      dp[i][RIGHT] = max(dp[i - 1][LEFT], dp[i - 1][MID]) + 1;
      if (x[i - 1] + h[i - 1] < x[i]) {
        // Case 3: x[i]-h[i] > x[i-1]+h[i-1]
        dp[i][RIGHT] = max(dp[i][RIGHT], dp[i - 1][RIGHT] + 1);
      }
    }
  }
  cout << max(dp[n][LEFT], max(dp[n][MID], dp[n][RIGHT])) << endl;
  return 0;
}
