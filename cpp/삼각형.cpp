#include <iostream>
using namespace std;

int main(){
int k;
int i;
int j;
do{
  cin>>k;
}while(1>k||k>99);
int num=1;
for(i=0; i<k; i++){
  for(j=0; j<i+1; j++){
   cout<<num<<" ";
   num+=1;
  }
  cout<<endl;
 }
return 0;
}
