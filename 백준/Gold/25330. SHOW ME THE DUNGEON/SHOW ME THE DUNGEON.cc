#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, K;
vector<pair<int, int>> villages;
int ans = 0;

void input(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> K;
    villages.resize(N);

    vector<int> temp(N);
    for (int i = 0; i < N; i++) cin >> temp[i];

    for (int i = 0; i < N; i++){
        int p;
        cin >> p;
        villages[i] = {temp[i], p};
    }
}

void dfs(int idx, int usedHp, int sum, int rescued){

    if(idx == N){
        ans = max(ans, rescued);
        return;
    }

    int cost = villages[idx].first + sum;

    if(usedHp + cost <= K) dfs(idx + 1, usedHp + cost, sum + villages[idx].first, rescued + villages[idx].second);
    
    dfs(idx + 1, usedHp, sum, rescued);
}

void solve(){

    sort(villages.begin(), villages.end());
    dfs(0, 0, 0, 0);

}

int main() {

    input();
    solve();
    cout << ans << '\n';
    return 0;
}
