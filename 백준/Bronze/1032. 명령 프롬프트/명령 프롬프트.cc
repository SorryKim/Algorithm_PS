#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<string> files(N);
    for(int i = 0; i < N; i++) {
        cin >> files[i];
    }

    int len = files[0].size();
    string pattern = files[0];

    for(int i = 0; i < len; i++) {
        char cur = files[0][i];
        for(int j = 1; j < N; j++) {
            if(files[j][i] != cur) {
                pattern[i] = '?';
                break;
            }
        }
    }

    cout << pattern << "\n";
    return 0;
}
