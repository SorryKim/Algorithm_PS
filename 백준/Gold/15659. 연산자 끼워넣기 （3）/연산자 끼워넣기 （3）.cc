#include <iostream>
#include <vector>
#include <stack>
#include <cmath>
#include <string>

using namespace std;

int ans1 = -1e9;
int ans2 = 1e9;
int N;

// 연산자의 우선순위
int Check(char op){
    if (op == '*' || op == '/')
        return 2;
    return 1;
}

// 중위 표현식을 후위 표현식으로 변환하는 함수
vector<string> Convert(const vector<int>& num, const vector<char>& v) {
    stack<char> st;
    vector<string> result;
    
    int idx = 0;
    for (int i = 0; i < v.size(); i++) {

        result.push_back(to_string(num[idx]));
        idx++;

        while (!st.empty() && Check(st.top()) >= Check(v[i])) {
            result.push_back(string(1, st.top()));
            st.pop();
        }

        st.push(v[i]);
    }

    // 마지막 숫자 추가
    result.push_back(to_string(num[idx]));

     // 남아 있는 연산자 스택 비우기
    while (!st.empty()) { 
        result.push_back(string(1, st.top()));
        st.pop();
    }
    
    return result;
}

int Calc(vector<int> &num, vector<char> &v){

    vector<string> post = Convert(num, v);
    stack<int> st;

    for(auto &now: post){
        
        // 연산자인 경우
        if(now == "+" || now == "-" || now == "*" || now =="/"){
            int b = st.top();
            st.pop();
            int a = st.top();
            st.pop();

            int temp;
            if(now == "+")
                temp = a + b;
            else if(now == "-")
                temp = a - b;
            else if(now == "*")
                temp = a * b;
            else if(now == "/")
                temp = a / b;
                
            st.push(temp);

        }
        // 숫자인 경우
        else
            st.push(stoi(now));
        
    }
    
    return st.top();
}

void DFS(int depth, vector<char> v, vector<int> &num, vector<int> op){

    // 종료조건
    if(depth == N){
        
        //값 계산
        ans1 = max(Calc(num, v), ans1);
        ans2 = min(Calc(num, v), ans2);
        return;
    }

    for(int i = 0; i < 4; i++){
        
        if(op[i] == 0)
            continue;
        op[i]--;
        if(i == 0)
            v.push_back('+');
        else if(i == 1)
            v.push_back('-');
        else if(i == 2)
            v.push_back('*');
        else if(i == 3)
            v.push_back('/');
        DFS(depth + 1, v, num, op);

        // 백트래킹
        v.pop_back();
        op[i]++;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;

    vector<int> num(N, 0);
    vector<int> op(4, 0);

    for(int i = 0; i < N; i++)
        cin >> num[i];
    
    for(int i = 0; i < 4; i++)
        cin >> op[i];

    DFS(1, vector<char>(), num, op);
    
    cout << ans1 << '\n';
    cout << ans2 << '\n';
    return 0;

}
