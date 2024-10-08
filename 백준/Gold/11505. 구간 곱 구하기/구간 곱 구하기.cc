#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int MOD = 1000000007;

class SegmentTree{
public:
    vector<long long> tree;

    SegmentTree(int size){
        int height = (int)ceil(log2(size));
        tree.resize(1 << (height + 1));
    }

    void Build(int node, int start, int end, vector<int> &v){
        
        if(start == end)
            tree[node] = v[start];
        else{
            int mid = (start + end) / 2;
            Build(node * 2, start, mid, v);
            Build(node * 2 + 1, mid + 1, end, v);
            tree[node] = ((tree[node * 2] % MOD) * (tree[node * 2 + 1] % MOD)) % MOD;  // tree[mid] -> tree[node]로 수정
        }
    }

    void Update(int node, int start, int end, int idx, int val){

        if(start == end)
            tree[node] = val;
        else{
            int mid = (start + end) / 2;
            if(idx <= mid)
                Update(node * 2, start, mid, idx, val);
            else
                Update(node * 2 + 1, mid + 1, end, idx, val);
            
            tree[node] = ((tree[node * 2] % MOD) * (tree[node * 2 + 1] % MOD)) % MOD; 
        }
    }

    long long Print(int node, int start, int end, int left, int right){

        if(start > right || end < left)
            return 1;
        
        if(left <= start && end <= right)
            return tree[node];
        
        int mid = (start + end) / 2;

        return ((Print(node * 2, start, mid, left, right) % MOD) * (Print(node * 2 + 1, mid + 1, end, left, right) % MOD)) % MOD;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M, K;
    cin >> N >> M >> K;

    vector<int> v(N + 1, 0); 
    for(int i = 1; i <= N; i++)
        cin >> v[i];
    
    SegmentTree seg(N); 
    seg.Build(1, 1, N, v);

    for(int i = 0; i < M + K; i++){

        int a,b,c;
        cin >> a >> b >> c;

        if(a == 1)
            seg.Update(1, 1, N, b, c);
        else
            cout << seg.Print(1, 1, N, b, c) << '\n'; 
    }

    return 0;
}
