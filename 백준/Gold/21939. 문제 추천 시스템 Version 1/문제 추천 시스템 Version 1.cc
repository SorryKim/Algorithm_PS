#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>

using namespace std;

int N, M;
struct Problem{
    int p, l;
    
    bool operator<(const Problem &other) const {
        if(l == other.l) return p > other.p;
        return l > other.l;
    }
};

set<Problem> problems;
unordered_map<int, int> level;

void input(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    
    for(int i = 0; i < N; i++){
        int P, L;
        cin >> P >> L;
        problems.insert({P,L});
        level[P] = L;
    }
}

void solve(){

    cin >> M;
    for(int i = 0; i < M; i++){
        string cmd;
        cin >> cmd;

        if(cmd == "recommend"){
            int x;
            cin >> x;

            // 가장 어려운 문제 번호 출력
            // 가장 어려운 문제가 여러개라면 문제번호 큰거 출력
            if(x == 1){
                Problem problem = *problems.begin();
                cout << problem.p << "\n";
            }
            // 가장 쉬운 문제 번호 출력
            // 여러개라면 문제 번호가 가장 작은 것 출력
            else{
                Problem problem = *problems.rbegin();
                cout << problem.p << "\n";
            }
        }else if(cmd == "add"){
            int P, L;
            cin >> P >> L;
            problems.insert({P, L});
            level[P] = L;
        }else if(cmd == "solved"){
            int P;
            cin >> P;
            int L = level[P];
            problems.erase({P,L});
            level.erase(P);
        }
    }

}

int main(){

    input();
    solve();
}