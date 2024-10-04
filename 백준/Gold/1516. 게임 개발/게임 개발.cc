#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    int time[501]; // 건물별 건설 시간
    int degree[501]; // 선행 건물의 갯수
    int dp[501]; // 해당 건물짓기 위해 필요한 시간

    cin >> N;
    vector<vector<int>> graph(N + 1, vector<int>());
    // Input
    
    for(int i = 1; i <= N; i++){
        int a, b;
        cin >> time[i] >> b;
        dp[i] = time[i];
        if(b == -1)
            continue;
        else{
            while(b != -1){
                degree[i]++;
                graph[b].push_back(i);
                cin >> b;
            }
        }
    }

    // 선행건물이 필요없는 건물부터 지음
    queue<int> q;
    for(int i = 1; i <= N; i++){
        if(degree[i] == 0)
            q.push(i);
    }

    
    while(!q.empty()){
        int now = q.front();
        q.pop();

        for(auto next : graph[now]){
            degree[next]--;
            dp[next] = max(dp[next], dp[now] + time[next]);
            
            // 선행건물이 모두 지어진 경우
            if (degree[next] == 0)
                    q.push(next);
        }
    }
    

    for(int i = 1; i <= N; i++)
        cout << dp[i] <<'\n';

    return 0;
}
