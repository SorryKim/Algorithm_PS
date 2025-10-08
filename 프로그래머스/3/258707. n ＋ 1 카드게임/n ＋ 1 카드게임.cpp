#include <string>
#include <vector>
#include <set>

using namespace std;

int N;
set<int> hand, pool;

int solution(int coin, vector<int> cards) {
    int answer = 0;
    N = cards.size();
    for(int i = 0; i < N / 3; i++) hand.insert(cards[i]);
    int idx = N / 3;
    
    while(idx < N){
        answer++;
        
        if(hand.empty()) return answer;
        pool.insert(cards[idx++]);
        pool.insert(cards[idx++]);
        bool pass = false;
        
        // 1. 손패에서 확인
        for(int a : hand){
            if(hand.find(N + 1 - a) != hand.end()){
                pass = true;
                hand.erase(a);
                hand.erase(N + 1 - a);
                break;
            }
        }
        if(pass) continue;
        
        // 2. pool + hand
        if(coin >= 1){
            for(int a : hand){
                if(pool.find(N + 1 - a) != pool.end()){
                    pass = true;
                    hand.erase(a);
                    pool.erase(N + 1 - a);
                    coin--;
                    break;
                }
            }
        }
        
        if(pass) continue;
        
        // 3. pool에서 2개
        if(coin >= 2){
            for(int a : pool){
                if(pool.find(N + 1 - a) != pool.end()){
                    pool.erase(a);
                    pool.erase(N + 1 - a);
                    pass = true;
                    coin -= 2;
                    break;
                }
            }
        }
        if(pass) continue;
        
        return answer;
    }
    
    answer++;
    return answer;
}