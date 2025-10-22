#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, K;
vector<int> v;

void input(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> K;
    v.resize(N, 0);
    for (int i = 0; i < N; i++) cin >> v[i];
}

int solve(){

    queue<int> q1, q2;

    for (int i = 0; i < N; i++){
        if(v[i] == 1) q1.push(i);
        else q2.push(i);
    }

    int start = 0, remain = N, time = 0;

    while (start < N) {
        time++;

        int sz = min(remain, K);

        int end = start + sz;

        if(!q1.empty() && q1.front() < end){
            start++;
            remain--;
            q1.pop();
        }

        if(!q2.empty() && q2.front() < end){
            start++;
            remain--;
            q2.pop();
        }
    }

    return time;
}

int main() {
    input();
    cout << solve() << "\n";
    return 0;
}
