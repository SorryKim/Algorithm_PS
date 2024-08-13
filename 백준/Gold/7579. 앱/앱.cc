#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;

    const int max_cost = 10000;
    vector<int> memory(N);
    vector<int> cost(N);
    vector<int> dp(max_cost + 1, -1);

    // input
    for (int i = 0; i < N; i++)
        cin >> memory[i];

    for (int i = 0; i < N; i++)
        cin >> cost[i];


    dp[0] = 0;

    for(int i = 0; i < N; i++){
        int now_cost = cost[i];
        int now_memory = memory[i];

        for(int j = max_cost; j >= now_cost; j--){
            if(dp[j - now_cost] != -1){
                dp[j] = max(dp[j], dp[j - now_cost] + now_memory);
            }
        }
    }
    for(int i = 0; i <= max_cost; i++){
        if(dp[i] >= M){
            cout << i <<'\n';
            return 0;
        }
    }

    return 0;
}
