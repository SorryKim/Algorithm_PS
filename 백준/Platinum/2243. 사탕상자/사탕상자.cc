#include <iostream>
#include <vector>

using namespace std;

const int MAX = 1000000;

class SegTree{
public:
    vector<int> tree;

    SegTree(){
        int size = 1;
        while(size < MAX) size <<= 1;
        tree.resize(size * 2, 0); 
    }

    // target의 수를 val만큼 변경
    void update(int node, int start, int end, int target, int val){
        if(target < start || target > end) return;
        tree[node] += val; // 누적합 기반

        if(start == end) return;

        int mid = (start + end) / 2;
        // 왼쪽 자식
        update(node * 2, start, mid, target, val);
        // 오른쪽 자식
        update(node * 2 + 1, mid + 1, end, target, val);
    }

    int find(int node, int start, int end, int target){
        
        if(start == end) return start;

        int mid = (start + end) / 2;

        if(tree[node * 2] >= target) return find(node * 2, start, mid, target);
        else return find(node * 2 + 1, mid + 1, end, target - tree[node * 2]);
    }

};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;

    SegTree segTree = SegTree();

    for(int i = 0; i < n; i++){
        int A, B, C;
        cin >> A;

        if(A == 1){
            cin >> B;
            // 꺼낸 사탕의 번호 출력
            int ans = segTree.find(1, 1, MAX, B);
            cout << ans << "\n";
            segTree.update(1, 1, MAX, ans, -1);
        }
        else{
            cin >> B >> C;
            // 사탕을 넣는 경우
            segTree.update(1, 1, MAX, B, C);
        }
    }
}