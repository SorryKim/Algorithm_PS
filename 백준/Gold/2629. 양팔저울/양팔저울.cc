#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

bool visited[40001][31];
int N, M;

void DFS(int weight, int idx, const vector<int> &v)
{

    if (idx >= N || visited[weight][idx] || weight >= 40000)
    {
        visited[weight][idx] = true;
        return;
    }

    visited[weight][idx] = true;

    // 추를 오른쪽에 올려놓은 경우
    DFS(weight + v[idx], idx + 1, v);

    // 추를 왼쪽에 올려놓은 경우
    // 음수될 수 있으므로 절대값처리
    DFS(abs(weight - v[idx]), idx + 1, v);

    // 추 안놓는 경우
    DFS(weight, idx + 1, v);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    vector<int> v(N, 0);
    for (int i = 0; i < N; i++)
        cin >> v[i];

    cin >> M;

    DFS(0, 0, v);
    for (int i = 0; i < M; i++)
    {
        int marble;
        cin >> marble;

        char answer = visited[marble][N] ? 'Y' : 'N';
        cout << answer << " ";
    }

    return 0;
}
