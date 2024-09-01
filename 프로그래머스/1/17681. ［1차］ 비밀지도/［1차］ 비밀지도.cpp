#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

// 2진수로 변환하는 메소드
string Change(int n, int size){
    
    string result = "";
    while(n != 0){
        
        result += to_string(n % 2);
        n /= 2;
    }
    
    while(result.size() != size)
        result += '0';
    
    reverse(result.begin(), result.end());
    return result;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    
    for(int i = 0; i < n; i++){
        string s1 = Change(arr1[i], n);
        string s2 = Change(arr2[i], n);
        string result = "";
        for(int j = 0; j < n; j++){
            int n1 = s1[j] - '0';
            int n2 = s2[j] - '0';
            if(n1 || n2 == 1)
                result += '#';
            else
                result += ' ';
        }
        
        answer.push_back(result);
    }
    
    return answer;
}