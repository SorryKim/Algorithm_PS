#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<string> v;
string alpha = "AEIOU";


void DFS(string current_word, int max_length) {

    if (!current_word.empty()) {
        v.push_back(current_word);
    }

    if (current_word.length() < max_length) {
        for (char word : alpha) {
            DFS(current_word + word, max_length);
        }
    }
}


int solution(string word) {
    int answer = 0;
    
    DFS("", 5);
    sort(v.begin(), v.end());
    
    for(int i = 0; i < v.size(); i++){
        if(v[i] == word)
            return i + 1;
    }
    
    
    return answer;
}