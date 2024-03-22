#include <vector>

using namespace std;


void dfs(int start, vector<vector<int>>& computers, vector<bool>& visited) {
    
    visited[start] = true;
    
    for (int i = 0; i < computers.size(); ++i) {
        if (computers[start][i] && !visited[i]) {
            dfs(i, computers, visited);
        }
    }
    
    return;
}

int solution(int n, vector<vector<int>> computers) {
    
    int answer = 0;
    vector<bool> visited(n, false);
    
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            dfs(i, computers, visited);
            answer++;
        }
    }

    return answer;
}
