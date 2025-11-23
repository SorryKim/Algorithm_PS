#include <iostream>
#include <vector>

using namespace std;

class SegTree{
public:
    vector<int> arr;
    vector<int> tree1, tree2; // 짝홀 트리 1개씩, 갯수 기록

    SegTree(int N){
        int size = 1;
        while(size < N) size <<= 1;
        tree1.resize(size * 2, 0);
        tree2.resize(size * 2, 0);
        arr.resize(N + 1);
    }

    void build(int node, int start, int end){

        if(start == end){
            if(arr[start] % 2 == 0){
                tree1[node] = 1;
                tree2[node] = 0;
            }else{
                tree1[node] = 0;
                tree2[node] = 1;
            }
            return;
        }

        int mid = (start + end) / 2;
        build(node * 2, start, mid);
        build(node * 2 + 1, mid + 1, end);
        tree1[node] = tree1[node * 2] + tree1[node * 2 + 1];
        tree2[node] = tree2[node * 2] + tree2[node * 2 + 1];
    }

    // 갱신 메소드
    void update(int node, int start, int end, int idx){

        if(start == end){
            if(arr[idx] % 2 == 0){
                tree1[node] = 1;
                tree2[node] = 0;
            }else{
                tree1[node] = 0;
                tree2[node] = 1;
            }

            return;
        }

        int mid = (start + end) / 2;

        if(idx <= mid) update(node * 2, start, mid, idx);
        else update(node * 2 + 1, mid + 1, end, idx);

        tree1[node] = tree1[node * 2] + tree1[node * 2 + 1];
        tree2[node] = tree2[node * 2] + tree2[node * 2 + 1]; 
    }

    // 짝수 찾기
    int find1(int node, int start, int end, int left, int right){
        if(start > right || end < left) return 0;
        if(start >= left && end <= right) return tree1[node];

        int mid = (start + end) / 2;
        return find1(node * 2, start , mid, left, right) + find1(node * 2 + 1, mid + 1, end, left, right);
    }

    // 홀수 찾기
    int find2(int node, int start, int end, int left, int right){
        if(start > right || end < left) return 0;
        if(start >= left && end <= right) return tree2[node];

        int mid = (start + end) / 2;
        return find2(node * 2, start , mid, left, right) + find2(node * 2 + 1, mid + 1, end, left, right);
    }

    void print1(int node, int start, int end){

        if(start == end){
            cout << tree1[node] << " ";
            return;
        }

        cout << tree1[node] << " ";
        
        int mid = (start + end) / 2;
        print1(node * 2, start, mid);
        print1(node * 2, mid + 1, end);
    }

    void print2(int node, int start, int end){

        if(start == end){
            cout << tree2[node] << " ";
            return;
        }

        cout << tree2[node] << " ";
        
        int mid = (start + end) / 2;
        print2(node * 2, start, mid);
        print2(node * 2, mid + 1, end);
    }
};

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N;
    SegTree seg(N);

    for(int i = 1; i <= N; i++) cin >> seg.arr[i];
    seg.build(1, 1, N);

    cin >> M;

    while(M--){
        int t, l ,r;
        cin >> t >> l >> r;

        if(t == 1){
            seg.arr[l] = r;
            seg.update(1, 1, N, l);
        }
        else if(t == 2) cout << seg.find1(1, 1, N, l, r) << "\n";
        else if(t == 3) cout << seg.find2(1, 1, N, l, r) << "\n";
    }

    // cout << "짝트리\n";
    // seg.print1(1, 1, N);
    // cout << endl;
    // cout <<"홀트리\n";
    // seg.print2(1, 1, N);
    // cout << endl;

    // for(int i = 1; i <= N; i++) cout << seg.arr[i] << " ";

    return 0;
}