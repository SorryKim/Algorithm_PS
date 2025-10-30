#include <iostream>
#include <cmath>
using namespace std;

int N;
long long K;

void solve(int n, int from, int to, int via, long long k) {
    
    if (n == 1) { // base
        cout << from << " " << to << "\n";
        return;
    }

    long long half = (1LL << (n - 1)); // 가운데 이동 위치
    
    if (k < half) {
        // 왼쪽 블록
        solve(n - 1, from, via, to, k);
    } 
    else if (k == half) {
        // 가운데 이동
        cout << from << " " << to << "\n";
    } 
    else {
        // 오른쪽 블록
        solve(n - 1, via, to, from, k - half);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> K;
    solve(N, 1, 3, 2, K);
}
