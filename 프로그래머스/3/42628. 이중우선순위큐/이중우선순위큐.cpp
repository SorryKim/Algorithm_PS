#include <string>
#include <vector>
#include <algorithm>
#include <deque>
#include <sstream>

using namespace std;


vector<string> splitString(string& input) {
    vector<string> result;
    istringstream iss(input);
    string token;

    while (iss >> token) {
        result.push_back(token);
    }

    return result;
}

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    deque<int> dq;
    
    for(auto a : operations){
        vector<string> cmd = splitString(a);
        
        if(cmd[0] == "I"){
            dq.push_back(stoi(cmd[1]));
            sort(dq.begin(), dq.end());
        }
        else{
            if(cmd[1] == "1"){
                if(!dq.empty())
                    dq.pop_back();
            }else{
                if(!dq.empty())
                    dq.pop_front();
            }
            
            
        }
    }
    
    if(dq.empty()){
        answer.push_back(0);
        answer.push_back(0);
    }
    else{
        answer.push_back(dq.back());
        answer.push_back(dq.front());
    }
    return answer;
}