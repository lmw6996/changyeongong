#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

bool checkCardNumberLength(string s){
    int len = s.length();
    switch (s[0]){
    case '3':
        if (len == 14) return true;
        if (len == 15) return true;
        break;
    case '6':
    case '5':
        if (len == 16) return true;
        break;
    case '4':
        if (len == 13) return true;
        if (len == 16) return true;
    }
    return false;
}

bool isCheckSumValid(string s){
    int length = s.length();
    int sum = 0;

    for (int i=1; i<length; i++){
        int digit = s[length-i-1] - '0';

        if (i % 2){
            digit *= 2;

            if (digit >= 10)
                digit -= 9;
        }
        sum += digit;
    }

    if (sum % 10 == 0)
        return s[length-1] == '0';
    else
        return s[length-1] == (10 - (sum % 10) + '0');
}

int main(void){
    string cardNumber;
    cin >> cardNumber;

    if( !checkCardNumberLength(cardNumber) ){
        cout << "0\n";
        return 0;
    }
    cout << isCheckSumValid(cardNumber) << endl;
}