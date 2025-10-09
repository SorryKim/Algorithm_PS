#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector<int> graph[26];
bool visited[26];

bool dfs(int a, int b) {
    if (a == b) return true;
    visited[a] = true;
    for (int next : graph[a]) {
        if (!visited[next] && dfs(next, b))
            return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N;

    // 관계 입력
    for (int i = 0; i < N; i++) {
        char a, b;
        string temp;
        cin >> a >> temp >> b;
        graph[a - 'a'].push_back(b - 'a');
    }

    cin >> M;
    for (int i = 0; i < M; i++) {
        char a, b;
        string temp;
        cin >> a >> temp >> b;

        memset(visited, false, sizeof(visited));
        if (dfs(a - 'a', b - 'a'))
            cout << "T\n";
        else
            cout << "F\n";
    }
}