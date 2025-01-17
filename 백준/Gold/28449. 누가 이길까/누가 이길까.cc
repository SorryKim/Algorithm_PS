#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    // Input
    int N, M;
    cin >> N >> M;

    vector<int> teamA(N), teamB(M);
    for(int i = 0; i < N; i++) cin >> teamA[i];
    for(int i = 0; i < M; i++) cin >> teamB[i];


    // 모두 경기해야하니 순서는 상관없음 이진탐색 사용하면 될 듯
    sort(teamB.begin(), teamB.end());
    long long winA = 0, winB = 0, draw = 0;
    
    for (int i = 0; i < N; i++) {
        int playerA = teamA[i];
    
        long long lower = lower_bound(teamB.begin(), teamB.end(), playerA) - teamB.begin(); // First position >= playerA
        long long upper = upper_bound(teamB.begin(), teamB.end(), playerA) - teamB.begin(); // First position > playerA

        winA += lower;
        winB += (M - upper);
        draw += (upper - lower);
    }
    

    cout << winA << " " << winB << " " << draw << '\n';
    return 0;
}
