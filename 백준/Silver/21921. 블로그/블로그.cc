#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, X;
    cin >> N >> X;

    vector<long long> v(N, 0);
    vector<long long> p(N, 0);
    for(int i = 0; i < N; i++) cin >> v[i];

    p[0] = v[0];

    for(int i = 1; i < N; i++){
        if(i < X) p[i] = p[i - 1] + v[i];
        else p[i] = p[i - 1] + v[i] - v[i - X];
    }
    
    sort(p.begin(), p.end(), greater<int>());

    int val = p[0];
    int ans = 1;
    for(int i = 1; i < N; i++){
        if(p[i] != val) break;
        ans++;
    }

    if(val == 0) cout << "SAD\n";
    else {
        cout << val << "\n";
        cout << ans << "\n";
    }
    
    return 0;
}