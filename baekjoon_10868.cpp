// 최솟값 / baekjoon_10868.cpp
// https://www.acmicpc.net/problem/10868

#include <iostream>
#include <algorithm>
using namespace std;

#define INF 2000000000

int N, M;
int arr[100001];
int tree[400000];
pair<int, int> quest[100001];

void Input() {

    cin >> N >> M;
    for (int i = 1; i <= N; i++)
        cin >> arr[i];

    for (int i = 1; i <= M; i++) {
        int a, b;
        cin >> a >> b;
        quest[i] = { a,b };
    }
    
}

int makeTree(int start, int end, int node) {
    
    // 세그먼트 트리 갱신
    if (start == end) {
        tree[node] = arr[start];
        return tree[node];
    }

    int mid = (start + end) / 2;
    int left = makeTree(start, mid, node * 2);
    int right = makeTree(mid + 1, end, node * 2 + 1);
    tree[node] = min(left, right);

    return tree[node];
}

int func(int start, int end, int left, int right, int node) {
    
    // 불가능한 경우
    if (left > end || right < start)
        return INF;
    
    // 범위 넘어가는 경우 세그먼트 트리값 반환
    if (left <= start && right >= end)
        return tree[node];

    int mid = (start + end) / 2;
    int leftResult = func(start, mid, left, right, node * 2);
    int rightResult = func(mid + 1, end, left, right, node * 2 + 1);

    return min(leftResult, rightResult);
}

void Solve() {
    
    makeTree(1, N, 1);
    for (int i = 1; i <= M; i++) {
        
        int start = quest[i].first;
        int end = quest[i].second;

        cout << func(1, N, start, end, 1) << "\n";
    }

}

int main() {
 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Input();
    Solve();
}
