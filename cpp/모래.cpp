#include <iostream>
using namespace std;

int main(){
 int k;
 do{
   cin>>k;
 }while((k<3||k>99)||(k%2==0));

 int i;
 int j;
 int l;

 for(i=0; i<(k/2);i++){
 for(j=0; j<i;j++){
 cout<<"-";
 }
 for(l=k/2; l>i; l--){
 cout<<"*+";
 }
 cout<<"*";
 for(j=0;j<i;j++){
 cout<<"-";
 }
 cout<<endl;
 }
 for(i=0;i<=k/2;i++){
 for(j=k/2;j>i;j--){
 cout<<"-";
 }
 cout<<"*";
 for(l=0;l<i;l++){
 cout<<"+*";
 }
 for(j=k/2;j>i;j--){
 cout<<"-";
 }
 cout<<endl;
 }
 return 0;
}
