#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    int answer = 0;

    cin >> N;
    vector<int> v(N);
    for(int i = 0; i < N; i++) cin >> v[i];

    for(int i = N - 1; i > 0; i--){
        while(v[i - 1] >= v[i]){
            answer++;
            v[i - 1]--;
        }
    }
    cout << answer << '\n';
    
    return 0;
}
