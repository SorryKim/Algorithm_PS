#include <string>
#include <vector>

using namespace std;

bool visited[1001] = {false,};
int answer = -1;

void DFS(int nowIdx, int fatigue, int cnt, const vector<vector<int>> &dungeons){
    
    for(int i = 0; i < dungeons.size(); i++){
        if(!visited[i]){
            if(fatigue >= dungeons[i][0]){
                visited[i] = true;\
                answer = max(answer, cnt + 1);
                DFS(i, fatigue - dungeons[i][1], cnt + 1, dungeons);
                visited[i] = false;
            }
        }
    }
    
}

int solution(int k, vector<vector<int>> dungeons) {
    
    DFS(0, k, 0, dungeons);
    
    return answer;
}