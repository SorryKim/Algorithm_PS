#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<unsigned long long> guitars;
int minGuitars;
int maxSongs;

int countBits(unsigned long long x) {
    int cnt = 0;
    while (x) {
        cnt += (x & 1ULL);
        x >>= 1;
    }
    return cnt;
}

void dfs(int idx, int cnt, unsigned long long bits) {
    if (idx == (int)guitars.size()) {
        int songCnt = countBits(bits);
        if (songCnt > maxSongs) {
            maxSongs = songCnt;
            minGuitars = cnt;
        } else if (songCnt == maxSongs) {
            minGuitars = min(minGuitars, cnt);
        }
        return;
    }
    // 선택
    dfs(idx + 1, cnt + 1, bits | guitars[idx]);
    // 비선택
    dfs(idx + 1, cnt, bits);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    minGuitars = 1e9;
    maxSongs = 0;
    guitars.reserve(N);

    for (int i = 0; i < N; i++) {
        string name, code;
        cin >> name >> code;
        unsigned long long mask = 0ULL;
        for (int j = 0; j < M; j++) {
            if (code[j] == 'Y') mask |= (1ULL << j);  // ULL 중요!
        }
        guitars.push_back(mask);
    }

    dfs(0, 0, 0ULL);

    if (maxSongs == 0) cout << -1 << '\n';
    else cout << minGuitars << '\n';
    return 0;
}
