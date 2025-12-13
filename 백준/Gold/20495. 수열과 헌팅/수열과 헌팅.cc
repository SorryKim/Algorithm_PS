#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> L, R;

void input(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    L.resize(N);
    R.resize(N);
    for(int i = 0; i < N; i++){
        int a, b;
        cin >> a >> b;
        L[i] = a - b;
        R[i] = a + b;
    }
}

void solve(){

    vector<int> r = R;
    vector<int> l = L;
    sort(r.begin(), r.end());
    sort(l.begin(), l.end());

    for(int i = 0; i < N; i++){
        int start = lower_bound(r.begin(), r.end(), L[i]) - r.begin();
        int end = l.end() - upper_bound(l.begin(), l.end(), R[i]);

        int minIdx = start + 1;
        int maxIdx = N - end;

        cout << minIdx << " " << maxIdx << "\n";
    }

    return;
}

int main(){
    input();
    solve();
    return 0;
}