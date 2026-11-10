#include <string>
#include <vector>

using namespace std;

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    string answer = "";
    
    // 현재 시간
    int now = 0;
    int m = stoi(pos.substr(0, 2));
    int s = stoi(pos.substr(3, 5));
    now += m*60 + s;
    
    int opS = 0;
    m = stoi(op_start.substr(0, 2));
    s = stoi(op_start.substr(3, 5));
    opS += m*60 + s;
    
    int opE = 0;
    m = stoi(op_end.substr(0, 2));
    s = stoi(op_end.substr(3, 5));
    opE += m*60 + s;
    
    int videoE = 0;
    m = stoi(video_len.substr(0, 2));
    s = stoi(video_len.substr(3, 5));
    videoE += m*60 + s;
    
    for(string cmd : commands){
        
        if(now >= opS && now <= opE) now = opE;
        
        if(cmd == "next"){
            now += 10;
            now = min(now, videoE);
        }
        else if(cmd == "prev"){
            now -= 10;
            now = max(0, now);
        }
        if(now >= opS && now <= opE) now = opE;
    }
    string M = "";
    string S = "";
    if(now/60 < 10) M = "0"; 
    if(now%60 < 10) S = "0";
    M += to_string(now/60);
    S += to_string(now%60);
    
    answer = M + ":" + S;
    return answer;
}