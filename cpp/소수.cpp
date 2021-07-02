#include <iostream>
using namespace std;

int main(){
int i,n;
cin>>n;
for(i=2; i<=n; i++){
   if(n%i==0)break;
 }
if (i==n)
 cout<<1<<endl;
else
cout<<0<<endl;

return 0;
}
