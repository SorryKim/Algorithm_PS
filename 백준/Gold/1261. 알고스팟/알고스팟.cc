#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int INF = 987654321;

int graph[101][101];
int dist[101][101];

int N, M;
int moveX[4] = {1, -1, 0, 0};
int moveY[4] = {0, 0, 1, -1};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // Input
    cin >> N >> M;
    for (int i = 1; i <= M; i++)
    {
        string s;
        cin >> s;
        for (int j = 1; j <= N; j++)
        {
            graph[i][j] = s[j - 1] - '0';
        }
    }

    for(int i = 0 ; i <= 100; i++){
        for(int j = 0; j <= 100; j++)
            dist[i][j] = INF;
    }

    queue<pair<int,int>> q;
    q.push({1,1});
    dist[1][1] = 0;

    while(!q.empty()){

        int nowX = q.front().first;
        int nowY = q.front().second;
        int nowDist = dist[nowX][nowY];
        q.pop();

        for(int i = 0; i < 4; i++){
            int nextX = nowX + moveX[i];
            int nextY = nowY + moveY[i];
            if(nextX > 0 && nextX <= M && nextY > 0 && nextY <= N){
                
                if(dist[nextX][nextY] > nowDist + graph[nextX][nextY]){
                    dist[nextX][nextY] = nowDist + graph[nextX][nextY];
                    q.push({nextX,nextY});
                }
            }
            
        }
    }

    cout << dist[M][N];
    
    return 0;
}