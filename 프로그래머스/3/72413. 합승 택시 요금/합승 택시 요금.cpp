#include <string>
#include <vector>

using namespace std;

const int INF = 20000000;

int graph[201][201];

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = INF;
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            graph[i][j] = i == j ? 0 : INF;
        }
    }
    
    for(auto fare : fares){
        int start = fare[0];
        int end = fare[1];
        int cost = fare[2];
        
        graph[start][end] = cost;
        graph[end][start] = cost;
    }
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            for(int k = 1; k <= n; k++){
                graph[j][k] = min(graph[j][k], graph[j][i] + graph[i][k]);
            }
        }
    }
    
    for(int i = 1; i <= n; i++){
        answer = min(answer, graph[a][i] + graph[b][i] + graph[s][i]);
    }
    
    return answer;
}