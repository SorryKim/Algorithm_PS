// 회장뽑기 / baekjoon_2660.cpp
// https://www.acmicpc.net/problem/2660

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define INF 987654321

int graph[51][51];
bool visited[51];
int N;
int arr[51];

void Input() {
    
    cin >> N;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            graph[i][j] = INF;
        }
    }

    for (int i = 0; i <= N; i++)
        graph[i][i] = 0;

    while (true) {
        int x, y;
        cin >> x >> y;
        if (x == -1 && y == -1)
            break;

        graph[x][y] = 1;
        graph[y][x] = 1;
    }
 
}


void Solve() {

    // 플로이드 워샬
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            for (int k = 1; k <= N; k++) {
                if (graph[i][k] + graph[j][i] < graph[j][k]) {
                    graph[j][k] = graph[i][k] + graph[j][i];
                }
            }
        }
    }

    int num = INF;

    for (int i = 1; i <= N; i++) {
        int temp = 0;

        for (int j = 1; j <= N; j++) {
            temp = max(temp, graph[i][j]);
        }

        arr[i] = temp;
        num = min(temp, num);

    }

    int cnt = 0;
    vector<int> v;
    for (int i = 1; i <= N; i++) {
        if (arr[i] == num) {
            cnt++;
            v.push_back(i);
        }
    }
    cout << num << " " << cnt << "\n";

    for (auto a : v) {
        cout << a << " ";
    }
    

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    Input();
    Solve();
}
