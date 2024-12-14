#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;

        int i = (int)s.size() - 2;
        while (i >= 0 && s[i] >= s[i + 1]) i--; // 교환위치 찾기

        if (i < 0) cout << s << '\n';
        else {
            int j = (int)s.size() - 1;
            while (s[j] <= s[i]) j--;
            swap(s[i], s[j]);
            reverse(s.begin() + i + 1, s.end());
            cout << s << '\n';
        }
    }

    return 0;
}