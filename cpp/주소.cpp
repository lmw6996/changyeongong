#include <iostream>
#include <string>
using namespace std;

unsigned toValue(string address){
  unsigned value = 0;
  size_t pos = 0, pos2;
  for (int i=0; i<3; i++){
    pos2 = address.find ('.', pos);
    value += (unsigned)stoi( address.substr(pos, pos2-pos));
    pos = pos2+1;
    value <<= 8;
  }
  value += stoi( address.substr(pos));
  return value;
}

string toIPv4(unsigned value){
  string address;
  unsigned t, mask = 0xff000000;
  for (int i=0; i<4; i++){
    t = value & mask;
    value <<= 8;
    t >>= 24;
    address += to_string(t);
    if (i<3) address += ".";
  }
  return address;
}

int main( void ){
  int mode;
  string address;
  unsigned value;

  cin >> mode;
  if (mode == 1){
    cin >> address;
    cout << toValue(address) << endl;
  }
  else {
    cin >> value;
    cout << toIPv4(value) << endl;
  }
}
