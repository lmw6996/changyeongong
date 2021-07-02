#include <iostream>
#include <string>
#include <cctype>

using namespace std;

char ISBNchecksum(string s){
  int checksum = 0;
  for (int i=0; i<9; i++){
    checksum += (s[i]-'0')*(10-i);
  }
  checksum = 11 - (checksum%11);
  switch (checksum) {
    case 11: return '0';
    case 10: return 'X';
    default: return checksum+'0';
  }
}

bool ISBNvalidity(string s){
  size_t pos = 0, pos2;
  int n_parts = 0;
  string parts[3];

  if (s.length() != 13)  return false;

  while ( (pos2 = s.find('-', pos)) != string::npos) {
    if (n_parts == 3) return false;
    if (pos == pos2) return false; // empty subpart
    parts[n_parts++] = s.substr(pos, pos2-pos);

    for (int i=0; i<parts[n_parts-1].length(); i++)
      if (!isdigit(parts[n_parts-1][i])) return false;
    pos = pos2+1;
  }
  if (n_parts < 3) return false;

  if (parts[0].length() > 5) return false;
  if (parts[1].length() > 7) return false;
  if (parts[2].length() > 6) return false;
  
  if ( (pos+1) != s.length()) return false;

  if (ISBNchecksum(parts[0]+parts[1]+parts[2]) == s[12])  return true;
  else                                                    return false;
}

int main(void){
  string s;
  cin >> s;

  if( ISBNvalidity(s) ) cout << 1 << endl;
  else                  cout << 0 << endl;
}
