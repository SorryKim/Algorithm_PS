#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

// 모든 SCV가 파괴된 경우
bool Finish(vector<int> &v){

    for(int now : v){
        if(now > 0)
            return false;
    }

    return true;
}

int BFS(vector<int> &v){

    int result = 1e9;
    bool visited[61][61][61];
    queue<pair<int, vector<int>>> q;
    q.push({0,v});

    while (!q.empty()) {
        int cnt = q.front().first;
        vector<int> now = q.front().second;
        q.pop();

        if (Finish(now)) {
            result = min(result, cnt);
            continue;
        }

        // 6가지 공격 순서
        vector<vector<int>> attacks = {
            {9, 3, 1},
            {9, 1, 3},
            {3, 9, 1},
            {3, 1, 9},
            {1, 9, 3},
            {1, 3, 9}
        };

        for (auto &attack : attacks) {
            vector<int> next = now;
            for (int i = 0; i < now.size(); i++) 
                next[i] = max(0, next[i] - attack[i]); // 공격 후 체력 감소

            // 방문 체크 및 큐에 추가
            if (!visited[next[0]][next[1]][next[2]]) {
                visited[next[0]][next[1]][next[2]] = true;
                q.push({cnt + 1, next});
            }
        }
    }
    
    return result;   
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<int> v(N);
    for(int i = 0; i < N; i++) cin >> v[i];

    cout << BFS(v) << '\n';

    return 0;
}
