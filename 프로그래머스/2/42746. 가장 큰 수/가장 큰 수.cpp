#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool cmp(const int &a, const int &b){
    string s1 = to_string(a);
    string s2 = to_string(b);
    
    int n1 = stoi(s1 + s2);
    int n2 = stoi(s2 + s1);
    
    return n1 > n2;
}


string solution(vector<int> numbers) {
    string answer = "";
    sort(numbers.begin(), numbers.end(), cmp);
    
    int cnt = 0;
    for(int i : numbers){
        answer += to_string(i);
    }
    
    while(answer.size() > 1 && answer[0] == '0'){
        answer = answer.substr(1);
    }
    
    return answer;
}