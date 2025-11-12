#include <iostream>
#include <vector>

using namespace std;

int N;
vector<vector<int>> v;
int ans = 0;

void input(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;

    for(int i = 0; i < N; i++){
        vector<int> temp;
        for(int j = 0; j < 9; j++){
            int num;
            cin >> num;
            temp.push_back(num);
        }
        v.push_back(temp);
    }

}

int calc(vector<int> &order){

    int score = 0;
    int inning = 0;
    int out = 0;
    int idx = 0;
    vector<bool> base(3, false);

    while(inning != N){

        // 타자 선정
        int batter = order[idx];
        idx = (idx + 1) % 9;
        // 결과
        int result = v[inning][batter];
        
        // 아웃
        if(result == 0){
            out++;
        }
        // 안타
        else if(result == 1){
            if(base[2]){
                base[2] = false;
                score++;
            }

            if(base[1]){
                base[1] = false;
                base[2] = true;
            }

            if(base[0]){
                base[1] = true;
                base[0] = false;
            }

            base[0] = true;
        }
        // 2루타
        else if(result == 2){
            if(base[2]){
                base[2] = false;
                score++;
            }

            if(base[1]){
                base[1] = false;
                score++;
            }

            if(base[0]){
                base[0] = false;
                base[2] = true;
            }

            base[1] = true;
        }
        // 3루타
        else if(result == 3){
            if(base[2]){
                base[2] = false;
                score++;
            }

            if(base[1]){
                base[1] = false;
                score++;
            }

            if(base[0]){
                base[0] = false;
                score++;
            }
            base[2] = true;
        }
        // 홈런
        else if(result == 4){
            if(base[2]){
                base[2] = false;
                score++;
            }

            if(base[1]){
                base[1] = false;
                score++;
            }

            if(base[0]){
               base[0] = false;
               score++;
            }
            score++;
        }
        
        if(out == 3){
            inning++;
            out = 0;
            base = vector<bool>(3, false);
        }
    }

    return score;
}

void comb(int idx, int mask, vector<int> &order) {
    
    // 모든 타순이 다 채워졌다면 시뮬레이션 실행
    if (idx == 9) {
        ans = max(ans, calc(order));
        return;
    }

    // 4번 타자는 이미 1번 선수로 고정
    if (idx == 3) {
        comb(idx + 1, mask, order);
        return;
    }

    // 아직 배치되지 않은 선수들 중에서 선택
    for (int i = 1; i < 9; i++) {
        if (mask & (1 << i)) continue;

        order[idx] = i;
        comb(idx + 1, mask | (1 << i), order);
        order[idx] = 0;  // 백트래킹 (다음 경우를 위해 초기화)
    }
}

void solve(){

    // 1. 조합짜기
    vector<int> order(9,0);
    comb(0, 1 << 0, order);
   
}

int main(){
    input();
    solve();
    cout << ans << "\n";
    return 0;
}