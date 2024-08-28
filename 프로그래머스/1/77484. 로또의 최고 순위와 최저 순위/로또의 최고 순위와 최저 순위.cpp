#include <string>
#include <vector>
#include <set>
#include <algorithm>


using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    set<int> my_num;
    int cnt = 0; // 모르는 갯수
    
    for(auto now : lottos){
        if(now == 0)
            cnt++;
        else
            my_num.insert(now);
    }
    
    int win_cnt = 0; // 확실하게 맞춘 숫자
    for(auto a : win_nums){
        if(my_num.find(a) != my_num.end())
            win_cnt++;
    }
    
    int a = win_cnt + cnt;
    int b = win_cnt;
    
    int rank1 = a >= 2 ? 7 - a : 6;
    int rank2 = b >= 2 ? 7 - b : 6;
    answer.push_back(rank1);
    answer.push_back(rank2);
    return answer;
}