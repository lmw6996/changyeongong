#include <iostream>
using namespace std;

int main(){
int k;
cin>>k;
int i;
int j;
for(i=0; i<k/2; i++){
 for(j=0; j<k/2; j++){
 cout<<".";
 }
 cout<<"I";
 for(j=k/2-1;j>i;j--){
 cout<<".";
 }
 cout<<"*";
 for(j=0;j<i;j++){
 cout<<".";
 }
 cout<<endl;
}
for(i=0; i<1; i++){
  for(j=0; j<k/2; j++){
    cout<<"+";
  }
  cout<<"O";
  for(j=0; j<k/2; j++){
    cout<<"+";
 }
 cout<<endl;
}
for(i=0; i<k/2; i++){
  for(j=k/2-1;j>i;j--){
  cout<<".";
  }
  cout<<"*";
  for(j=0;j<i;j++){
  cout<<".";
  }
 cout<<"I";
 for(j=0; j<k/2; j++){
 cout<<".";
 }
 cout<<endl;
}
return 0;
}
