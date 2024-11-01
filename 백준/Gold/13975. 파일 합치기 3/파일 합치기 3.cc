#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    while(T--){
        int K;
        cin >> K;
        
        priority_queue<long long, vector<long long>, greater<long long>> pq;

        for(int i = 0; i < K; i++){
            long long num;
            cin >> num;
            pq.push(num);
        }

        long long answer = 0;

        // 파일을 하나로 합치기
        while(pq.size() > 1){
            long long a = pq.top();
            pq.pop();
            long long b = pq.top();
            pq.pop();

            long long sum = a + b;
            answer += sum;
            pq.push(sum);
        }
        
        cout << answer << '\n';
    }
    
    return 0;
}
