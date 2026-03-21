#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int N;
vector<int> v;

void input(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    v.resize(N);

    for(int i = 0; i < N; i++) cin >> v[i];

    return;
}

string solve(){

    stack<int> st;
    int target = 1;

    for(int now : v){

        while(!st.empty() && target == st.top()){
            target++;
            st.pop();
        }

        if(target == now){
            target++;
            continue;
        }else st.push(now);
    }

    // 남은 사람 처리
    while(!st.empty()){
        if(target != st.top()) break;
        target++;
        st.pop();
    }

    if(target == N + 1 && st.empty()) return "Nice";
    else return "Sad";
}

int main(){
    
    input();
    cout << solve() << "\n";

    return 0;
}