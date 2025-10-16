#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long a, b;
    char slash;
    cin >> a >> slash >> b;

    string path = "";

    while (!(a == 1 && b == 1)) {
        if (a < b) {
            path += 'L';
            long long temp_b = b;
            b = a;
            a = temp_b - a;
        } else { // a > b
            path += 'R';
            long long temp_a = a;
            a = b;
            b = temp_a - b;
        }
    }

    cout << path << "\n";

    return 0;
}