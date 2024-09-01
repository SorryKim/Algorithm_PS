#include <string>
#include <vector>

using namespace std;

string solution(vector<int> food) {
    string answer = "";
    string temp = "";
    
    for(int i = 1; i < food.size(); i++){
        int now = food[i];
        int cnt = now / 2;
        while(cnt--)
            temp += to_string(i);
    }
    
    for(auto a : temp)
        answer += a;
    answer += '0';
    
    for(int i = temp.size() - 1; i >=0; i--)
        answer += temp[i];
    
    
    return answer;
}