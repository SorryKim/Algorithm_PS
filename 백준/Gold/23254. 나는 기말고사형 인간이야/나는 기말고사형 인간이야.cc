#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> a, b;

void input(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;

    a.resize(M);
    b.resize(M);

    for(int i = 0; i < M; i++) cin >> a[i];
    for(int i = 0; i < M; i++) cin >> b[i];

    return;
}

int solve(){

    int T = 24 * N;
    int ans = 0;

    // 기본 점수 먼저 더함
    for(int i = 0; i < M; i++) ans += a[i];

    vector<int> cnt(101, 0);

    for(int i = 0; i < M; i++){
        int gap = 100 - a[i];

        int k = gap / b[i];
        int r = gap % b[i];

        cnt[b[i]] += k;
        cnt[r]++;
    }

    int time = 0;
    for(int i = 100; i > 0 && T > time; i--){
        if(cnt[i] == 0) continue;
        int t = min(cnt[i], T - time);
        time += t;
        ans += t * i;
    }

    return ans;
}

int main(){
    input();
    cout << solve() << "\n";
    return 0;
}
