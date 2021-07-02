#include <iostream>
#include <cstring>
#include <cassert>
using namespace std;

class MyString{
char *p;
public:
MyString(const char *str=NULL);
MyString(MyString& s);
MyString& operator=(const MyString& s);
char& operator[](int idx);
~MyString();

friend ostream& operator<<(ostream& os, const MyString& s){
os<<s.p;
return os;
}
MyString& operator+=(const MyString& rhs){
int len =size()+rhs.size()+1;
char *new_p=new char[len];
strcpy(new_p,p);
strcat(new_p,rhs.p);
delete[] p;
p=new_p;
return *this;
}
friend MyString operator+(MyString s1, const MyString& s2){
s1+=s2; return s1;
}
void print();
int size();
};
MyString::MyString(const char *str){
if(!str){
p=new char[1];
p[0]='\0';
return;
}
p=new char[strlen(str)+1];
strcpy(p,str);
cout<<this<<" "<<str<<"]MyString(const char *)\n";
}
MyString::MyString(MyString& s){
p=new char[s.size()+1];
strcpy(p, s.p);
cout<<this<<" "<<s.p<<"]MyString(const MyString&)\n";
}
MyString& MyString::operator=(const MyString& s){
if(&s != this){
delete[] p;
int len=s.size()+1;
p=new char[len];
strcpy(p,s.p);
}
return *this;
}
char& MyString::operator[](int idx){
assert(0<=idx && idx<size());
return p[idx];
}

MyString::~MyString{delete[] p;}
void MyString::print(){cout<<p<<endl;}
int MyString::size(){return strlen(p);}

int main(){
char word[]="april";
const MyString m1("1st");
MyString m2(word);
MyString m3=m1+m2;
cout<<"m1: "<<m1<<endl;
cout<<"m2: "<<m2<<endl;
cout<<"m3: "<<m3<<endl;
m2[1]=m1[0];
cout<<"m2 "<<m2<<endl;
m2+=m1;
cout<<"m2: "<<m2<<endl;
return 0;
}
