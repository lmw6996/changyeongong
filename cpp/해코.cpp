#include <iostream>
#include <bitset>
#include <string>
using namespace std;

int HammingWeight(unsigned num){
    int weight = 0;
    while (num){
        if (num & 0x01)
            weight++;
        num >>= 1;
    }
    return weight;
}

unsigned EvenParity(unsigned v, int log_pos){
    unsigned encoding_mask[5] = {
      0x02AAAD5B,   // 10 1010 1010 1010 1101 0101 1011
      0x0333366D,   // 11 0011 0011 0011 0110 0110 1101
      0x03C3C78E,   // 11 1100 0011 1100 0111 1000 1110
      0x03FC07F0,   // 11 1111 1100 0000 0111 1111 0000
      0x03FFF800 }; // 11 1111 1111 1111 1000 0000 0000
    unsigned parity;
    parity = HammingWeight(v & encoding_mask[log_pos]) % 2;
    return parity;
}

unsigned  Hencode(unsigned v){
  unsigned code, tmp;

  code = (v >> 11);
  tmp = v & 0x000007ff; // lower 11(=7+3+1) bits
  code = (code << 1) | EvenParity(v,4);

  code = (code << 7) | (tmp >> 4);
  tmp = v & 0x0000000f; // lower 3+1 bits
  code = (code << 1) | EvenParity(v,3);

  code = (code << 3) | (tmp >> 1);
  tmp = v & 0x00000001; // lower 1 bit
  code = (code << 1) | EvenParity(v,2);

  code = (code << 1) | tmp;
  code = (code << 1) | EvenParity(v,1);

  code = (code << 1) | EvenParity(v,0);
  return code;
}

unsigned Hdecode(bitset<32> v){
  bitset<32> parity_masks[5] = { 0x55555555, 0x66666666, 0x78787878, 0x7f807f80, 0x7fff8000 };
  int uniq_error = 0, parity_pos =1;

  for (int i=0; i<5; i++, parity_pos*=2){
    bitset<32> t = parity_masks[i] & v;
    int p = t.count() % 2;
    if (p) {
      uniq_error += parity_pos;
    }
  }
  if (uniq_error){
    v.flip(uniq_error-1);  // negate this position 
  }

  bitset<32> code;
  int k=0;
  for (int i=1; i<=32; i++){
    if (i==1) continue;
    if (i==2) continue;
    if (i==4) continue;  
    if (i==8) continue;
    if (i==16) continue;

    code[k++] = v[i-1];
  }
  return code.to_ulong();
}

int main(void){
  int mode;
  unsigned value;

  cin >> mode >> value;
  if (mode == 0)
    cout << Hencode(value) << endl;
  else
    cout << Hdecode(value) << endl;
}
