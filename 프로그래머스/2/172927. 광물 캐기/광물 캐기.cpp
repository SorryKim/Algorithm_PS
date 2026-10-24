
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> picks, vector<string> minerals) {
    int answer = 0;
    int cnt = 0;

    // 캘 수 있는 최대 광물 개수
    for (int i = 0; i < 3; i++) cnt += picks[i] * 5;
    
    cnt = min(cnt, (int)minerals.size());
    vector<vector<int>> works;
    
    for(int i = 0; i < min(cnt, (int)minerals.size()); i += 5){
        vector<int> temp(4, 0);
        for(int j = i; j < min(i + 5, cnt); j++){
            string now = minerals[j];
            if(now == "diamond"){
                temp[0] += 25;
                temp[1]++;
            }
            if(now == "iron"){
                temp[0] += 5;
                temp[2]++;
            }
            if(now == "stone"){
                temp[0] += 1;
                temp[3]++;
            }
        }
        works.push_back(temp);
    }
    
    sort(works.begin(), works.end(), greater<vector<int>>());
    for(auto work : works){
        int dia = work[1];
        int iron = work[2];
        int stone = work[3];
        
        if(picks[0] > 0){
            answer += dia + iron + stone;
            picks[0]--;
        }else if(picks[1] > 0){
            answer += 5 * dia + iron + stone;
            picks[1]--;
        }else{
            answer += 25 * dia + 5 * iron + stone;
            picks[0]--;
        }
    }
    
    return answer;
}
