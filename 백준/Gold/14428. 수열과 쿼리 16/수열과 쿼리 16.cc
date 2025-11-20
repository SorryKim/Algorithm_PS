#include <iostream>
#include <vector>

using namespace std;

class SegTree{
public:
    vector<int> tree; // 인덱스 값 저장
    vector<long long> arr; // 해당인덱스의 값 저장

    SegTree(int N){
        int temp = 1;
        while(temp < N) temp <<= 1;
        tree.resize(temp * 2, -1);
        arr.resize(N + 1);
    }

    // 인덱스끼리 비교 메소드
    int compare(int a, int b){
        if(a == -1) return b;
        if(b == -1) return a;

        if(arr[a] == arr[b]) return a < b ? a : b;

        return arr[a] < arr[b] ? a : b;
    }

    void build(int node, int start, int end){
        if(start == end){
            tree[node] = start;
            return;
        }

        int mid = (start + end) / 2;
        build(node * 2, start, mid);
        build(node * 2 + 1, mid + 1, end);

        tree[node] = compare(tree[node * 2], tree[node * 2 + 1]);
    }

    void update(int node, int start, int end, int idx, long long val){

        if(start == end){
            arr[idx] = val;
            tree[node] = idx;
            return;
        }

        int mid = (start + end) / 2;
        if(idx <= mid) update(node * 2, start, mid, idx, val);
        else update(node * 2 + 1, mid + 1, end, idx, val);

        tree[node] = compare(tree[node * 2], tree[node * 2 + 1]);
    }

    int find(int node, int start, int end, int left, int right){
        if(right < start || end < left) return -1;
        if(left <= start && end <= right) return tree[node];

        int mid = (start + end) / 2;
        int l = find(node * 2, start, mid, left, right);
        int r = find(node * 2 + 1, mid + 1, end, left, right);
        return compare(l, r);
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;

    cin >> N;
    SegTree seg(N);

    for(int i = 1; i <= N; i++) cin >> seg.arr[i];
    
    seg.build(1,1,N);

    cin >> M;
    while(M--){
        int t, a, b;
        cin >> t >> a >> b;

        if(t == 1) seg.update(1, 1, N, a, b);
        else cout << seg.find(1, 1, N, a, b) << '\n';
    }
    
    return 0;
}