#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int A, B, C;
    cin >> A >> B >> C;

    cout << (3 * B * C) / A; 

    return 0;
}