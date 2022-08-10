/*
 * Author : AFGXF
 * Date : 2022-06-27 15:40:04
 * */

#include <algorithm>
#include <cstring>
#include <iostream>
#include <stack>
#include <string>
using namespace std;
const int MAXN = 500 + 10;
int a[MAXN];
stack<int> st;
bool has[10000];
int n;
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = n; i >= 1; i--) {
    if (!has[a[i]]) {
      has[a[i]] = 1;
      st.push(a[i]);
    }
  }
  cout << st.size() << endl;
  while (!st.empty()) {
    cout << st.top() << ' ';
    st.pop();
  }
  cout << endl;
  return 0;
}
