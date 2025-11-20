#include <iostream>
#include <vector>

using namespace std;

vector<int> input;
const long long INF = 11e9;
int idx = 0;

class SegTree{
public:

    vector<long long> tree;

    SegTree(int N){
        int size = 1;
        while(size < N) size <<= 1;
        tree.resize(size * 2, INF);
    }

    void build(int node, int start, int end){

        if(start == end){
            tree[node] = input[idx++];
            return;
        }

        int mid = (start + end) / 2;
        build(node * 2, start, mid);
        build(node * 2 + 1, mid + 1, end);
        tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
    }


    // 특정 idx의 값 갱신
    void update(int node, int start, int end, int idx, long long val){
        if(start == end){
            tree[node] = val;
            return;
        }

        int mid = (start + end) / 2;
        if(idx <= mid) update(node * 2, start, mid, idx, val);
        else update(node * 2 + 1, mid + 1, end, idx, val);

        // 부모 갱신
        tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
    }


    long long find(int node, int start, int end, int left, int right){

        if(left > end || right < start) return INF;
        if(left <= start && right >= end) return tree[node];

        int mid = (start + end) / 2;

        return min(find(node * 2, start , mid, left, right), find(node * 2 + 1, mid + 1, end, left, right));
    }


};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;

    cin >> N;
    input.resize(N);
    SegTree seg(N);
    for(int i = 0; i < N; i++) cin >> input[i];

    seg.build(1, 1, N);
    cin >> M;
    while(M--){
        int t, a;
        long long b;
        cin >> t >> a >> b;

        if(t == 1) seg.update(1, 1, N, a, b);
        else if(t == 2) cout << seg.find(1, 1, N, a, b) << '\n';
    }

    return 0;
}