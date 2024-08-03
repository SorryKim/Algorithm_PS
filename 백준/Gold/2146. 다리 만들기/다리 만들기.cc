#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
int graph[101][101];
bool visited[101][101];
vector<vector<pair<int, int>>> islands;

int moveX[4] = { 1,-1,0,0 };
int moveY[4] = { 0,0,1,-1 };

void Clear() {

    for (int i = 0; i <= 100; i++) 
        for (int j = 0; j <= 100; j++) 
            visited[i][j] = false;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> graph[i][j];
            visited[i][j] = false;
        }
    }
    
    int num = 1;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            
            
            
            if (graph[i][j] == 1 && !visited[i][j]) {
                num++;
                vector<pair<int, int>> v; // 섬의 좌표들
                queue<pair<int, int>> q;
                q.push({ i,j });
                visited[i][j] = true;

                while (!q.empty()) {
                    int nowX = q.front().first;
                    int nowY = q.front().second;
                    v.push_back({ nowX, nowY });
                    graph[nowX][nowY] = num;
                    q.pop();
                    
                    for (int i = 0; i < 4; i++) {
                        int nextX = nowX + moveX[i];
                        int nextY = nowY + moveY[i];

                        if (nextX >= 0 && nextX < N && nextY >= 0 && nextY < N) {
                            if (!visited[nextX][nextY] && graph[nextX][nextY] == 1) {
                                visited[nextX][nextY] = true;
                                q.push({ nextX,nextY });
                            }
                        }
                    }
                }

                islands.push_back(v);

            }
            
        }
    }
    

    int answer = 98765321;

    for (auto a : islands) {
        for (auto b : a) {

            Clear();
            queue<pair<pair<int, int>, int>> q;
            q.push({ { b.first, b.second }, 0});
            visited[b.first][b.second] = true;
            int num = graph[b.first][b.second];

            while (!q.empty()) {

                int nowX = q.front().first.first;
                int nowY = q.front().first.second;
                int dist = q.front().second;
                q.pop();

                // 다른 대륙에 도착한 경우
                if (graph[nowX][nowY] != 0 && graph[nowX][nowY] != num) {
                    answer = min(answer, dist);
                    break;
                }

                for (int i = 0; i < 4; i++) {
                    int nextX = nowX + moveX[i];
                    int nextY = nowY + moveY[i];

                    if(nextX >= 0 && nextX < N && nextY >= 0 && nextY < N) {
                        
                        if (!visited[nextX][nextY] && graph[nextX][nextY] != num) {
                            visited[nextX][nextY] = true;
                            q.push({ {nextX, nextY}, dist + 1 });
                        }
                    }
                }
                
                
            }

        }
    }
    
    cout << answer - 1 << "\n";

    return 0;
}
