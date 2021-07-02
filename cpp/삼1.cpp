#include <iostream>
using namespace std;

int main(){
int a;
int b;
int c;
cin>>a>>b>>c;
if((a>=b+c)||(b>=a+c)||(c>=a+b))
cout<<0<<endl;
else if((a==b)&&(b==c))
cout<<1<<endl;
else if((a*a==b*b+c*c)||(b*b==a*a+c*c)||(c*c==a*a+b*b))
cout<<2<<endl;
else if(((a==b)&&(a!=c))||((b==c)&&(a!=b))||((a==c)&&(a!=b)))
cout<<3<<endl;
else
cout<<4<<endl;
return 0;
}
