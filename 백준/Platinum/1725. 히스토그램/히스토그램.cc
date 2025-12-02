#include <iostream>
#include <vector>

using namespace std;

class SegTree{
public:
    int N;
    vector<int> tree; // 트리에는 인덱스 저장
    vector<int> height;

    SegTree(int N){
        this->N = N;
        int size = 1;
        while(size < N) size <<= 1;
        tree.resize(size * 2, 0);
        height.resize(N + 1, 0);
    }

    // 인덱스 기반 높이비교 함수
    // 결과값으로 낮은 높이의 인덱스를 반환
    int cmp(int a, int b){
        if(a == 0) return b;
        if(b == 0) return a;
        return height[a] < height[b] ? a : b;
    }


    void build(int node, int start, int end){
        if(start == end){
            tree[node] = start;
            return;
        }
        int mid = (start + end) / 2;
        build(node * 2, start, mid);
        build(node * 2 + 1, mid + 1, end);
        tree[node] = cmp(tree[node * 2], tree[node * 2 + 1]);
    }

    int find(int node, int start, int end, int left, int right){
        if(start > right || end < left) return 0;
        if(start >= left && end <= right) return tree[node];

        int mid = (start + end) / 2;
        return cmp(find(node * 2, start, mid, left, right), find(node * 2 + 1, mid + 1, end, left, right));
    }

    long long solve(int start, int end){
        if(start > end) return 0;

        // [start, end] 구간 최소값의 인덱스
        int idx = find(1, 1, N, start, end);
        int h = height[idx];

        long long area = (end - start + 1) * h;
        
        long long left = solve(start, idx - 1);
        long long right = solve(idx + 1, end);

        return max(area, max(left, right));
    }
};



int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    SegTree seg(N);
    for(int i = 1; i <= N; i++) cin >> seg.height[i];
    seg.build(1, 1, N);
    cout << seg.solve(1, N) << "\n";
    
    return 0;
}