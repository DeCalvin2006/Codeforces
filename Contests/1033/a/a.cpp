/*
 * Author : AFGXF
 * Date : 2021-08-25 22:33:13
 * */
#include <iostream>

using namespace std;

int n;

int ax, ay, bx, by, cx, cy;

int main() {
  cin >> n;
  cin >> ax >> ay >> bx >> by >> cx >> cy;
  if (((bx < ax && by < ay) && (cx < ax && cy < ay)) ||
      ((bx < ax && by > ay) && (cx < ax && cy > ay)) ||
      ((bx > ax && by < ay) && (cx > ax && cy < ay)) ||
      ((bx > ax && by > ay) && (cx > ax && cy > ay)))
    cout << "YES" << endl;
  else
    cout << "NO" << endl;

  return 0;
}
