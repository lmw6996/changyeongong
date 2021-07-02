#include <iostream>
using namespace std;

int main(){
    int a,b,n,w;
    cin >> a >> b >> n >> w;

    int cnt = 0;
    int sn, gn;

    for (int i=1;i<n;i++){
        if (a*i + b*(n-i) == w){
            cnt++;
            sn = i;
            gn = n-i;
        }
    }

    if (cnt == 1 )
        cout <<sn<<" "<<gn<<endl;
    else
        cout <<-1<<endl;

    return 0;
}
