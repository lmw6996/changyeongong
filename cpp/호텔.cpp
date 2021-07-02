#include <iostream>
using namespace std;

int main(){
int H,W,N,num,floor;
cin>>H>>W>>N;
num=(N-1)/H;
floor=N-num*H;
cout<<1+num+100*floor<<endl;
return 0;
}
