#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<pair<int,int>> tree;
vector<vector<int>> level;
vector<int> width;

int cnt = 1;
int root = 1;

pair<int, int> GetAnswer(){

    int idx = 0;
    int ans = 0;

    // 레벨별로 너비의 최댓값을 비교
    for(int i = 1; i <= N; i++){
        vector<int> temp;
        for(int n : level[i]){
            for(int j = 1; j <= N; j++){
                if(n == width[j]){
                    temp.push_back(j);
                    break;
                }
            }
        }

        if(temp.empty()) continue;
        sort(temp.begin(), temp.end());
        int val = temp.back() - temp[0] + 1;

        if(val > ans){
            idx = i;
            ans = val;
        }
    }
    
    return {idx, ans};
}
// 중위순회를 하며 너비 순서 정함
void DFS(int node){

    int left = tree[node].first;
    int right = tree[node].second;

    if(left != -1) DFS(left);

    width[cnt] = node;
    cnt++;

    if(right != -1) DFS(right);

    return;
}

// 노드별 레벨 설정
void SetLevel(int node, int height){
    
    level[height].push_back(node);

    int left = tree[node].first;
    int right = tree[node].second;

    if(left != -1) SetLevel(left, height + 1);
    if(right != -1) SetLevel(right, height + 1);

    return;
}

void Input(){
    
    cin >> N;
    tree.resize(N + 1);
    level.resize(N + 1);
    width.resize(N + 1, -1);

    vector<bool> check(N + 1, false);

    for(int i = 1; i <= N; i++){
        int node, left, right;

        cin >> node >> left >> right;
        tree[node].first = left;
        tree[node].second = right;

        if(left != -1) check[left] = true;
        if(right != -1) check[right] = true;
    }

    // 루트 노드 찾기
    for(int i = 1; i <= N; i++){
        if(!check[i]){
            root = i;
            break;
        }
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    Input();
    SetLevel(root,1);
    DFS(root);
    pair<int,int> answer = GetAnswer();
    cout << answer.first  << " " << answer.second << "\n";

    return 0;
}