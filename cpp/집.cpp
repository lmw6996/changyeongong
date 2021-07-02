#include <iostream>
#include <bitset>
using namespace std;
void print(bitset<100>& s){
  int n = s.count();
  cout << n << " ";
  for (int i=0; i<100; i++)
    if (s[i]) cout << i+1 << " ";
  cout << endl;
}
int main(void) {
  bitset<100> a,b,u,p,d;
  int n,v;
  cin >> n;
  for (int i=0; i<n; i++){
    cin >> v;
    a.set(v-1);
  }
  cin >> n;
  for (int i=0; i<n; i++){
    cin >> v;
    b.set(v-1);
  }
  u = a|b;
  p = a&b;
  d = a&(~b);
  print(p);
  print(u);
  print(d);

  return 0;
}
