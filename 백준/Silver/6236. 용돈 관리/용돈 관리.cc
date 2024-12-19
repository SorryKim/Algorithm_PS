#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;

    vector<int> money(N);
    for(int i = 0; i < N; i++) cin >> money[i];

    int left = 0;
    int right = 100000;
    int answer = 1e9;
    
    while(left <= right){
        
        int mid = (left + right) / 2;

        int remain = mid;
        int cnt = 1;
        for(int i = 0; i < N; i++){
            if(remain >= money[i])
                remain -= money[i];
            else{
                // 돈이 부족해서 인출
                remain = mid;
                cnt++;
                // 인출해도 부족한 경우
                if(remain < money[i]){
                    cnt = 1e9;
                    break;
                }
                remain -= money[i];
            }
        }

        if(cnt > M){
            left = mid + 1;
        }else{
            answer = min(answer, mid);
            right = mid - 1;
        }
        
    }

    cout << answer << '\n';
    

    return 0;
}
