#include <string>
#include <vector>

using namespace std;

int N;
int maxScore = 0;
vector<int> answer;

// 점수 계산
int getScore(const vector<int> &ryan, const vector<int> &apeach) {
    int ryanScore = 0, apeachScore = 0;
    
    for (int i = 0; i < 11; i++) {
        int score = 10 - i;
        if (ryan[i] == 0 && apeach[i] == 0) continue;
        if (ryan[i] > apeach[i]) ryanScore += score;
        else apeachScore += score;
    }
    
    return ryanScore - apeachScore;
}

void DFS(int idx, int depth, vector<int> v, vector<int> &info) {
    
    if (depth == N || idx == 11) {
        // 남은 화살 0점에 몰아주기
        if (depth < N) v[10] += N - depth;

        int score = getScore(v, info);
        if (score <= 0) return; // 이기지 못함

        if (score > maxScore) {
            maxScore = score;
            answer = v;
        }
        else if (score == maxScore) {
            // 낮은 점수를 더 많이 맞힌 경우로 갱신
            for (int i = 10; i >= 0; i--) {
                if (v[i] > answer[i]) {
                    answer = v;
                    break;
                }
                else if (v[i] < answer[i]) break;
            }
        }
        return;
    }

    // 현재 점수에 화살 쏘기
    v[idx]++;
    DFS(idx, depth + 1, v, info);
    v[idx]--;

    // 다음 점수로 이동
    DFS(idx + 1, depth, v, info);
}

vector<int> solution(int n, vector<int> info) {
    N = n;
    vector<int> v(11, 0);
    DFS(0, 0, v, info);
    if (answer.empty()) return {-1};
    return answer;
}