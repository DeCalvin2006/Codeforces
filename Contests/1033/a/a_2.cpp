/*
 * Author : AFGXF
 * Date : 2021-08-25 22:33:13
 * */
#include <iostream>

using namespace std;

const int MAXN = 1E3 + 50;

const int dir[8][2] = {{1, 0}, {0, 1},  {-1, 0}, {0, -1},
                       {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

int n;

int ax, ay, bx, by, cx, cy;

bool vis[MAXN][MAXN];

int qx[MAXN], qy[MAXN], head, tail;

bool ok(int x, int y) {
  return x >= 1 && x <= n && y >= 1 && y <= n && !vis[x][y];
}

bool posOk(int x, int y) {
  return x != ax && y != ay && x + (ay - ax) != y && x + (ay + ax) != y;
}

void bfs(int sx, int sy) {
  head = tail = 0;
  vis[sx][sy] = 1;
  qx[head] = sx, qy[head] = sy;
  tail++;
  while (head != tail) {
    int x = qx[head], y = qy[head];
    head = (head + 1 + MAXN) % MAXN;
    for (int i = 0; i < 8; i++) {
      int tx = x + dir[i][0], ty = y + dir[i][1];
      if (ok(tx, ty) && posOk(tx, ty)) {
        if (tx == cx && ty == cy) {
          cout << "YES" << endl;
          return;
        }
        qx[tail] = tx;
        qy[tail] = ty;
        tail = (tail + 1 + MAXN) % MAXN;
        vis[tx][ty] = 1;
      }
    }
  }
  cout << "NO" << endl;
}

int main() {
  cin >> n;
  cin >> ax >> ay >> bx >> by >> cx >> cy;
  bfs(bx, by);
  return 0;
}
