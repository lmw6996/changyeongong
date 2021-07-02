#include <iostream>
#include <cmath>
using namespace std;

int main(){
int ax,ay,bx,by,cx,cy;
cin>>ax>>ay>>bx>>by>>cx>>cy;
if((sqrt((ax-bx)*(ax-bx)+(ay-by)*(ay-by))>=sqrt((ax-cx)*(ax-cx)+(ay-cy)*(ay-cy))+sqrt((bx-cx)*(bx-cx)+(by-cy)*(by-cy)))||
  (sqrt((ax-cx)*(ax-cx)+(ay-cy)*(ay-cy))>=sqrt((ax-bx)*(ax-bx)+(ay-by)*(ay-by))+sqrt((bx-cx)*(bx-cx)+(by-cy)*(by-cy)))||
  (sqrt((bx-cx)*(bx-cx)+(by-cy)*(by-cy))>=sqrt((ax-bx)*(ax-bx)+(ay-by)*(ay-by))+sqrt((ax-cx)*(ax-cx)+(ay-cy)*(ay-cy))))
  cout<<0<<endl;
else if(((ax-bx)*(ax-bx)+(ay-by)*(ay-by)==(ax-cx)*(ax-cx)+(ay-cy)*(ay-cy)+(bx-cx)*(bx-cx)+(by-cy)*(by-cy))||
  ((ax-cx)*(ax-cx)+(ay-cy)*(ay-cy)==(ax-bx)*(ax-bx)+(ay-by)*(ay-by)+(bx-cx)*(bx-cx)+(by-cy)*(by-cy))||
  ((bx-cx)*(bx-cx)+(by-cy)*(by-cy)==(ax-bx)*(ax-bx)+(ay-by)*(ay-by)+(ax-cx)*(ax-cx)+(ay-cy)*(ay-cy)))
  cout<<1<<endl;
else if(((ax-bx)*(ax-bx)+(ay-by)*(ay-by)>(ax-cx)*(ax-cx)+(ay-cy)*(ay-cy)+(bx-cx)*(bx-cx)+(by-cy)*(by-cy))||
  ((ax-cx)*(ax-cx)+(ay-cy)*(ay-cy)>(ax-bx)*(ax-bx)+(ay-by)*(ay-by)+(bx-cx)*(bx-cx)+(by-cy)*(by-cy))||
  ((bx-cx)*(bx-cx)+(by-cy)*(by-cy)>(ax-bx)*(ax-bx)+(ay-by)*(ay-by)+(ax-cx)*(ax-cx)+(ay-cy)*(ay-cy)))
  cout<<2<<endl;
else if(((ax-bx)*(ax-bx)+(ay-by)*(ay-by)<(ax-cx)*(ax-cx)+(ay-cy)*(ay-cy)+(bx-cx)*(bx-cx)+(by-cy)*(by-cy))||
  ((ax-cx)*(ax-cx)+(ay-cy)*(ay-cy)<(ax-bx)*(ax-bx)+(ay-by)*(ay-by)+(bx-cx)*(bx-cx)+(by-cy)*(by-cy))||
  ((bx-cx)*(bx-cx)+(by-cy)*(by-cy)<(ax-bx)*(ax-bx)+(ay-by)*(ay-by)+(ax-cx)*(ax-cx)+(ay-cy)*(ay-cy)))
  cout<<3<<endl;
return 0;
}
