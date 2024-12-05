#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M;
    cin >> N >> M;
    vector<int> v(N);

    for(int i = 0; i < N; i++) cin >> v[i];

    int answer = 1e9;

    int left = 0;
    int right = 1e9;

    while(left <= right){

        int mid = (left + right) / 2; // 구간의 점수 최댓값

        int min_value = v[0]; // 구간의 최솟값
        int max_value = v[0]; // 구간의 최댓값
        int cnt = 1; // 구간의 갯수

        for(int i = 0; i  < N; i++){
            int now = v[i];
            min_value = min(min_value, now);
            max_value = max(max_value, now);
            
            int val = max_value - min_value;

            if(val > mid){
                cnt++;
                min_value = now;
                max_value = now;
            }
        }

        if(cnt > M) left = mid + 1;
        else {
            answer = mid;
            right = mid - 1;
        }
        
    }

    cout << answer << '\n';

    return 0;
}