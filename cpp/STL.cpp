#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <functional>
using namespace std;

template <class T1, class T2>
ostream& operator<<(ostream& os, const pair<T1, T2>& p){
os<<"["<<p.first<<"]"<<p.second;
return os;
}
template <class T>
void print_container(const T& container, string s=""){
cout<<s<<"("<<container.size()<<")";
auto it=container.begin();
for(; it !=container.end(); it++) cout<< *it<<" ";
cout<<endl;
}

int main(){
char a[10]={'c','a','x','a','c','b','x','c','b','y'};
print_container(v, "v= ");
print_container(dq, "dq= ");
print_container(li, "li= ");
print_container(s, "s= ");
print_container(ss, "ss= ");
print_container(m, "m= ");
print_container(mm, "mm= ");
return 0;
}
