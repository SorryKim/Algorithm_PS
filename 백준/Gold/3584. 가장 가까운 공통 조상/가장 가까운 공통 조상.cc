#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, D;
int graph[16][16];

// 해당 노드의 깊이를 반환하는 함수
int GET_DEPTH(int node, vector<int> &tree){
    int depth = 0;
    
    while(node != -1){
        node = tree[node];
        depth++;
    }

    return depth;
}

// 공통 조상 찾기
int NCA(int a, int b, vector<int> &tree){
    
    // 각 노드의 깊이
    int depthA = GET_DEPTH(a, tree);
    int depthB = GET_DEPTH(b, tree);

    while(depthA > depthB){
        a = tree[a];
        depthA--;
    }
    
    while(depthB > depthA){
        b = tree[b];
        depthB--;
    }

    while(a != b){
        a = tree[a];
        b = tree[b];
    }

    return a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while(T--){
        int N;
        cin >> N;
        vector<int> tree(N + 1, -1);

        for(int i = 0; i < N - 1; i++){
            int a, b;
            cin >> a >> b;
            tree[b] = a;
        }

        int A,B;
        cin >> A >> B;

        cout << NCA(A, B, tree) << '\n';

    }

    return 0;
}
