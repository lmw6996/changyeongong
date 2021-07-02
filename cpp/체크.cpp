#include <iostream>
using namespace std;

bool isChecksumOK(unsigned int n);

int main(void){
        unsigned int value;

        cin >> value;
        cout << isChecksumOK(value) << endl;
}

bool isChecksumOK(unsigned int n){
    int three = 3;
    unsigned int mask = 0x000000FF;
    unsigned int byte;
    unsigned int sum = 0;
    unsigned int checkSum;

    checkSum = n & mask;

    while (three--){
        n >>= 8;
        byte = n & mask;
        sum += byte;
    }

    sum = sum & mask;

    sum = 255 - sum;

    if (checkSum == sum)
        return true;
    else
        return false;
}
