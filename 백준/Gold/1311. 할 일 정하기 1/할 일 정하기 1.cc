#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

const int MAXN = 20;
int N;
int work[MAXN][MAXN];
int DP[1 << MAXN][MAXN];

// 집합에 해당 사람이 존재하는지 확인 
bool Check(int people, int person){
    return ((people >> person) & 1) == 1;
}

// 집합에 해당 사람 포함 
int Select(int people, int person){
    return (people | (1 << person));
}

// idx: 일의 인덱스
// people: 사람의 비트마스크 상태
int DFS(int idx, int people){

    // 모든 일이 할당된 경우
    if(idx == N)
        return 0;

    // 이미 계산된 경우
    if(DP[people][idx] != 0)
        return DP[people][idx];

    int result = 1e9;

    for(int i = 0; i < N; i++){

        // 이미 해당 사람이 선택된 경우
        if(Check(people, i))
            continue;

        int cost = work[i][idx] + DFS(idx + 1, Select(people, i));
        result = min(result, cost);
    }

    DP[people][idx] = result;
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // Input
    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> work[i][j];
        }
    }

    int ans = DFS(0, 0);

    cout << ans << endl;
    return 0;
}
