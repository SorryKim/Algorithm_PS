#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;

    vector<long long> a(N);
    for(int i = 0; i < N; i++) cin >> a[i];

    sort(a.begin(), a.end());  // 오름차순

    long long sum = 0;
    for(int i = 0; i < K; i++){
        sum += a[N - 1 - i];  // 큰 것부터 K개
    }

    long long penalty = 1LL * K * (K - 1) / 2;

    cout << sum - penalty << "\n";
    return 0;
}
