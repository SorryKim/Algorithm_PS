#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// 전처리 함수
// 문자열길이를 홀수로 전환

string Pre(const string& s) {
    string temp = "#";
    
    for (char ch : s) {
        temp += ch;
        temp += "#";
    }
    
    return temp;
}
 
// 마나커 알고리즘
vector<int> Manacher(const string& s) {
    
    string temp = Pre(s);
    int n = temp.size();
    vector<int> P(n, 0);
    
    int center = 0, right = 0;
    
    for (int i = 0; i < n; i++) {
        
        int left = 2 * center - i;
        
        if (i <= right)
            P[i] = min(right - i, P[left]);

        // 중심에서 확장
        while (i + (P[i] + 1) < n && i - (P[i] + 1) >= 0 && temp[i + (P[i] + 1)] == temp[i - (P[i] + 1)]){
            P[i]++;
        }

        // 범위 넘어갔을 경우 새로운 중심 설정
        if ((i + P[i]) > right) {
            center = i;
            right = i + P[i];
        }
    }
    return P;
}
    
int solution(string s){
    int answer=0;

    vector<int> v = Manacher(s);
    
    
    sort(v.begin(), v.end());
    
    answer = v[v.size() - 1];
    
    return answer;
}