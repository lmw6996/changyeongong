#include <iostream>
using namespace std;
int main()
{
    int decimal1;
    int decimal2;
    int binary1[50];
    int binary2[50];
    int count1=0;
    int count2=0;
    int count3=0;
    cin>>decimal1;
    cin>>decimal2;


       for(int i=0; i<32; i++){
        binary1[i] = decimal1 % 2;
        decimal1 = decimal1 / 2;
    }

    for (int i = 0; i<32; i++)
    {
         if(binary1[i]==1){
           count1++;
         }
       }
          for(int i=0; i<32; i++){
           binary2[i] = decimal2 % 2;
           decimal2 = decimal2 / 2;
       }

       for (int i = 0; i<32; i++)
       {
            if(binary2[i]==1){
              count2++;
            }
          }
      for (int i=0; i<32; i++){
        if (binary1[i]!=binary2[i])
        count3++;
      }

      cout<<count1<<" "<<count2<<" "<<count3<<endl;
    }
