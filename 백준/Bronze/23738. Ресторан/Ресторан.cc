#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    string ans;

    for (char ch : s) {
        switch (ch) {
            case 'A': ans += "a"; break;
            case 'K': ans += "k"; break;
            case 'M': ans += "m"; break;
            case 'O': ans += "o"; break;
            case 'T': ans += "t"; break;

            case 'B': ans += "v"; break;
            case 'E': ans += "ye"; break;
            case 'H': ans += "n"; break;
            case 'P': ans += "r"; break;
            case 'C': ans += "s"; break;
            case 'Y': ans += "u"; break;
            case 'X': ans += "h"; break;
        }
    }

    cout << ans << '\n';
    return 0;
}
