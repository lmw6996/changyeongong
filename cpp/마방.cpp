#include <iostream>

using namespace std;

int main() {
    int arr[50][50]{ 0 }, n, count = 0;
    cin >> n;

    int a = 0, b = n / 2;
    for (int i = 0; i < n * n; i++) {
        count++;

        if (a < 0)
         a += n;

        if (b >= n)
         b -= n;
        arr[a][b] = count;

        if (count % n == 0) {
            a++;
            continue;
        }

        a--;
        b++;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
    return 0;
}
