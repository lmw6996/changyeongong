#include <iostream>
#include <vector>
using namespace std;

vector<int> v;

void happyNumber(int N)
{
        if (N == 1){
       cout << "HAPPY" << endl;
        return;
      }
        for(int i=0; i<v.size(); i++)
               if (N == v[i]){
                  cout << "UNHAPPY" << endl;
                  return;
                }
        v.push_back(N);

        int n = N;
        int result = 0;

        while (n)
        {
               result += (n % 10)*(n % 10);
               n /= 10;
        }
        happyNumber(result);
}

int main(void)
{
        int N;
        cin >> N;
        happyNumber(N);

       return 0;
}
