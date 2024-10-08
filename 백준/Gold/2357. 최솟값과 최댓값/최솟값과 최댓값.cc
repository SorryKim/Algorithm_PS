#include <iostream>
#include <vector>
#include <cmath>
#include <climits> // INT_MAX와 INT_MIN 사용

using namespace std;

class SegmentTree{
public:
    int height;
    vector<int> max_tree;
    vector<int> min_tree;

    SegmentTree(int h){
        int size = (int)ceil(log2(h));
        height = 1 << (size + 1);
        max_tree.resize(height);
        min_tree.resize(height);
    }

    void Build(vector<int> &v, int node, int start, int end){

        if(start == end){
            max_tree[node] = v[start];
            min_tree[node] = v[start];
        }
        else{
            int mid = (start + end) / 2;
            Build(v, node * 2, start, mid);
            Build(v, node * 2 + 1, mid + 1, end);
            max_tree[node] = max(max_tree[node * 2], max_tree[node * 2 + 1]);
            min_tree[node] = min(min_tree[node * 2], min_tree[node * 2 + 1]);
        }
    }

    int Max(int node, int start, int end, int left, int right){
        if(right < start || end < left)
            return 0;
        
        if(left <= start && end <= right)
            return max_tree[node];
        
        int mid = (start + end) / 2;
        return max(Max(node * 2, start, mid , left, right), Max(node * 2 + 1, mid + 1, end, left, right)); 
    }

    int Min(int node, int start, int end, int left, int right){
        if(right < start || end < left)
            return 1e9;
        
        if(left <= start && end <= right)
            return min_tree[node];
        
        int mid = (start + end) / 2;
        return min(Min(node * 2, start, mid , left, right), Min(node * 2 + 1, mid + 1, end, left, right)); 
    }

};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    vector<int> v(N + 1, 0);
    
    for(int i = 1; i <= N; i++)
        cin >> v[i];
    
    SegmentTree segmentTree(N + 1);
    segmentTree.Build(v, 1, 1, N);

    for(int i = 1; i <= M; i++){
        int a,b;
        cin >> a >> b;
        cout << segmentTree.Min(1, 1, N, a, b) << " " << segmentTree.Max(1, 1, N, a, b) << '\n';
    }

    return 0;
}
