#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>


using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    const int MAX = 1000000;
    cin >> N;

    vector<int> F(MAX + 1, 0);    // 등장 빈도
    vector<int> V(N + 1, 0);
    vector<int> NGF(N + 1, -1);  // 오등큰수
    stack<int> st;

    for(int i = 1; i <= N; i++){
        int num;
        cin >> num;

        F[num]++;
        V[i] = num;
    }

    
    for(int i = 1; i <= N; i++){

        int now = V[i];

        // stack의 최댓값 갱신
        // i번째의 V값의 F와 st.top()인덱스의 V에서의 F와 비교
        while(!st.empty() && F[V[st.top()]] < F[now]){
            NGF[st.top()] = now;
            st.pop();
        }

        st.push(i);
    }
    
    
    for(int i = 1; i <= N; i++)
        cout << NGF[i] << " ";

    return 0;
}