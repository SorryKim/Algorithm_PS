#include <string>
#include <vector>
using namespace std;

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int n = board.size();
    int m = board[0].size();

    // 누적합 배열
    vector<vector<int>> acc(n + 1, vector<int>(m + 1, 0));

    // 각 skill을 누적합 배열에 표시
    for (auto &s : skill) {
        int type = s[0];
        int r1 = s[1], c1 = s[2], r2 = s[3], c2 = s[4], degree = s[5];

        // 공격이면 음수, 회복이면 양수
        if (type == 1) degree = -degree;

        acc[r1][c1] += degree;
        acc[r1][c2 + 1] -= degree;
        acc[r2 + 1][c1] -= degree;
        acc[r2 + 1][c2 + 1] += degree;
    }

    // 행 기준 누적합
    for (int i = 0; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            acc[i][j] += acc[i][j - 1];
        }
    }

    // 열 기준 누적합
    for (int j = 0; j <= m; j++) {
        for (int i = 1; i <= n; i++) {
            acc[i][j] += acc[i - 1][j];
        }
    }

    // 최종 내구도 계산 + 파괴되지 않은 건물 카운트
    int answer = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] + acc[i][j] > 0) answer++;
        }
    }
    
    return answer;
}
