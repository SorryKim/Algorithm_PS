#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<int> func(string& input) {
    vector<int> result;
    istringstream iss(input);
    int number;

    while (iss >> number) {
        result.push_back(number);
        iss.ignore();
    }

    return result;
}

string solution(string s) {
    string answer = "";
    
    vector<int> v = func(s);
    
    int maxV = v[0];
    int minV = v[0];
    
    for(auto a : v){
        maxV = max(maxV, a);
        minV = min(minV, a);
    }
    
    answer += to_string(minV) + " " + to_string(maxV);
    return answer;
}