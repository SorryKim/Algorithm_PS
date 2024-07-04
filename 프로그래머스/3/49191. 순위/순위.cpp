#include <string>
#include <vector>

using namespace std;


int solution(int n, vector<vector<int>> results) {
    
    int answer = 0;
    bool graph[101][101] = { false, };
    int wins[101] = { 0,};
    
    for(auto a: results){
        int winner = a[0];
        int loser = a[1];
        
        graph[winner][loser] = true;
    }
    
    // 플로이드 워샬
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            for(int k = 1; k <= n; k++){
                if(graph[k][i] && graph[i][j]){
                    graph[k][j] = true;
                }
            }
        }
    }
    
    for(int i = 1; i <= n; i++){
        bool flag = true;
        
        for(int j = 1; j <= n; j++){
            if(i != j){
                if(!graph[i][j] && !graph[j][i]){
                    flag = false;
                    break;
                }
            }
        }
        
        if(flag)
            answer++;
    }
    
   
    
    return answer;
}