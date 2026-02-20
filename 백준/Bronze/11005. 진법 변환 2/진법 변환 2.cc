#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    long long N;
    int B;
    cin >> N >> B;

    string result = "";

    while (N > 0) {
        int r = N % B;

        if (r < 10)
            result += (r + '0');
        else
            result += (r - 10 + 'A');

        N /= B;
    }

    reverse(result.begin(), result.end());
    cout << result;

    return 0;
}