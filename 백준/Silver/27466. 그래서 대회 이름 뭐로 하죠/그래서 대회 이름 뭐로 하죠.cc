#include <bits/stdc++.h>
using namespace std;

bool isVowel(char c) {
    return c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    string S;
    cin >> N >> M >> S;

    // 뒤에서부터 "AAC" 패턴 찾기
    int c_idx = -1, a2_idx = -1, a1_idx = -1;

    for (int i = N - 1; i >= 0; i--) {
        if (c_idx == -1 && !isVowel(S[i])) c_idx = i;
        else if (c_idx != -1 && a2_idx == -1 && S[i] == 'A') a2_idx = i;
        else if (a2_idx != -1 && a1_idx == -1 && S[i] == 'A') {
            a1_idx = i;
            break;
        }
    }

    if (a1_idx == -1) {
        cout << "NO\n";
        return 0;
    }

    // 앞부분 채우기
    string T;
    for (int i = 0; i < a1_idx && (int)T.size() < M - 3; i++) {
        T += S[i];
    }

    T += "AA";
    T += S[c_idx];

    if ((int)T.size() == M) {
        cout << "YES\n" << T << "\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}
