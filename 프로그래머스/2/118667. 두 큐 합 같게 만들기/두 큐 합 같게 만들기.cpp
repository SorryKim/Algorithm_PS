#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;
    queue<int> q1, q2;
    long long sum1 = 0, sum2 = 0;
    
    for(auto a : queue1){
        sum1 += a;
        q1.push(a);
    }
    
    for(auto b :queue2){
        sum2 += b;
        q2.push(b);
    }
    
    int max_cnt = 3 * queue1.size();
    
    while(sum1 != sum2 && answer < max_cnt){
        
        answer++;
        if(sum1 > sum2){
            int num = q1.front();
            q1.pop();
            sum1 -= num;
            sum2 += num;
            q2.push(num);
        }else{
            int num = q2.front();
            q2.pop();
            sum1 += num;
            sum2 -= num;
            q1.push(num);
        }
    }
    
    
    if(answer == max_cnt)
        return -1;
    
    return answer;
}