#include <iostream>
#include <vector>
using namespace std;

int N, K;
vector<int> v;

void input(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> K;
    v.resize(N, 0);
    for(int i = 0; i < N; i++) cin >> v[i];
}

int solve(){

    int ans = 0;
    int left = 0;
    int remain = N;
    vector<bool> check(N, false);

    while(ans <= N){
        
        // 후보군 뽑기
        vector<int> temp;
        for(int i = 0; i < N; i++){
            if(!check[i]) temp.push_back(i);
            if(temp.size() == K) break;
        }

        // 다 나간 경우
        if(temp.size() == 0) return ans;

        bool out1 = false, out2 = false;

        for(int now : temp){
            int grade = v[now];
            
            if(grade == 1){
                if(!out1){
                    out1 = true;
                    check[now] = true;
                    remain--;
                }
            }else{
                if(!out2){
                    out2 = true;
                    check[now] = true;
                    remain--;
                }
            }
        }

       
        ans++;
        if(remain == 0) return ans;
    }
    
    return ans;

}

int main(){
    
    input();
    cout << solve() << "\n";

}