#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(int argc, char *argv[]){
 if(argc != 2){
 cout<<"usage: ./dice n\n";
 return -1;
 }
 int i=0;
 int n = atoi(argv[1]);
 srand(n);
 for(i=0; i<10; i++){
 cout<<rand()%6+1<<" ";
 }
 cout<<endl;
 return 0;
}
