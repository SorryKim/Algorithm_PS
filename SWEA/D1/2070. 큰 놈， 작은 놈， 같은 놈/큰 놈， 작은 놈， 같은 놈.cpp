#include <iostream>
#include <math.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    for (int test = 1; test <= T; test++) {
        int a, b;
        cin >> a >> b;

        cout << "#" << test << " ";
        if (a > b)
            cout << ">\n";
        else if (a == b)
            cout << "=\n";
        else
            cout << "<\n";
    }
}