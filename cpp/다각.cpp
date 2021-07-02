#include <iostream>
using namespace std;

int sum = 0;
int main(){
    int x[10000];
    int y[10000];
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> x[i] >> y[i];

    x[n] = x[0];
    y[n] = y[0];

    for (int i = 0; i < n; i++)
        sum += ((x[i] * y[i + 1])- (x[i + 1] * y[i]));

  if(sum>0)
  cout<<sum<<" "<<1<<endl;
  if(sum<0)
  cout<<abs(sum)<<" "<<-1<<endl;

  return 0;
}
