#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    vector<int> v(N);
    for(int i = 0; i < N; i++)
        cin >> v[i];
    
    sort(v.begin(), v.end());

    long long answer = 0;
    
    for(int a = 0; a < N - 2; a++){
        for(int b = a + 1; b < N - 1; b++){
            
            // 두 수를 고정하고 나머지 범위에서 이분탐색으로 1가지 수를 찾음
            int num = -1*(v[a] + v[b]);

            int left = b + 1;
            int right = N - 1;

            // 중복되는 수가 존재하기 때문에 upper와 lower를 사용해 범위로 구함
            auto lower = lower_bound(v.begin() + left, v.end(), num);
            auto upper = upper_bound(v.begin() + left, v.end(), num);
            answer += (upper - lower);
        }
    }
    

    cout << answer;
    return 0;
}