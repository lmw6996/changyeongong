#include <iostream>
using namespace std;

int main(){
 int a,b;
 do{
   cin>>a>>b;
 } while((a<1||a>10000)||(b<1||b>10000));

 cout<<a+b<<" "<<a-b<<" "<<abs(a-b)<<" "<<a*b<<" ";
 cout<<a/b<<" "<<a%b<<" ";
 if(a>=b)
  cout<<a<<" ";
 else
  cout<<b<<" ";
 if(a==b)
  cout<<1<<" ";
 else
  cout<<0<<"\n";
 return 0;
}
