#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class SegmentTree {
public:
    vector<int> tree;
    vector<int> v;

    SegmentTree(int n, vector<int>& v) {
        this->v = v;
        int h = (int)ceil(log2(n));
        int size = pow(2, h + 1);
        tree.resize(size);
        Build(1, 0, n - 1);
    }

    // 분할정복에서 사용하기 위해 인덱스로 저장
    void Build(int node, int start, int end) {
        if (start == end)
            tree[node] = start;
        else {
            int mid = (start + end) / 2;
            Build(node * 2, start, mid);
            Build(node * 2 + 1, mid + 1, end);
            int left = tree[node * 2];
            int right = tree[node * 2 + 1];
            tree[node] = (v[left] < v[right]) ? left : right; 
        }
    }

    // 구간에서 최소 높이 인덱스를 찾는 함수
    int getIdx(int node, int start, int end, int left, int right) {
        if (start > right || end < left)
            return -1;

        if (start >= left && end <= right)
            return tree[node];

        int mid = (start + end) / 2;
        int leftIdx = getIdx(node * 2, start, mid, left, right);
        int rightIdx = getIdx(node * 2 + 1, mid + 1, end, left, right);

        if (leftIdx == -1) return rightIdx;
        if (rightIdx == -1) return leftIdx;
        return (v[leftIdx] < v[rightIdx]) ? leftIdx : rightIdx;
    }
};

// 최대 사각형 넓이 계산을 위한 분할정복
long long getMaxArea(SegmentTree& segTree, int start, int end) {
    if (start > end)
        return 0;

    int minIdx = segTree.getIdx(1, 0, segTree.v.size() - 1, start, end);
    long long area = (long long)(end - start + 1) * segTree.v[minIdx];

    long long leftArea = getMaxArea(segTree, start, minIdx - 1);
    long long rightArea = getMaxArea(segTree, minIdx + 1, end);

    return max(area, max(leftArea, rightArea));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (true) {
        int n;
        cin >> n;
        if (n == 0) return 0;

        vector<int> v(n);
        for (int i = 0; i < n; i++) cin >> v[i];

        SegmentTree segTree(n, v);
        cout << getMaxArea(segTree, 0, n - 1) << '\n';
    }
}
