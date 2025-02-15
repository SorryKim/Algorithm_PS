#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 100000;
int N;
int tree[MAX + 1][2];
bool visited[MAX + 1];
int parent[MAX + 1];
int cnt = 0;
int LAST;

void InOrder(int node){

    int left = tree[node][0];
    int right = tree[node][1];

    // 순회 처리
    // cout << node << '\n';
    cnt++;
    visited[node] = true;

    // 1. 현재 위치한 노드의 왼쪽 자식 노드가 존재하고 아직 방문하지 않았다면, 왼쪽 자식 노드로 이동한다.
    if(left != -1 && !visited[left]){
        InOrder(left);
    }
    // 2. 그렇지 않고 현재 위치한 노드의 오른쪽 자식 노드가 존재하고 아직 방문하지 않았다면, 오른쪽 자식 노드로 이동한다.
    else if(right != -1 && !visited[right]) {
        InOrder(right);
    }
    // 3. 그렇지 않고 현재 노드가 유사 중위 순회의 끝이라면, 유사 중위 순회를 종료한다.
    else if(node == LAST){
        return;
    }
    // 4. 그렇지 않고 부모 노드가 존재한다면, 부모 노드로 이동한다.
    else if(parent[node] != -1){
        InOrder(parent[node]);
    }

}

void Init(){
    for(int i = 1; i <= MAX; i++){
        tree[i][0] = -1;
        tree[i][1] = -1;
        visited[i] = false;
        parent[i] = -1;
    }
}

void Input(){
    
    Init();
    cin >> N;
    for(int i = 1; i <= N; i++){
        int a, b, c;
        cin >> a >> b >> c;
        tree[a][0] = b;
        tree[a][1] = c;
        parent[b] = a;
        parent[c] = a;
    }
}

int DFS(int node){

    int right = tree[node][1];
    if(right != -1) return DFS(right);
    else return node;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    Input();
    LAST = DFS(1);
    InOrder(1);
    cout << cnt - 1 << '\n';

    return 0;
}