#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        long long a, b;
        cin >> a >> b;

        a %= 10;

        int exponent = b % 4;
        if (exponent == 0) exponent = 4;

        long long result = 1;
        for (int i = 0; i < exponent; i++)
            result *= a;

        int answer = result % 10;
        if (answer == 0) answer = 10;

        cout << answer << "\n";
    }

    return 0;
}