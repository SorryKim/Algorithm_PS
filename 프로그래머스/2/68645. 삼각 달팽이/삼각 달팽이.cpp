#include <string>
#include <vector>
#include <iostream>

using namespace std;

// DFS 함수
void DFS(int x, int y, int& num, int n, vector<vector<int>>& v, vector<pair<int, int>>& directions, int& dirIdx) {
    // 현재 위치에 숫자 채우기
    v[x][y] = num++;
    
    // 다음 위치 계산
    int nx = x + directions[dirIdx].first;
    int ny = y + directions[dirIdx].second;
    
    // 경계를 벗어나거나 이미 채워진 곳이면 방향을 바꿔서 재시도
    if (nx >= n || ny >= v[nx].size() || v[nx][ny] != 0) {
        dirIdx = (dirIdx + 1) % 3;  // 방향 전환 (0 -> 1 -> 2 -> 0 반복)
        nx = x + directions[dirIdx].first;
        ny = y + directions[dirIdx].second;
    }
    
    // 다음 위치로 이동할 수 있는지 확인 후 재귀 호출
    if (nx < n && ny < v[nx].size() && v[nx][ny] == 0) {
        DFS(nx, ny, num, n, v, directions, dirIdx);
    }
}

vector<int> solution(int n) {
    vector<int> answer;
    vector<vector<int>> v;
    
    // 삼각형 모양의 2차원 배열 초기화
    for (int i = 1; i <= n; i++) {
        vector<int> temp(i, 0);
        v.push_back(temp);
    }
    
    // 방향 (아래 -> 오른쪽 -> 대각선 위)
    vector<pair<int, int>> directions = {{1, 0}, {0, 1}, {-1, -1}};
    int dirIdx = 0;  // 현재 방향 인덱스
    int num = 1;     // 채워질 숫자
    
    // 첫 번째 위치에서 시작
    DFS(0, 0, num, n, v, directions, dirIdx);
    
    // 2차원 배열을 1차원 배열로 변환
    for (auto a : v)
        for (auto b : a)
            answer.push_back(b);
    
    return answer;
}
