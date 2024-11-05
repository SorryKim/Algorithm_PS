#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class SegmentTree {
public:
    vector<long long> tree;
    vector<long long> v;

    SegmentTree(int n, vector<long long> &v) {
        this->v = v;
        int h = (int)ceil(log2(n));
        int size = pow(2, h + 1);
        tree = vector<long long>(size, 0);
    }

    // 주어진 배열로 세그먼트 트리 구성
    void Build(int node, int start, int end) {
        // 리프노드
        if (start == end)
            tree[node] = v[start - 1];  // 1 기반이므로 v[start - 1] 사용
        else {
            int mid = (start + end) / 2;
            Build(node * 2, start, mid);
            Build(node * 2 + 1, mid + 1, end);
            tree[node] = tree[node * 2] + tree[node * 2 + 1];
        }
    }

    void Update(int node, int start, int end, int target, long long value) {
        if (start == end) {
            tree[node] = value;
        } else {
            int mid = (start + end) / 2;
            if (target <= mid)
                Update(node * 2, start, mid, target, value);
            else
                Update(node * 2 + 1, mid + 1, end, target, value);

            tree[node] = tree[node * 2] + tree[node * 2 + 1];
        }
    }

    long long Sum(int node, int start, int end, int left, int right) {
        if (start > right || end < left)
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
    int N, Q;
    cin >> N >> Q;
    vector<long long> v(N, 0);
    for (int i = 0; i < N; i++)
        cin >> v[i];

    SegmentTree segmentTree(N, v);
    segmentTree.Build(1, 1, N); 

    while (Q--) {
        int x, y, a, b;
        cin >> x >> y >> a >> b;
        if (x > y)
            swap(x, y);

        cout << segmentTree.Sum(1, 1, N, x, y) << '\n';
        segmentTree.Update(1, 1, N, a, b);
    }

    return 0;
}
