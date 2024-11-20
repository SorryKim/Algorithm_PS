#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

bool check[200001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    string s;
    cin >> n >> s;

    int answer = 0;
    stack<int> st;

    for(int i = 0; i < n; i++){
        char now = s[i];

        if(now == '('){
            st.push(i);

        }else{
            if(!st.empty()){
                for(int j = st.top(); j <= i; j++)
                    check[j] = true;
                st.pop(); 
            }
        }
    }

    int temp = 0;
    for(int i = 0; i < n; i++){
        if(!check[i])
            temp = 0;
        else{
            temp++;
            answer = max(answer, temp);
        }
    }

    cout << answer << '\n';
    return 0;
}