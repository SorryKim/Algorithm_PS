#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int cnt = 1;

    while (true) {
        int N;
        cin >> N;
        if (N == 0) break;
        for (int i = 0; i < N; ++i) {
            int num;
            cin >> num;
        }
        cout << "Case " << cnt++ << ": Sorting... done!\n";
    }

    return 0;
}