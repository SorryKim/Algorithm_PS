#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    int T;
    cin >> T;

    while(T--){
        
        // input
        int N;
        cin >> N;
        vector<int> price(N);
        for(int i = 0; i < N; i++) cin >> price[i];

        long long answer = 0; // 얻은 이득
        vector<int> maxPrice(N, 0); // 해당날짜에 사면 팔 수있는 최대금액

        maxPrice[N - 1] = price[N - 1];

        for(int i = N - 2; i >= 0; i--){
            maxPrice[i] = max(price[i], maxPrice[i + 1]);
        }

        
        for(int i = 0; i < N; i++){
            // 이득을 볼 수 있는 경우 판매
            if(price[i] < maxPrice[i]) answer += maxPrice[i] - price[i];
        }
        
        cout << answer << '\n';
    }

    return 0;
}
