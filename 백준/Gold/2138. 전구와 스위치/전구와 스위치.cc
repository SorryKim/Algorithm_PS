#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int N;
const int INF = 987654321;

string toggle(string s, int idx) {

    // 스위치 idx를 눌렀을 때 전구 상태 변경
    for (int i = idx - 1; i <= idx + 1; ++i) {
        if (i >= 0 && i < N) {
            s[i] = (s[i] == '0') ? '1' : '0';
        }
    }

    return s;
}

int solve(string s, string target, bool first) {
    int cnt = 0;

    if (first) {
        s = toggle(s, 0);
        cnt++;
    }

    for (int i = 1; i < N; ++i) {

        if (s[i - 1] != target[i - 1]) {
            s = toggle(s, i);
            cnt++;
        }

    }

    if (s == target)
        return cnt;
    else
        return INF;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    string s, target;
    cin >> s >> target;

    int result1 = solve(s, target, false);
    int result2 = solve(s, target, true);

    int answer = min(result1, result2);

    if (answer == INF)
        cout << -1 << '\n';
    else
        cout << answer << '\n';

    return 0;
}
