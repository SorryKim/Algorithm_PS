#include <iostream>
#include <vector>
#include <string>

using namespace std;

int K;
vector<char> v;
string mn = "", mx = "";

void input(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> K;
    v.resize(K);

    for (int i = 0; i < K; i++) cin >> v[i];
    
    return;
}

bool check(char op, char a, char b) {
    if (op == '<') return a < b;
    return a > b;
}

void dfs(int depth, string cur, int mask) {

    // 종료 조건
    if (depth == K + 1) {
        if (mn.empty() || cur < mn) mn = cur;
        if (mx.empty() || cur > mx) mx = cur;
        return;
    }

    for (int i = 0; i <= 9; i++) {
        if (mask & (1 << i)) continue;  // 이미 사용한 숫자

        char digit = char('0' + i);
        
        if (depth == 0 || check(v[depth - 1], cur.back(), digit)) {
            dfs(depth + 1, cur + digit, mask | (1 << i));
        }
    }
}

int main() {
    
    input();
    dfs(0, "", 0);

    cout << mx << '\n';
    cout << mn << '\n';

    return 0;
}