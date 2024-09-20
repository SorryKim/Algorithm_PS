#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    string U;
    cin >> N >> U;

    vector<char> v;

    
    // N이 짝수인 경우
    // 불가능함
    if(N % 2 == 0)
        cout << "NOT POSSIBLE\n";
    else{
        string answer = "";
        string s1 = "";
        string s2 = "";
        
        // 0. 중앙이 다른경우
        for(int i = 0 ; i < N / 2; i++)
            s1 += U[i];
        
        for(int i = N/2 + 1 ; i < N; i++)
            s2 += U[i];

        if(s1 == s2)
            answer = s1;
        
        // 1. 중앙 기준 오른쪽 문자열에 문자를 추가한 경우
        s1 = "";
        s2 = "";
        for(int i = 0 ; i < N / 2; i++)
            s1 += U[i];
        
        for(int i = N/2 ; i < N; i++)
            s2 += U[i];
        
        bool flag = false;
        bool ans = true; // 성립 여부

        for(int i = 0; i < N/2; i++){
            
            char ch1 = s1[i];
            char ch2 = flag ? s2[i + 1] : s2[i];

            if(ch1 != ch2 & flag){
                ans = false;
                break;
            }

            // 다른 것 발견
            if(ch1 != ch2 && !flag){
                flag = true;
                
                if(ch1 != s2[i + 1]){
                    ans = false;
                    break;
                }
            }
        }
        
        if(ans)
            answer = s1;

        // 2. 중앙 기준 왼쪽 문자열에 문자를 추가한 경우
        s1 = "";
        s2 = "";
        ans = true;
        flag = false;

        for(int i = 0 ; i <= N / 2; i++)
            s1 += U[i];
        
        for(int i = N/2  + 1; i < N; i++)
            s2 += U[i];

        
        for(int i = 0; i < N/2; i++){
            
            char ch1 = flag ? s1[i + 1] : s1[i];
            char ch2 = s2[i];

            if(ch1 != ch2 & flag){
                ans = false;
                break;
            }

            // 다른 것 발견
            if(ch1 != ch2 && !flag){
                flag = true;
                
                if(ch2 != s1[i + 1]){
                    ans = false;
                    break;
                }
            }
        }

        if(ans){
            if(answer == "")
                answer = s2;
            else{
                if(answer != s2)
                    answer = "NOT UNIQUE";
            }
        }

        if(answer == "")
            cout <<  "NOT POSSIBLE";
        else
            cout << answer;
    }

    return 0;
}
