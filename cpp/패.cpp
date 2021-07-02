#include <iostream>
using namespace std;
int main()
{
    int decimal;
    int binary[50];
    int a[50];
    int count=0;
    cin>>decimal;
    int decimal2=decimal;
    int position = 0;
    while (1)
    {
        binary[position] = decimal2 % 2;
        decimal2 = decimal2 / 2;

        position++;

        if (decimal2 == 0)
            break;
    }

    for (int i = 0; i<position; i++)
    {
      if(binary[i]==1){
        count++;
      }
    }
    if (count%2==0){
      cout<<decimal<<endl;
    }
    else if(count%2!=0){
      cout<<decimal+2147483648<<endl;
    }
    return 0;
}
