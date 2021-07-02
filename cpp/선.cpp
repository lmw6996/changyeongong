#include <iostream>
using namespace std;

int main(void) {
    int ax1, ay1, ax2, ay2;
    int bx1, by1, bx2, by2;
    int hx1, hy, hx2;
    int vx, vy1, vy2;

    cin >> ax1 >> ay1 >> ax2 >> ay2;
    cin >> bx1 >> by1 >> bx2 >> by2;

    if (ax1 < ax2) { hx1 = ax1; hx2 = ax2; hy = ay2; }
    else if (ax1 > ax2) { hx1 = ax2; hx2 = ax1; hy = ay2; }
    else if (ay1 < ay2) { vy1 = ay1; vy2 = ay2; vx = ax2; }
    else                { vy1 = ay2; vy2 = ay1; vx = ax2; }

    if (bx1 < bx2) { hx1 = bx1; hx2 = bx2; hy = by2; }
    else if (bx1 > bx2) { hx1 = bx2; hx2 = bx1; hy = by2; }
    else if (by1 < by2) { vy1 = by1; vy2 = by2; vx = bx2; }
    else                { vy1 = by2; vy2 = by1; vx = bx2; }

    if ((vx < hx1) || (hx2 < vx)) {  cout << "0\n";  return 0; }
    else if ((hy < vy1) || (vy2 < hy)) {  cout << "0\n";  return 0; }
    else if ((vx == hx1) || (vx == hx2)) {  cout << "2\n";  return 0; }
    else if ((hy == vy1) || (hy == vy2)) {  cout << "2\n";  return 0; }
    else                                 {  cout << "1\n"; return 0;}
}
