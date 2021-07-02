#include <iostream>
using namespace std;

int main(void) {
    int k, *h, i, m2, m3, m5, p2, p3, p5;
    h = new int[1351];
    h[1]=1; i=1;
    m2 = m3 = m5 = 1;
    p2 = 2*h[m2]; p3 = 3*h[m3]; p5 = 5*h[m5];
    cin >> k;
    while (i < k){
      if (p2 < p3){
        if (p2 < p5) { // p2 is the smallest
          if (p2 != h[i]) h[++i] = p2;
          p2 = 2*h[++m2];
        }
        else {      // p5 is the smallest
          if (p5 != h[i]) h[++i] = p5;
          p5 = 5*h[++m5];
        }
      }
      else {
        if (p3 < p5){  // p3 is the smallest
          if (p3 != h[i]) h[++i] = p3;
          p3 = 3*h[++m3];
        }
        else {       // p5 is the smallest
          if (p5 != h[i]) h[++i] = p5;
          p5 = 5*h[++m5];
        }
      }
    }

    cout << h[k] << endl;
    return 0;
}
