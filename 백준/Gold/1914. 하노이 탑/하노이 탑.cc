#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int N;
string path = "";

// __int128 → string 변환 함수
string to_string128(__int128 n) {
    if (n == 0) return "0";
    string s;
    while (n > 0) {
        s.push_back('0' + (n % 10));
        n /= 10;
    }
    reverse(s.begin(), s.end());
    return s;
}

void hanoi(int n, int from, int to, int via) {
    if (n == 0) return;
    hanoi(n - 1, from, via, to);
    path += to_string(from) + " " + to_string(to) + "\n";
    hanoi(n - 1, via, to, from);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    // 2^N - 1 계산 (__int128 사용)
    __int128 ans = 1;
    for (int i = 0; i < N; i++) ans *= 2;
    ans -= 1;

    cout << to_string128(ans) << "\n";

    if (N <= 20) {
        hanoi(N, 1, 3, 2);
        cout << path;
    }
}
