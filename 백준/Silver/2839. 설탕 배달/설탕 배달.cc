#include <iostream>
#include <vector>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    int DP[5001];

    for (int i = 0; i <= 5000; i++)
        DP[i] = -1;

    int num = 3;

    DP[3] = 1;
    DP[5] = 1;
    for (int i = 6; i <= 5000; i++) {

        int a = DP[i - 3];
        int b = DP[i - 5];

        if (a == -1 && b == -1)
            continue;

        if (a == -1)
            DP[i] = b + 1;
        else if (b == -1)
            DP[i] = a + 1;
        else
            DP[i] = min(a, b) + 1;


    }


    cout << DP[N] << '\n';

    
}