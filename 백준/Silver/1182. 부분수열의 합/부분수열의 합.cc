#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, S;
long long ans;
vector<int> v;
vector<bool> visited;

void Input() {
   
    cin >> N >> S;
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        v.push_back(num);
        visited.push_back(false);
    }

}

void DFS(int n) {

    if (n == N) {
        long long sum = 0;

        for (int i = 0; i < N; i++) {
            if (visited[i]) {
                sum += v[i];
            }
        }

        if (sum == S)
            ans++;
        return;
    }

    visited[n] = true;
    DFS(n + 1);

    visited[n] = false;
    DFS(n + 1);
}



void Solve() {
    ans = 0; 
    DFS(0);

    if (S == 0)
        ans--;
    cout << ans << "\n";
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Input();
    Solve();

    return 0;
}


