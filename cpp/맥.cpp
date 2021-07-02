#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
int n;
cin >> n;
vector<int> v;
for (int i = 0; i < n; i++) {
int input;
cin >> input;
 v.push_back(input);
 }
 sort(v.begin(), v.end());
 int result = max(v[n - 1] * v[n - 2], v[n - 1] * v[n - 2] * v[n - 3]);
 if (v[0] * v[1] > 0) {
  result = max(v[0] * v[1], result);
  result = max(v[0] * v[1] * v[n - 1], result);
   }
   cout << result<<endl;
   return 0;
}
