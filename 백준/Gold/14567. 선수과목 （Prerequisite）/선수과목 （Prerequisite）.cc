#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;
    vector<vector<int>> graph(N + 1);
    vector<int> answer(N + 1, 1);
    vector<int> indegree(N + 1, 0);

    for(int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        indegree[b]++;
    }

    queue<pair<int,int>> q; // {현재 과목, 이수기간}

    // 선수과목이 없는 과목들부터 시작
    for(int i = 1; i <= N; i++){
        if(indegree[i] == 0) q.push({i,1});
    }
    
    while(!q.empty()){
        int now = q.front().first;
        int now_cnt = q.front().second;
        q.pop();

        // 해당과목의 선수과목들 하나씩 제거
        for(int next : graph[now]){
            indegree[next]--;
            if(indegree[next] == 0){
                answer[next] = now_cnt + 1;
                q.push({next, now_cnt + 1});   
            }
        }
    }

    for(int i = 1; i <= N; i++) cout << answer[i] << " ";

    return 0;
}