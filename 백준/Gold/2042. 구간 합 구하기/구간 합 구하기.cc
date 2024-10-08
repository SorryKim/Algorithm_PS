#include <iostream>
#include <vector>
#include <cmath> // log2와 ceil을 사용하기 위해 추가

using namespace std;

int N, M, K;

class SegmentTree {
public:
    vector<long long> tree;
    int size;

    SegmentTree(int n) {
        int h = (int)ceil(log2(n));
        size = pow(2, h + 1);
        tree.resize(size);
    }

    void Build(vector<long long>& v, int node, int start, int end) {
        
        // 리프 노드인 경우
        if (start == end) 
            tree[node] = v[start];
        else {
            int mid = (start + end) / 2;
            Build(v, node * 2, start, mid);
            Build(v, node * 2 + 1, mid + 1, end);
            tree[node] = tree[node * 2] + tree[node * 2 + 1];
        }
    }

    // 점 업데이트를 위한 함수
    void Update(int node, int start, int end, int idx, long long value) {
        
        if (start == end) 
            tree[node] = value;
        else {
            int mid = (start + end) / 2;
            if (idx <= mid) Update(node * 2, start, mid, idx, value);
            else Update(node * 2 + 1, mid + 1, end, idx, value);
            tree[node] = tree[node * 2] + tree[node * 2 + 1];
        }
    }

    // 구간 합 쿼리를 위한 함수
    long long Sum(int node, int start, int end, int left, int right) {
        
        // 원하는 범위 아닌 경우
        if (right < start || end < left) 
            return 0;
        
        if (left <= start && end <= right)
            return tree[node];

        // 일부만 겹침
        int mid = (start + end) / 2;
        return Sum(node * 2, start, mid, left, right) + Sum(node * 2 + 1, mid + 1, end, left, right);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M >> K;

    vector<long long> v(N);

    for (int i = 0; i < N; i++)
        cin >> v[i];

    SegmentTree seg(N);
    seg.Build(v, 1, 0, N - 1);

    for (int i = 0; i < M + K; i++) {
        int a,b;
        long long c;
        cin >> a >> b >> c;

        if (a == 1) seg.Update(1, 0, N - 1, b - 1, c);
        else cout << seg.Sum(1, 0, N - 1, b - 1, c - 1) << '\n';
    }

    return 0;
}
