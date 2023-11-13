#include <iostream>
#include <vector>
using namespace std;

bool Check(string s) {

    int length = (int)(s.length() / 2);
    for (int i = 0; i < length; i++) {
        char a = s[i];
        char b = s[s.length() - i - 1];

        if (a != b)
            return false;
    }

    return true;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;

    for (int test = 1; test <= T; test++) {
        string s;
        cin >> s;
        bool b = Check(s);
        int ans = b ? 1 : 0;
        cout << "#" << test << " " << ans << "\n";

    }
}