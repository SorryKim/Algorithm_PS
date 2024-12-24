#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int a = 2 * n + 2;
    int b = 3 * n + 3;
    cout << a << " " << b << "\n";

    return 0;
}