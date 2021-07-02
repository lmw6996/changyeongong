#include<iostream>
using namespace std;

int arr[1000001] = { 0 };

int main() {

        int n;
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        long long answer = 0;
        int last = arr[n - 1];

        for (int i = n-2; i >= 0; i--)
        {
            if (last > arr[i])
            {
                answer += (last - arr[i]);
            }
            else{
                last = arr[i];
            }
        }
        if (answer <= 0)
         cout << 0 << endl;
        else cout << answer <<endl;
    }
