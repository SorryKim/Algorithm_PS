#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<vector<int>> tree;

// bottom - up

int DFS(int node){

    // 리프 노드인 경우
    if(tree[node].empty()) return 0;

    vector<int> times;
    for(int child : tree[node]) times.push_back(DFS(child));
    
    // 자식이 많은 노드부터
    sort(times.begin(), times.end(), greater<int>());

    int result = 0;

    for(int i = 0; i < times.size(); i++){

        // i를 통해 한번에 한명씩 연락
        result = max(result, (times[i] + 1) + i);
    }

    return result;
}


void Input(){

    cin >> N;
    tree.resize(N);

    for(int i = 0; i < N; i++){
        int node;
        cin >> node;
        if(node == -1) continue;
        tree[node].push_back(i);
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    Input();
    cout << DFS(0) << '\n';
    
    return 0;
}