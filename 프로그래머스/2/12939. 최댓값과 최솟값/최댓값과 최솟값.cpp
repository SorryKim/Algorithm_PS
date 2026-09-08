#include <string>
#include <vector>
#include <sstream>
#include <cmath>
#include <climits>
#include <iostream>

using namespace std;

string solution(string s) {
    string answer = "";
    stringstream ss(s);
    vector<int> numbers;
    int number;
    while(ss >> number){
        numbers.push_back(number);
    }
    
    int minV = INT_MAX;
    int maxV = INT_MIN;
    
    for(int num : numbers){
        minV = min(minV, num);
        maxV = max(maxV, num);
    }
    
    answer = to_string(minV) + " " + to_string(maxV);
    return answer;
}