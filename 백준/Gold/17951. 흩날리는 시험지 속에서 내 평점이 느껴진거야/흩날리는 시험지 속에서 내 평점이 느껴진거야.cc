#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    cin >> N >> K;
    vector<int> v(N);

    int left = 0;
    int right = 0;
    int answer = 0;

    for(int i = 0; i < N; i++){
        cin >> v[i];
        left = max(left, v[i]); // 최대 원소 값부터 가능
        right += v[i];
    }
    
    while(left <= right){
        
        int mid = (left + right) / 2;
        int cnt = 0;
        int sum = 0;
        
        for(int i = 0; i < N; i++){
            sum += v[i];

            if(sum >= mid){
                cnt++;
                sum = 0;
            }
        }

        if(cnt < K)
            right = mid - 1;
        else{
            left = mid + 1;
            answer = mid;
        }
    }

    cout << answer << '\n';

    return 0;
}