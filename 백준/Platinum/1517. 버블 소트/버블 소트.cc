#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

using namespace std;

int N;
vector<int> v;

class SegmentTree {
public:
    vector<int> tree;

    SegmentTree(int n) {
        int h = (int)ceil(log2(n));
        int size = (1 << (h + 1));
        tree.resize(size, 0);
    }

    void Update(int node, int start, int end, int idx, int value) {
        if (idx < start || idx > end)
            return;
        if (start == end) {
            tree[node] += value;
            return;
        }
        int mid = (start + end) / 2;
        Update(node * 2, start, mid, idx, value);
        Update(node * 2 + 1, mid + 1, end, idx, value);
        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }

    int Sum(int node, int start, int end, int left, int right) {
        if (right < start || left > end)
            return 0;
        if (left <= start && end <= right)
            return tree[node];
        int mid = (start + end) / 2;
        return Sum(node * 2, start, mid, left, right) + Sum(node * 2 + 1, mid + 1, end, left, right);
    }
};

void Input() {
    cin >> N;
    v.resize(N);

    for (int i = 0; i < N; i++)
        cin >> v[i];

    // 좌표 압축
    vector<int> temp = v;
    sort(temp.begin(), temp.end());
    temp.erase(unique(temp.begin(), temp.end()), temp.end()); // 중복 제거

    map<int, int> compressed;
    for (int i = 0; i < temp.size(); i++)
        compressed[temp[i]] = i + 1;

    for (int i = 0; i < N; i++)
        v[i] = compressed[v[i]];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Input();

    SegmentTree seg(N);
    long long answer = 0;

    for (int i = N - 1; i >= 0; i--) {
        // 현재 값보다 작은 값들의 합을 구함
        answer += seg.Sum(1, 1, N, 1, v[i] - 1);
        // 현재 값 추가
        seg.Update(1, 1, N, v[i], 1);
    }

    cout << answer << '\n';
    return 0;
}
