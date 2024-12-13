#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // Input
    int N;
    cin >> N;
    vector<int> price(N);
    for(int i = 0; i < N; i++) cin >> price[i];
    int M;
    cin >> M;

    // Solve

    // 1. 최대 자릿수 구하기

    int min1_idx = 1;
    int min1 = 1e9; // 0을 제외한 최솟값
    for(int i = 1; i < N; i++){
        if(min1 > price[i]){
            min1 = price[i];
            min1_idx = i;
        }
    }
    
    int min2_idx = 0;
    int min2 = 1e9; // 0을 포함한 최솟값
    for(int i = 0; i < N; i++){
        if(min2 > price[i]){
            min2 = price[i];
            min2_idx = i;
        }
    }

    int temp = M - min1;
    // 방번호가 0밖에 안되는 경우
    if(temp < 0){
        cout << 0 << '\n';
        return 0;
    }

    M -= min1;
    
    int length = 1 + M / min2; // 최대길이
    int remain = M - min2 * (length - 1); // 남은 돈

    vector<int> answer(length, min2_idx);
    answer[0] = min1_idx;

    for(int i = 0; i < length; i++){

        for(int j = N - 1; j >= 0; j--){
            
            // 밑으로 가면 교체필요 x
            if(answer[i] == j) break;
            // 값차이
            int diff = price[j] - price[answer[i]];

            // 교체가능한 경우
            if(remain >= diff){
                answer[i] = j;
                remain -= diff;
                break;
            }
        }
    }


    for(auto num : answer) cout << num;
    cout << '\n';

    return 0;
}
