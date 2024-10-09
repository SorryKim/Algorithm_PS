#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class SegmentTree {
public:

    vector<long long> tree;

    SegmentTree(int n) {
        int h = (int)ceil(log2(n));
        tree = vector<long long>(1 << (h + 1), 0);
    }

    void Modify(int node, int start, int end, int idx, long long value) {
        if (start == end) 
            tree[node] = value;
        else {
            int mid = (start + end) / 2;
            if (idx <= mid) Modify(node * 2, start, mid, idx, value);
            else Modify(node * 2 + 1, mid + 1, end, idx, value);
            tree[node] = tree[node * 2] + tree[node * 2 + 1];
        }
    }

    long long Sum(int node, int start, int end, int left, int right) {
   
        if (right < start || end < left) 
            return 0;
        
        if (left <= start && end <= right)
            return tree[node];
        
        int mid = (start + end) / 2;
        return Sum(node * 2, start, mid, left, right) + Sum(node * 2 + 1, mid + 1, end, left, right);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    SegmentTree seg(N);
    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        
        // Sum
        if (a == 0) {
            if (b > c) 
                swap(b, c);
            cout << seg.Sum(1, 1, N, b, c) << '\n';
        }
        // Modify
        else if (a == 1) {
            seg.Modify(1, 1, N, b, c);
        }
    }
    
    return 0;
}
