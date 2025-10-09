#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> answer(2, 0);
    int N = emoticons.size();
    int total = pow(4, N);
    
    for(int mask = 0; mask <= total; mask++){
        
        vector<int> dc(N, 0);
        int temp = mask;
        
        // 조합 디코딩
        for(int i = N - 1; i >= 0; i--){
            int val = temp % 4;
            dc[i] = 10 + val * 10;
            temp /= 4;
        }
        
        // 현재 조합으로 계산
        int cnt = 0;
        int amount = 0;
        
        for(auto &user : users){
            int sum = 0;
            for(int i = 0; i < N; i++){
                if(user[0] <= dc[i]) sum += emoticons[i] * (100 - dc[i]) / 100; 
            }
            
            if(sum >= user[1]) cnt++;
            else amount += sum;
        }
        
        if(cnt > answer[0]){
            answer[0] = cnt;
            answer[1] = amount;
        }
        else if(cnt == answer[0]) answer[1] = max(answer[1], amount);
    }
    
    return answer;
}