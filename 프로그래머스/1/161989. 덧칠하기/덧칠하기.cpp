#include <string>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0;
    vector<bool> wall(n + 1, true);
    
    for(auto a : section)
        wall[a] = false;
    
    
    for(auto now : section){
        if(wall[now])
            continue;
        else{
            int start = now;
            int end = (now + m - 1 <= n) ? now + m - 1 : n;
            for(int i = start; i <= end; i++)
                wall[i] = true;
            
            answer++;
        }
    }
    
   
    return answer;
}