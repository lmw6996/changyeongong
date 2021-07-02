#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

#define BARCODE_LENGTH   95         
#define GUARD_BAR "101"
#define CENTER_GUARD_BAR "01010"
#define DIGIT_LENGTH 7

typedef enum {LEFT, RIGHT} BarSide;

char barDigits[10][2][DIGIT_LENGTH+1] = {
        {"0001101", "1110010"}, {"0011001", "1100110"}, {"0010011", "1101100"},
        {"0111101", "1000010"}, {"0100011", "1011100"}, {"0110001", "1001110"},
        {"0101111", "1010000"}, {"0111011", "1000100"}, {"0110111", "1001000"},
        {"0001011", "1110100"} };

int readDigit(char *pattern, BarSide side){
    for (int i=0; i<10; i++){
        if (strncmp(pattern, barDigits[i][side], DIGIT_LENGTH) == 0) return i;
    }
    return -1;
}

bool checkSum(string& s){
    int i;
    int evenSum = 0, oddSum = 0;
    int sum;
    int check;

    for (i=0; i<5; i++){
        oddSum += s[2*i+1] - '0' ;
        evenSum += s[2*i] - '0';
    }
    evenSum += s[10] - '0';

    sum = oddSum + evenSum * 3;
    check = 10 - (sum % 10);
    if (check == 10) check = 0;

    if (check == (s[11] - '0')) return true; 
    s += '*';
    s += check + '0';
    return false;
}

string barCode(char *bars){
    if (strlen(bars) != BARCODE_LENGTH) throw -1;
    if (strncmp(bars,GUARD_BAR,3)) throw -1;
    if (strncmp(bars+92,GUARD_BAR,3)) throw -1;
    if (strncmp(bars+45,CENTER_GUARD_BAR,5)) throw -1;

    string code;
    int digit;

    digit = readDigit(bars+3, LEFT); // determine the scanning direction with the first digit
    if ( digit < 0 ){
        reverse(bars, bars + BARCODE_LENGTH);
        digit = readDigit(bars+3, LEFT);
        if ( digit < 0 )   throw -1;
    }
    code += digit + '0';

    for (int i=1; i<6; i++){
        digit = readDigit(bars + 3 + DIGIT_LENGTH * i, LEFT);
        if (digit < 0)  throw -1;
        code += digit + '0';
    }
    for (int i=6; i<12; i++){
        digit = readDigit(bars + 8 + DIGIT_LENGTH * i, RIGHT);
        if (digit < 0)  throw -1;
        code += digit + '0';
    }
    
    checkSum(code);
    return code;
}

int main(){
    char input[101];
    cin >> input;
    try {
        string code = barCode(input);
        cout << code.substr(0,6) << '-' << code.substr(6) << endl;
    }
    catch (...) {
        cout << "******-******\n";
    }
}