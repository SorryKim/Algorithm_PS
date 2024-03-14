#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <unordered_set>

using namespace std;


vector<pair<int, vector<int>>> parsing(string s){
    
    vector<pair<int, vector<int>>> sets; // {집합 크기, 집합} 으로 이루어진 벡터

    // 문자열 파싱하여 집합 추출
    stringstream ss(s.substr(2, s.size() - 4)); // 양 끝의 {{와 }}를 제거하고 파싱
    string token;
    while (getline(ss, token, '{')) {
        if (token.empty()) continue;
        stringstream token_ss(token);
        vector<int> temp_set;
        string element;
        while (getline(token_ss, element, ',')) {
            temp_set.push_back(stoi(element));
        }
        sets.push_back({temp_set.size(), temp_set});
    }
    
    return sets;
}

vector<int> solution(string s) {
    vector<int> answer;
    vector<pair<int, vector<int>>> sets; // {집합 크기, 집합} 으로 이루어진 벡터

    sets = parsing(s);

    // 집합 크기순으로 정렬
    sort(sets.begin(), sets.end());

    // 결과에 추가
    for (const auto& set_pair : sets) {
        for (int num : set_pair.second) {
            if (find(answer.begin(), answer.end(), num) == answer.end()) {
                answer.push_back(num);
                break;
            }
        }
    }

    return answer;
}
