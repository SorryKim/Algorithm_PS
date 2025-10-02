#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

map<string, int> mp;

//  {연, 달, 일} 값 리턴
vector<int> splitDate(const string &s){
    vector<int> result;
    stringstream ss(s);
    string temp;
    
    while(getline(ss, temp, '.')){
        result.push_back(stoi(temp));
    }
        
    return result;
}

// n개월 후 날짜 반환
string calcDate(string date, int n){
    
    vector<int> temp = splitDate(date);
    int year = temp[0];
    int month = temp[1];
    int day = temp[2];
    
    month += n;
    
    if(month > 12){
        year += (month - 1) / 12;
        month = (month - 1) % 12 + 1;
    }
    
    string result = to_string(year) + "." + to_string(month) + "." + to_string(day);
    
    return result;
}

// date간 대소비교
bool isOver(string date, string endDate){
    vector<int> v1 = splitDate(date);
    vector<int> v2 = splitDate(endDate);
    
    // year 비교
    if(v1[0] > v2[0]) return true;
    
    if(v1[0] == v2[0] && v1[1] > v2[1]) return true;
    
    if(v1[0] == v2[0] && v1[1] == v2[1] && v1[2] >= v2[2]) return true;
    
    return false;
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    
    // 유효기간 map에 저장
    for (string term : terms) {
        int pos = term.find(' ');
        string code = term.substr(0, pos);
        int period = stoi(term.substr(pos + 1));
        mp[code] = period;
    }
    
    int idx = 0;
    for(string privacy : privacies){
        idx++;
        int pos = privacy.find(' ');
        string start = privacy.substr(0, pos);
        string code = privacy.substr(pos + 1);
        
        int duration = mp[code];
        
        // 만료날짜 계산
        string endDate = calcDate(start, duration);
        
        // 대소 비교
        bool b = isOver(today, endDate);
        if(b) answer.push_back(idx);
    }
    

    return answer;
}