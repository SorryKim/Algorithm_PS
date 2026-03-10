#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Log {
    int t, a, b;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, K;
    cin >> N >> M >> K;

    vector<int> infectedFinal(N + 1, 0);

    for(int i = 0; i < K; i++){
        int x;
        cin >> x;
        infectedFinal[x] = 1;
    }

    vector<Log> logs(M);

    for(int i = 0; i < M; i++){
        cin >> logs[i].t >> logs[i].a >> logs[i].b;
    }

    sort(logs.begin(), logs.end(), [](Log &x, Log &y){
        return x.t < y.t;
    });

    for(int start = 1; start <= N; start++){

        vector<int> infected(N + 1, 0);
        infected[start] = 1;

        for(auto &log : logs){
            if(infected[log.a])
                infected[log.b] = 1;
        }

        bool ok = true;

        for(int i = 1; i <= N; i++){
            if(infected[i] != infectedFinal[i]){
                ok = false;
                break;
            }
        }

        if(ok){
            cout << start << "\n";
            return 0;
        }
    }

    return 0;
}