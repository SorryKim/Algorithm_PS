#include <iostream>
using namespace std;

int main() {
    int N;
    int S;

    while (cin >> N >> S) {
        int x = S / (N + 1);
        cout << x << '\n';
    }

    return 0;
}
