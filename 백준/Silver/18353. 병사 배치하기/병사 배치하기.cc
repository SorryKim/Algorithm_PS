#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    vector<int> v(N);
    for(int i = 0; i < N; i++) cin >> v[i];
    reverse(v.begin(), v.end());
    
    vector<int> ans;
    for(int i = 0; i < N; i++){

        int now = v[i];
        if(ans.empty() || ans.back() < now) ans.push_back(now);
        else{
            int idx = upper_bound(ans.begin(), ans.end(), now) - ans.begin();
            ans[idx] = now;
        }
        
    }

    cout << N - ans.size() << '\n';
    
    return 0;
}
