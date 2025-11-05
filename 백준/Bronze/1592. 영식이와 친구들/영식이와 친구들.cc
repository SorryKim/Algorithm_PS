#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, L;
    cin >> N >> M >> L;

    vector<int> v(N + 1, 0);
    int now = 1; 
    int cnt = 0;

    while (true) {
        v[now]++;
        if (v[now] == M) break;

        if (v[now] % 2 == 1)
            now = (now + L - 1) % N + 1;
        else
            now = (now - L - 1 + N) % N + 1;

        cnt++;
    }

    cout << cnt << "\n";
    return 0;
}
