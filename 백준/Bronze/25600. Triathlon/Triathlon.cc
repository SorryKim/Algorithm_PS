#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    long long answer = 0;

    for (int i = 0; i < N; i++) {
        long long a, d, g;
        cin >> a >> d >> g;

        long long score = a * (d + g);
        if (a == d + g) {
            score *= 2;
        }

        answer = max(answer, score);
    }

    cout << answer << "\n";
    return 0;
}
