#include <iostream>
#include <string>
using namespace std;

int main(){

		string s;
		cin >> s;
		int count = 0;
		for (int i = 0; i < s.length() && count >= 0; i++){
			if (s[i] == '(') count++;
			else count--;
		}

		if (count ==0)
		cout << 1 << endl;
		else
		cout << 0 << endl;

	return 0;
}
