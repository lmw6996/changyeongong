#include <iostream>
using namespace std;

int main(){
int ax,ay,bx,by,cx,cy;
int area,sarea;
cin>>ax>>ay>>bx>>by>>cx>>cy;
sarea=((bx-ax)*(cy-ay)-(cx-ax)*(by-ay));
area=abs(((bx-ax)*(cy-ay)-(cx-ax)*(by-ay)));
if(sarea>0)
cout<<area<<" "<<1<<endl;
else if(sarea<0)
cout<<area<<" "<<-1<<endl;
else
cout<<area<<" "<<0<<endl;
return 0;
}
