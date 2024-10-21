#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int TC;
    const int INF = 1e9;
    cin >> TC;

    while(TC--){

        int N, M, K;
        
        // Input
        cin >> N >> M;
        vector<vector<int>> graph(N + 1, vector<int>(N + 1, INF));
        for(int i = 1; i <= N; i++)
            graph[i][i] = 0;
        for(int i = 0; i < M; i++){
            int a, b, c;
            cin >> a >> b >> c;
            graph[a][b] = c;
            graph[b][a] = c;
        }
        cin >> K;
        vector<int> friends(K);
        for(int i = 0; i < K; i++)
            cin >> friends[i];

        // 플로이드-워샬
        for(int i = 1; i <= N; i++){
            for(int j = 1; j <= N; j++){
                for(int k = 1; k <= N; k++){
                    if(graph[j][k] > graph[j][i] + graph[i][k]){
                        graph[j][k] = graph[j][i] + graph[i][k];
                    }
                }
            }
        }

        int target = INF;
        int answer = 0;
        // 최소 경로 설정
        for(int place = 1; place <= N; place++){
            int sum = 0;
            for(auto a : friends)
                sum += graph[a][place];
            if(target > sum){
                target = sum;
                answer = place;
            }
        }

        cout << answer << '\n';
    }

    return 0;
}
