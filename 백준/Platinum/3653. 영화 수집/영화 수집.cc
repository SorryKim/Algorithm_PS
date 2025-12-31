#include <iostream>
#include <vector>

using namespace std;

int N, M;

class SegmentTree{
public:

    vector<int> tree;

    SegmentTree(){
        int size = 1;
        while(size < N + M) size <<= 1;
        tree.resize(size * 2);
    }

    void build(int node, int start, int end){
        if(start == end){
            if(start >= M && start < M + N) tree[node] = 1;
            else tree[node] = 0;
            return;
        }

        int mid = (start + end) / 2;
        build(node * 2, start, mid);
        build(node * 2 + 1, mid + 1, end);
        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }

    // [left, right] 구간 합
    int query(int node, int start, int end, int left, int right){
        if(right < start || end < left) return 0;
        if(left <= start && end <= right) return tree[node];

        int mid = (start + end) / 2;
        
        return query(node * 2, start, mid, left, right) + query(node * 2 + 1, mid + 1, end, left, right);
    }

    void update(int node, int start, int end, int idx, int val){
        if(start == end){
            tree[node] = val;
            return;
        }

        int mid = (start + end) / 2;
        if(idx <= mid) update(node * 2, start, mid, idx, val);
        else update(node * 2 + 1, mid + 1, end, idx, val);
        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }

};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int TC;
    cin >> TC;

    while(TC--){
        cin >> N >> M;

        vector<int> v(M);
        for(int i = 0; i < M; i++) cin >> v[i];

        SegmentTree seg;
        seg.build(1, 0, N + M - 1);

        vector<int> pos(N + 1);
        for(int i = 1; i <= N; i++) pos[i] = M + i - 1;
        
        int top = M - 1;

        for(int i = 0; i < M; i++){
            int now = v[i];
            int above = seg.query(1, 0, N + M - 1, 0, pos[now] - 1);

            cout << above << " ";

            // 기존 위치 제거
            seg.update(1, 0, N + M - 1, pos[now], 0);

            // 맨 위로 이동
            seg.update(1, 0, N + M - 1, top, 1);
            pos[now] = top;
            top--;
        }

        cout << "\n";
    }

    return 0;

}