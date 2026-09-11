#include <string>
#include <algorithm>

using namespace std;

int solution(string name) {
    int answer = 0;
    int N = name.size();

    // 상하 조작 횟수
    for (char c : name) {
        int up = c - 'A';
        int down = 'Z' - c + 1;
        answer += min(up, down);
    }

    // 기본값: 오른쪽으로만 이동
    int move = N - 1;

    for (int i = 0; i < N; i++) {
        int next = i + 1;

        // i 다음부터 연속된 A 구간 확인
        while (next < N && name[next] == 'A') {
            next++;
        }

        // 오른쪽을 먼저 방문한 뒤 왼쪽으로 이동
        int rightFirst = i * 2 + (N - next);

        // 왼쪽을 먼저 방문한 뒤 오른쪽으로 이동
        int leftFirst = i + (N - next) * 2;

        move = min(move, min(rightFirst, leftFirst));
    }

    return answer + move;
}