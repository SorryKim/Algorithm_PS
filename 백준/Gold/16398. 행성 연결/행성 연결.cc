#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int N;
int cost[1001][1001];
bool visited[1001];
long long answer = 0;

void input(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> cost[i][j];
}

void solve(){
    vector<int> minDist(N, INT_MAX);
    minDist[0] = 0;

    for (int cnt = 0; cnt < N; cnt++) {
        int u = -1;
        int minCost = INT_MAX;

        for (int i = 0; i < N; i++) {
            if (!visited[i] && minDist[i] < minCost) {
                minCost = minDist[i];
                u = i;
            }
        }

        visited[u] = true;
        answer += minCost;

        for (int v = 0; v < N; v++) {
            if (!visited[v] && cost[u][v] < minDist[v]) {
                minDist[v] = cost[u][v];
            }
        }
    }

}

int main() {
    input();
    solve();
    cout << answer << "\n";
    return 0;
}
