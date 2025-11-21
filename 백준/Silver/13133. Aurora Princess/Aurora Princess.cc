#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    
    vector<int> mother(N+1), father(N+1);
    for(int i = 1; i <= N; ++i) {
        cin >> mother[i] >> father[i];
    }

    int M;
    cin >> M;
    
    set<int> removed;
    for(int i = 0; i < M; ++i) {
        int x;
        cin >> x;
        removed.insert(x);
    }

    int ans = 0;
    for(int i = 1; i <= N; ++i) {
        
        // 1. 본인이 살아있는지
        if (removed.count(i)) continue;

        // 2. 부모가 존재하는지
        if (mother[i] == 0 || father[i] == 0) continue;

        // 3. 부모도 사건에 휘말리지 않았는지
        if (removed.count(mother[i]) || removed.count(father[i])) continue;

        ans++;
    }

    cout << ans << "\n";
    return 0;
}
