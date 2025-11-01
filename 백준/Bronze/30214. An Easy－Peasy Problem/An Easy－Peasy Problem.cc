#include <iostream>
using namespace std;

int main() {
    int s1, s2;
    cin >> s1 >> s2;

    if (2 * s1 >= s2)
        cout << "E\n";
    else
        cout << "H\n";

    return 0;
}
