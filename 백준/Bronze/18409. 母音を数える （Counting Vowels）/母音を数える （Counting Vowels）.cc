#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    string S;

    cin >> N >> S;

    int cnt = 0;
    for (char c : S) {
        if (c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o') {
            cnt++;
        }
    }

    cout << cnt << "\n";

    return 0;
}
