#include <iostream>
#include <set>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    set<int> S;
    for(int i = 0; i < M; i++){
        int num;
        cin >> num;
        S.insert(num);
    }

    
    int ans = 1e9; 

    for(int i = 1; i <= 1001; i++) {
        if(S.find(i) != S.end()) continue;
        for(int j = 1; j <= 1001; j++) {
            if(S.find(j) != S.end()) continue;
            for(int k = 1; k <= 1001; k++) {
                if(S.find(k) != S.end()) continue;
                int val = i*j*k;
                ans = min(ans, abs(N - val));
                if(N < val) break;
            }
        }
    }
    

    cout << ans << "\n";
    return 0;
}
