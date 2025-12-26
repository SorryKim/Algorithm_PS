#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    
    vector<pair<int,int>> v;
    for (int i = 0; i < N; i++) v.push_back({A[i], i});
    
    sort(v.begin(), v.end());

    vector<int> P(N);
    for (int i = 0; i < N; i++) {
        int idx = v[i].second;
        P[idx] = i;
    }

    for (int i = 0; i < N; i++) cout << P[i] << " ";
    cout << "\n";

    return 0;
}
