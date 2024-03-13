#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> v;

bool cmp(const int &a, const int &b) {
    string n1 = to_string(a);
    string n2 = to_string(b);
    
    int num1 = stoi(n1 + n2);
    int num2 = stoi(n2 + n1);
    
    
    return num1 > num2;
}

string solution(vector<int> numbers) {
    string answer = "";

    sort(numbers.begin(), numbers.end(), cmp);

    for (auto num : numbers) {
        answer += to_string(num);
    }
    
    bool flag = false;
    for(auto a : answer){
        if(a != '0')
            flag = true;
    }
    
    return flag ? answer : "0";
}
