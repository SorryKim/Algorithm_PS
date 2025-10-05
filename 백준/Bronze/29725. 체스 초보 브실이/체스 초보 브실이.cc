#include <iostream>
#include <string>
using namespace std;

int getScore(char c) {
    switch (tolower(c)) {
        case 'p': return 1;
        case 'n': return 3;
        case 'b': return 3;
        case 'r': return 5;
        case 'q': return 9;
        case 'k': return 0;
        default: return 0;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int white = 0, black = 0;
    for (int i = 0; i < 8; i++) {
        string row;
        cin >> row;
        for (char c : row) {
            if (c == '.') continue;
            if (isupper(c)) white += getScore(c);
            else black += getScore(c);
        }
    }

    cout << white - black << "\n";
    return 0;
}
