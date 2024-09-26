#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 1000000;
vector<int> tree[MAX + 1];
int DP[MAX + 1][2];
bool visited[MAX + 1];

void DFS(int now){

    visited[now] = true;

    DP[now][0] = 0; // now가 얼리어답터가 아닌 경우
    DP[now][1] = 1; // now가 얼리어답터인 경우

    for(int next : tree[now]){

        if(!visited[next]){
            
            // 말단 노드에서부터 DP테이블 쌓아올림
            DFS(next);

            // 본인이 얼리어답터가 아니라면 자식은 반드시 얼리어답터이다.
            DP[now][0] += DP[next][1];

            // 본인이 얼리어답터라면 둘 중 최솟값 선택
            DP[now][1] += min(DP[next][1], DP[next][0]);

        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    for(int i = 0; i < N - 1; i++){
        int u,v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    DFS(1); // 임의의 노드를 루트로 선택

    int answer = min(DP[1][0], DP[1][1]);
    cout << answer << '\n';

    return 0;
}
