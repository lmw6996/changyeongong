#include <iostream>
#include <vector>
using namespace std;

int main(){
   int n,k;
   vector<int> v1;
   cin>>n;
   cin>>k;
   for(int i=0; i<n; i++){
     int input;
     cin>>input;
     v1.push_back(input);
   }

     for(int i=0; i<k; i++){
     vector<int> v2=v1;

     for (int j=0; j<n; j++){
       if (j==0){
        if(v2[1]<3 || v2[1]>7){
          if(v2[0]==0){
           v1[0]==0;
          }
         else
         v1[0]--;
        }
        if(v2[1]>=4 && v2[1]<=7){
          if(v2[0]==9){
            v1[0]==9;
          }
          else
          v1[0]++;
        }
       }
       if(j>=1&&j<=n-2){
       if (v2[j-1]+v2[j+1]<3 || v2[j-1]+v2[j+1]>7){
         if (v2[j]==0){
          v1[j]==0;
         }
         else
         v1[j]--;
      }
       if(v2[j-1]+v2[j+1]>=4 && v2[j-1]+v2[j+1]<=7){
         if(v2[j]==9){
           v1[j]==9;
         }
         else
         v1[j]++;
        }
       }
       if(j==n-1){
       if (v2[n-2]<3 || v2[n-2]>7){
         if (v2[n-1]==0){
          v1[n-1]==0;
         }
         else
         v1[n-1]--;
      }
       if(v2[n-2]>=4 && v2[n-2]<=7){
         if(v2[n-1]==9){
           v1[n-1]==9;
         }
         else
         v1[n-1]++;
        }
       }
     }
   }
   for(int i=0; i<n; i++){
     cout<<v1[i]<<" ";
   }
   cout<<endl;
  return 0;
}
