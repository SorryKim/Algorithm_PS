#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N;
    vector<long long> v(N + 1, 0);
    v[0] = 0;

    for(int i = 1; i <= N; i++){
        cin >> v[i];
        v[i] += v[i - 1];
    }

    cin >> M;

    while(M--){
        int a, b;
        cin >> a >> b;
        cout << v[b] - v[a - 1] << "\n";
    }
   
    return 0;
}