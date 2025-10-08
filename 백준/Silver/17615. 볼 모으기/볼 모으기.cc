#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int N;
string s;

void input() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    cin >> s;
}

int solve() {
    int ans = 1e9;
    int cnt;

    // 1️. 빨간볼을 왼쪽으로 옮기는 경우
    cnt = 0;
    int idx = 0;
    while (idx < N && s[idx] == 'R') idx++;
    for (int i = idx; i < N; i++) {
        if (s[i] == 'R') cnt++;
    }
    ans = min(ans, cnt);

    // 2. 빨간볼을 오른쪽으로 옮기는 경우
    cnt = 0;
    idx = N - 1;
    while (idx < N && s[idx] == 'R') idx--; 
    
    for (int i = idx; i >= 0; i--) {
        if (s[i] == 'R') cnt++;
    }
    ans = min(ans, cnt);

    // 3. 파란볼을 왼쪽으로 옮기는 경우
    cnt = 0;
    idx = 0;
    while (idx < N && s[idx] == 'B') idx++;
    for (int i = idx; i < N; i++) {
        if (s[i] == 'B') cnt++;
    }
    ans = min(ans, cnt);

    // 4. 파란볼을 오른쪽으로 옮기는 경우
    cnt = 0;
    idx = N - 1;
    while (idx < N && s[idx] == 'B') idx--; 
    
    for (int i = idx; i >= 0; i--) {
        if (s[i] == 'B') cnt++;
    }
    ans = min(ans, cnt);

    return ans;
}

int main() {
    input();
    cout << solve() << '\n';
    return 0;
}
