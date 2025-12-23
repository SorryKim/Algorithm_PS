#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<int> baskets(N);
    for (int i = 0; i < N; i++) {
        baskets[i] = i + 1; 
    }

    while (M--) {
        int i, j;
        cin >> i >> j;
        swap(baskets[i - 1], baskets[j - 1]);
    }

    for (int i = 0; i < N; i++) {
        cout << baskets[i] << ' ';
    }

    return 0;
}
