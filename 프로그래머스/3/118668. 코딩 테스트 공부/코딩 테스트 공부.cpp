#include <string>
#include <vector>

using namespace std;

const int INF = 1e9;
int targetA, targetC; // 목표 알고력, 코딩력
int dp[201][201]; // dp[알고력][코딩력]에 도달할 수 있는 최소시간

int solution(int alp, int cop, vector<vector<int>> problems) {
    
    int answer = INF;
    targetA = 0;
    targetC = 0;
    for(auto a : problems){
        targetA = max(targetA, a[0]);
        targetC = max(targetC, a[1]);
    }
    
    // dp테이블 초기화
    for(int i = 0; i <= 200; i++){
        for(int j = 0; j <= 200; j++){
            dp[i][j] = INF;
        }
    }
    
    // 초기 설정
    dp[alp][cop] = 0;
    
    for(int i = alp; i <= 200; i++){
        for(int j = cop; j <= 200; j++){
            
            if (dp[i][j] == INF) continue;
            
            // 문제풀이x, 학습의 경우
            if (i + 1 <= 200) dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + 1);
            if (j + 1 <= 200) dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + 1);

            for(auto &p : problems){
                int alp_req = p[0];
                int cop_req = p[1];
                int alp_rwd = p[2];
                int cop_rwd = p[3];
                int cost = p[4];
                
                if(i >= alp_req && j >= cop_req){
                    int nextA = min(200, i + alp_rwd);
                    int nextC = min(200, j + cop_rwd);
                    dp[nextA][nextC] = min(dp[nextA][nextC], dp[i][j] + cost);
                }
            }
        }
    }
    
    // 정답 찾기
    for(int i = targetA; i <= 200; i++){
        for(int j = targetC; j <= 200; j++){
            answer = min(answer, dp[i][j]);
        }
    }
    
    return answer;
}