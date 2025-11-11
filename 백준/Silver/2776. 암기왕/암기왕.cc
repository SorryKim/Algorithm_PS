#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N;
        vector<int> note1(N);
        for (int i = 0; i < N; i++) cin >> note1[i];
        sort(note1.begin(), note1.end());

        cin >> M;
        for (int i = 0; i < M; i++) {
            int x;
            cin >> x;
            if (binary_search(note1.begin(), note1.end(), x))
                cout << "1\n";
            else
                cout << "0\n";
        }
    }
    
    return 0;
}
