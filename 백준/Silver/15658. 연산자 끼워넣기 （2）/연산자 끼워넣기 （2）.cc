#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int ans1 = -1e9;
int ans2 = 1e9;
int N;

void DFS(int depth, int val, const vector<int> &num, vector<int> op){

    // 종료조건
    if(depth == N){
        ans1 = max(ans1, val);
        ans2 = min(ans2, val);
        return;
    }

    for(int i = 0; i < 4; i++){
        
        if(op[i] == 0)
            continue;
        
        op[i]--;

        // +
        if(i == 0)
            DFS(depth + 1, val + num[depth], num, op);
        // -
        else if(i == 1)
            DFS(depth + 1, val - num[depth], num, op);
        // *
        else if(i == 2)
            DFS(depth + 1, val * num[depth], num, op);
        // /
        else if(i == 3)
                DFS(depth + 1, val / num[depth], num, op); 
        op[i]++;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;

    vector<int> num(N, 0);
    vector<int> op(4, 0);

    for(int i = 0; i < N; i++)
        cin >> num[i];
    
    for(int i = 0; i < 4; i++)
        cin >> op[i];

    DFS(1, num[0], num, op);
    
    cout << ans1 << '\n';
    cout << ans2 << '\n';
    return 0;

}
