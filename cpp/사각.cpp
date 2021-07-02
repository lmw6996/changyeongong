#include <iostream>
using namespace std;

int main(){
int x1,y1,x2,y2,a,b;
cin>>x1>>y1>>x2>>y2;
cin>>a>>b;
if((a<x1)&&(y2>=b)&&(b>=y1))
cout<<(x1-a)*(x1-a)<<" "<<x1-a<<endl;
else if((a>x2)&&(y2>=b)&&(b>=y1))
cout<<(a-x2)*(a-x2)<<" "<<a-x2<<endl;
else if((b>y2)&&(a>=x1)&&(x2>=a))
cout<<(b-y2)*(b-y2)<<" "<<b-y2<<endl;
else if((b<y1)&&(a>=x1)&&(x2>=a))
cout<<(y1-b)*(y1-b)<<" "<<y1-b<<endl;
else if((a<x1)&&(b<y1))
cout<<(x1-a)*(x1-a)+(y1-b)*(y1-b)<<" "<<(x1-a)+(y1-b)<<endl;
else if((a<x1)&&(b>y2))
cout<<(x1-a)*(x1-a)+(b-y2)*(b-y2)<<" "<<(x1-a)+(b-y2)<<endl;
else if((a>x2)&&(b>y2))
cout<<(a-x2)*(a-x2)+(b-y2)*(b-y2)<<" "<<(a-x2)+(b-y2)<<endl;
else if((a>x2)&&(b<y1))
cout<<(a-x2)*(a-x2)+(y1-b)*(y1-b)<<" "<<(a-x2)+(y1-b)<<endl;
else
cout<<0<<" "<<0<<endl;
return 0;
}
