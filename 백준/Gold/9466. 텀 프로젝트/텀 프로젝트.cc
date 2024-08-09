#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int MAX = 100000;
int n;
int arr[MAX + 1];
bool check[MAX + 1];
bool finished[MAX + 1];
int team_count;

void DFS(int current) {

    check[current] = true;
    int next = arr[current];

    if (!check[next]) {
        DFS(next);
    } else if (!finished[next]) {

        // 사이클이 발생한 경우
        for (int i = next; i != current; i = arr[i]) {
            team_count++;
            finished[i] = true; // 사이클 내의 노드들을 처리
        }
        team_count++;
        finished[current] = true; // 마지막 노드 처리
    }

    finished[current] = true; // 탐색 종료
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    while (T--) {
        cin >> n;
        int answer = 0;
        team_count = 0;

        for(int i = 0; i <= n; i++){
            finished[i] = false;
            check[i] = false;
        }

        for (int i = 1; i <= n; i++) 
            cin >> arr[i];
        

        for (int i = 1; i <= n; i++) {
            if (!check[i]) {
                DFS(i);
            }
        }

        answer = n - team_count;
        cout << answer << '\n';
    }

    return 0;
}
