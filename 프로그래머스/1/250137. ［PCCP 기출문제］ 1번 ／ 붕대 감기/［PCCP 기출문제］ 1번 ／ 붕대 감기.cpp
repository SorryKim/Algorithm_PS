#include <string>
#include <vector>

using namespace std;



// 해당 시간에 공격을 체크하는 함수
// 공격이 있다면 해당시간에 해당하는 데미지 리턴
int checkAttack(int now, const vector<vector<int>> &attacks){
    
    for(auto a : attacks){
        int time = a[0];
        
        if(now == time)
            return a[1];
    }
    
    return -1;
}


int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int answer = 0;
    int lastTime = attacks[attacks.size() -1][0]; // 몬스터의 마지막 공격 시간
    int temp = 0;
    int nowHealth = health;
    
    // bandage[0] = 시전시간
    // bandage[1] = 초당 회복량
    // bandage[2] = 시전시간까지 무사히 붕대감았을 경우 추가 회복량
    for(int i = 0; i <= lastTime; i++){
        
        int damage = checkAttack(i, attacks);
        
        // 몬스터의 공격이 없는 경우
        if(damage == -1){
            temp++;
            nowHealth += bandage[1];
            
            // 연속 회복을 성공한 경우
            if(temp == bandage[0]){
                temp = 0;
                nowHealth += bandage[2];
            }
            
            // 체력회복이 최대체력을 넘은 경우
            if(nowHealth > health)
                nowHealth = health;
        }
        else{
            temp = 0;
            nowHealth -= damage;
            if(nowHealth <= 0)
                return -1;
        }
        

        
    }
    return nowHealth;
}